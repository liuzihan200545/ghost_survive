//
// Created by Lenovo on 2026/2/8.
//

#include "sprite.h"

Texture::Texture(const std::string &file_path) {
    texture = Game::get_instance().get_asset_store()->getImage(file_path);
    SDL_GetTextureSize(texture,&src_rect.w,&src_rect.h);
}

Sprite * Sprite::addSpriteChild(ObjectScreen *parent, const std::string &file_path, float scale, Anchor anchor) {
    auto sprite = new Sprite();
    sprite->init();
    sprite->set_texture(Texture{file_path});
    sprite->setScale(scale);
    sprite->set_parent(parent);
    sprite->setOffsetByAnchor(anchor);
    parent->addChild(sprite);
    return sprite;
}

void Sprite::render() {
    ObjectAffiliate::render();
    if (is_finished_ || !m_texture.texture || !parent_) {
        return;
    }
    auto pos = parent_->get_render_position() + this->m_offset;
    m_game.renderTexture(m_texture,pos,m_size,percentage_);
}
