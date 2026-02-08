//
// Created by Lenovo on 2026/2/8.
//

#include "sprite.h"

Texture::Texture(const std::string &file_path) {
    texture = Game::get_instance().getAssetStore()->getImage(file_path);
    SDL_GetTextureSize(texture,&src_rect.w,&src_rect.h);
}

void Sprite::render() {
    ObjectAffiliate::render();
    if (m_texture.texture == nullptr) {
        return;
    }
    if (m_parent == nullptr) {
        return;
    }
    auto pos = m_parent->getRenderPosition() + this->m_offset;
    m_game.renderTexture(m_texture,pos,m_size);
}
