//
// Created by Lenovo on 2026/2/10.
//

#ifndef HELLO_SPELL_H
#define HELLO_SPELL_H

#include "../core/object_world.h"
#include "../affiliate/spriteAnim.h"

class Spell : public ObjectWorld {
protected:
    SpriteAnim* sprite_ = nullptr;
    float damage_ = 60.0f;
public:

    // main functions
    void update(float dt) override;

    static Spell* addSpellChild(Object* parent, const std::string& file_path, glm::vec2 pos, float damage, float scale = 1.0f, Anchor anchor = Anchor::CENTER) {
        Spell* spell = new Spell();
        spell->init();
        spell->sprite_ = SpriteAnim::addSpriteAnimChild(spell, file_path, scale, anchor);
        spell->sprite_->set_is_loop(false);
        auto size = spell->sprite_->get_size();
        spell->collider_ = Collider::addColliderChild(spell, size, Collider::Type::CIRCLE , anchor);
        spell->set_render_position(pos);
        spell->set_damage(damage);
        if (parent) parent->addChild(spell);
        return spell;
    }

    // setter and getter
    void setSprite(SpriteAnim* sprite) { sprite_ = sprite; }
    SpriteAnim* getSprite() const { return sprite_; }

    void set_damage(float damage) { damage_ = damage; }
    float get_damage() const { return damage_; }

private:
    void attack();
};


#endif //HELLO_SPELL_H