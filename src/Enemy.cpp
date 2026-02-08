//
// Created by Lenovo on 2026/2/8.
//

#include "Enemy.h"
#include "affiliate/spriteAnim.h"

void Enemy::aim_target(Player *target) {
    if (target == nullptr) {
        return;
    }
    auto direction = target->getPosition() - this->getPosition();
    direction = glm::normalize(direction);
    m_velocity = direction * m_max_speed;
}

void Enemy::init() {
    Actor::init();
    SpriteAnim::addSpriteAnimChild(this,"assets/sprite/ghost-Sheet.png",2.0f);
}

void Enemy::update(float dt) {
    Actor::update(dt);
    aim_target(m_player);
    move(dt);
}
