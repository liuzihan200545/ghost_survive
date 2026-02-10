//
// Created by Lenovo on 2026/2/9.
//

#include "effect.h"

#include "../core/scene.h"

void Effect::update(float dt) {
    ObjectWorld::update(dt);
    check_finish();
}

Effect * Effect::addEffectChild(Object *parent, const std::string &file_path, glm::vec2 pos,float scale,
    ObjectWorld *next_object) {
    Effect* effect = new Effect();
    effect->init();
    effect->sprite_ = SpriteAnim::addSpriteAnimChild(effect, file_path, scale);
    effect->sprite_->set_is_loop(false);
    effect->next_object_ = next_object;
    effect->set_position(pos);
    if (parent) {
        parent->safe_add_child(effect);
    }
    return effect;
}

void Effect::check_finish() {
    if (sprite_ && sprite_->get_is_finished()) {
        need_remove_ = true;
        if (next_object_) {
            m_game.getCurrentScene()->safe_add_child(next_object_);
        }
    }
}
