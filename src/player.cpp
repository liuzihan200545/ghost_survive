//
// Created by Lenovo on 2026/2/6.
//

#include "player.h"
#include "affiliate/spriteAnim.h"
#include "core/scene.h"

void Player::init() {
    Actor::init();
    this->set_max_speed(500.0f);
    SpriteAnim::addSpriteAnimChild(this,"assets/sprite/ghost-idle.png",4.0f);
}

void Player::handle_events(SDL_Event &event) {
    Actor::handle_events(event);
}

void Player::update(float dt) {
    Actor::update(dt);
    KeyBoardControl();
    m_velocity *= 0.9f;
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

void Player::move(float dt) {
    setPosition(m_position + m_velocity * dt);

    m_position = glm::clamp(m_position, glm::vec2(0.0f), m_game.getCurrentScene()->getWorldSize());

}

void Player::syncCamera() {
    m_game.getCurrentScene()->setCameraPosition(m_position - m_game.getScreenSize()/2.0f);
}

