//
// Created by Lenovo on 2026/2/8.
//

#ifndef HELLO_SPRITEANIM_H
#define HELLO_SPRITEANIM_H

#include "sprite.h"
#include <iostream>

class SpriteAnim : public Sprite{
private:
    int m_current_frame = 0;
    int m_total_frames = 0;
    int m_fps = 10;
    float m_frame_timer = 0.0f;

public:
    SpriteAnim() = default;

    static SpriteAnim* addSpriteAnimChild(ObjectScreen* parent, const std::string& file_path, float scale = 1.0f) {
        auto sprite_anim = new SpriteAnim();
        sprite_anim->init();
        sprite_anim->set_texture(Texture{file_path});
        sprite_anim->setScale(scale);
        sprite_anim->set_parent(parent);
        parent->addChild(sprite_anim);
        return sprite_anim;
    }

    // main funcs
    virtual void update(float dt) override ;

    // getter and setter
    [[nodiscard]] int get_m_current_frame() const {
        return m_current_frame;
    }

    void set_m_current_frame(const int current_frame) {
        this->m_current_frame = current_frame;
    }

    [[nodiscard]] int get_m_total_frames() const {
        return m_total_frames;
    }

    void set_m_total_frames(const int total_frames) {
        this->m_total_frames = total_frames;
    }

    [[nodiscard]] int get_fps() const {
        return m_fps;
    }

    void set_fps(const int fps) {
        this->m_fps = fps;
    }

    virtual void set_texture(const Texture& texture) override{
        this->m_texture = texture;
        m_total_frames = texture.src_rect.w / texture.src_rect.h;
        m_texture.src_rect.w = texture.src_rect.h;
        m_size = glm::vec2{m_texture.src_rect.w, m_texture.src_rect.h};
    }
};



#endif //HELLO_SPRITEANIM_H
