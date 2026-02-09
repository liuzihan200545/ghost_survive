//
// Created by Lenovo on 2026/2/6.
//

#include "player.h"
#include "affiliate/spriteAnim.h"
#include "core/scene.h"
#include <iostream>

void Player::init() {
    Actor::init();
    this->set_max_speed(500.0f);
    m_sprite_idle = SpriteAnim::addSpriteAnimChild(this,"assets/sprite/ghost-idle.png",2.0f);
    m_sprite_move = SpriteAnim::addSpriteAnimChild(this,"assets/sprite/ghost-move.png",2.0f);
    m_sprite_move->set_is_active(false);

    collider_ = Collider::addColliderChild(this, m_sprite_idle->get_size() / 1.6f);
}

void Player::handle_events(SDL_Event &event) {
    Actor::handle_events(event);
}

void Player::update(float dt) {
    Actor::update(dt);
    KeyBoardControl();
    m_velocity *= 0.9f;
    checkState();
    move(dt);
    syncCamera();
}

void Player::render() {
    Actor::render();
}

void Player::clean() {
    Actor::clean();
}

void Player::KeyBoardControl() {
    auto currentKeyStates = SDL_GetKeyboardState(NULL);
    if (currentKeyStates[SDL_SCANCODE_W]) {
        m_velocity.y = - m_max_speed;
    }
    if (currentKeyStates[SDL_SCANCODE_S]) {
        m_velocity.y = m_max_speed;
    }
    if (currentKeyStates[SDL_SCANCODE_A]) {
        m_velocity.x = -m_max_speed;
    }
    if (currentKeyStates[SDL_SCANCODE_D]) {
        m_velocity.x = m_max_speed;
    }
}

void Player::syncCamera() {
    m_game.getCurrentScene()->setCameraPosition(m_position - m_game.getScreenSize()/2.0f);
}

void Player::checkState() {

    if (m_velocity.x < 0.0f) {
        m_sprite_idle->setFlip(true);
        m_sprite_move->setFlip(true);
    }
    else {
        m_sprite_idle->setFlip(false);
        m_sprite_move->setFlip(false);
    }
    bool new_is_moving = (glm::length(m_velocity) >= 50.0f);

    if (new_is_moving != is_moving) {
        is_moving = new_is_moving;
        changeState(new_is_moving);
    }
}

void Player::changeState(bool is_moving) {
    if (is_moving) {
        m_sprite_idle->set_is_active(false);
        m_sprite_move->set_is_active(true);
        m_sprite_move->set_m_current_frame(m_sprite_idle->get_m_current_frame());
        m_sprite_move->set_m_frame_timer(m_sprite_idle->get_frame_timer());
    }
    else {
        m_sprite_idle->set_is_active(true);
        m_sprite_move->set_is_active(false);
        m_sprite_idle->set_m_current_frame(m_sprite_move->get_m_current_frame());
        m_sprite_idle->set_m_frame_timer(m_sprite_move->get_frame_timer());
    }
}


