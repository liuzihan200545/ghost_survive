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

public:
    Sprite() = default;

    virtual void render() override;

    [[nodiscard]] Texture get_texture() const {
        return m_texture;
    }

    void set_texture(const Texture &texture) {
        this->m_texture = texture;
        this->m_size = glm::vec2{texture.src_rect.w,texture.src_rect.h};
    }
};


#endif //HELLO_SPRITE_H