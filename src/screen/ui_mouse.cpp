//
// Created by Lenovo on 2026/2/10.
//

#include "ui_mouse.h"

void UIMouse::update(float dt) {
    ObjectScreen::update(dt);

    timer_ += dt;
    if (timer_ < 0.3f) {
        sprite1_->set_is_active(true);
        sprite2_->set_is_active(false);
    }
    else if (timer_ < 0.6f) {
        sprite1_->set_is_active(false);
        sprite2_->set_is_active(true);
    }
    else {
        timer_ = 0.0f;
    }

    this->set_render_position(m_game.get_mouse_position());
}

UIMouse * UIMouse::addUIMouseChild(Object *parent, const std::string &file_path_1, const std::string &file_path_2,float scale, Anchor anchor) {
    auto ui_mouse = new UIMouse();
    ui_mouse->init();
    ui_mouse->sprite1_ = Sprite::addSpriteChild(ui_mouse, file_path_1, scale, anchor);
    ui_mouse->sprite2_ = Sprite::addSpriteChild(ui_mouse, file_path_2, scale, anchor);
    if (parent) {
        parent->addChild(ui_mouse);
    }
    return ui_mouse;
}
