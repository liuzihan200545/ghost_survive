//
// Created by Lenovo on 2026/2/9.
//

#ifndef HELLO_EFFECT_H
#define HELLO_EFFECT_H

#include "../core/object_world.h"
#include "../affiliate/spriteAnim.h"

class Effect : public ObjectWorld {
    SpriteAnim* sprite_ = nullptr;
    ObjectWorld* next_object_ = nullptr; // 播放完毕后添加到场景

public:
    // main functions
    void update(float dt) override;

    // static Create and add Child
    static Effect * addEffectChild(Object* parent,const std::string& file_path, glm::vec2 pos,float scale = 1.0f, ObjectWorld* next_object = nullptr);

    // getter and setter for sprite_
    [[nodiscard]] SpriteAnim *get_sprite() const {
        return sprite_;
    }

    void set_sprite(SpriteAnim *sprite) {
        Effect::sprite_ = sprite;
    }
    // getter and setter for next_object_
    [[nodiscard]] ObjectWorld *get_next_object() const {
        return next_object_;
    }

    void set_next_object(ObjectWorld *next_object) {
        Effect::next_object_ = next_object;
    }
private:
    void check_finish();

};

#endif //HELLO_EFFECT_H
