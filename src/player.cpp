//
// Created by Lenovo on 2026/2/6.
//

#include "player.h"
#include "core/scene.h"

void Player::init() {
    m_max_speed = 250.0f;
}

void Player::handle_events(SDL_Event &event) {

}

void Player::update(float dt) {
    KeyBoardControl();
    m_velocity *= 0.9f;
    move(dt);
    syncCamera();
}

void Player::render() {
    m_game.drawBoundary(m_render_position,m_render_position+glm::vec2(20.0f),5.0f,{1,0,0,0});
}

void Player::clean() {

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

void Player::move(float dt) {
    setPosition(m_position + m_velocity * dt);

    m_position = glm::clamp(m_position, glm::vec2(0.0f), m_game.getCurrentScene()->getWorldSize());

}

void Player::syncCamera() {
    m_game.getCurrentScene()->setCameraPosition(m_position - m_game.getScreenSize()/2.0f);
}

