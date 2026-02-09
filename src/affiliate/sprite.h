//
// Created by Lenovo on 2026/2/8.
//

#ifndef HELLO_SPRITE_H
#define HELLO_SPRITE_H

#include "../core/object_affiliate.h"

struct Texture {
    SDL_Texture* texture = nullptr;
    SDL_FRect src_rect;
    float angle = 0.0f;
    bool is_flip = false;
    Texture(const std::string& file_path);
    Texture() = default;
};

class Sprite : public ObjectAffiliate {
protected:
    Texture m_texture;
    bool is_finished_ = false;

public:
    [[nodiscard]] bool get_is_finished() const {
        return is_finished_;
    }

    void set_is_finished(bool is_finished) {
        is_finished_ = is_finished;
    }

    Sprite() = default;

    // main funcs

    static Sprite* addSpriteChild(ObjectScreen* parent, const std::string& file_path, float scale = 1.0f);

    virtual void render() override;

    // getter and setter

    [[nodiscard]] Texture get_texture() const {
        return m_texture;
    }

    virtual void set_texture(const Texture &texture) {
        this->m_texture = texture;
        this->m_size = glm::vec2{texture.src_rect.w,texture.src_rect.h};
    }

    void setScale(float scale) {
        m_size *= scale;
    }

    void setAngle(float angle) {
        m_texture.angle = angle;
    }

    [[nodiscard]]float getAngle() const {
        return m_texture.angle;
    }

    void setFlip(bool flip) {
        m_texture.is_flip = flip;
    }

    [[nodiscard]]bool getFlip() const {
        return m_texture.is_flip;
    }

};


#endif //HELLO_SPRITE_H