//
// Created by Lenovo on 2026/2/8.
//

#include "Enemy.h"
#include "affiliate/spriteAnim.h"
#include "core/scene.h"
#include "raw/states.h"

Enemy * Enemy::addEnemyChild(Object *parent, const glm::vec2 &pos, Player* target) {
    Enemy* enemy = new Enemy();
    enemy->init();
    enemy->set_position(pos);
    enemy->set_target(target);
    if (parent) parent->addChild(enemy);
    return enemy;
}

void Enemy::aim_target(Player *target) {
    if (target == nullptr) {
        return;
    }
    auto direction = target->get_position() - this->get_position();
    direction = glm::normalize(direction);
    m_velocity = direction * m_max_speed;
}

void Enemy::checkState() {

}

void Enemy::changeState(State new_state) {
    if (new_state == current_state_) {
        return;
    }

    anim_current_ -> set_is_active(false);

    switch (new_state) {
        case State::NORMAL:
            anim_current_ = anim_normal_;
            anim_normal_->set_is_active(true);
            break;
        case State::HURT:
            anim_current_ = anim_hurt_;
            anim_hurt_->set_is_active(true);
            break;
        case State::DIE:
            anim_current_ = anim_die_;
            anim_die_->set_is_active(true);
            break;
    }
    current_state_ = new_state;
}

void Enemy::init() {
    Actor::init();
    anim_normal_ = SpriteAnim::addSpriteAnimChild(this,"assets/sprite/ghost-Sheet.png",3.0f);
    anim_hurt_ = SpriteAnim::addSpriteAnimChild(this,"assets/sprite/ghostHurt-Sheet.png",3.0f);
    anim_die_ = SpriteAnim::addSpriteAnimChild(this,"assets/sprite/ghostDead-Sheet.png",3.0f);
    anim_hurt_->set_is_active(false);
    anim_die_->set_is_active(false);

    anim_hurt_->set_is_loop(false);
    anim_die_->set_is_loop(false);

    anim_current_ = anim_normal_;

    collider_ = Collider::addColliderChild(this, anim_current_->get_size());

    states_ = States::addStatesChild(this);

    set_type(ObjectType::ENEMY);
}

void Enemy::update(float dt) {
    Actor::update(dt);
    if (target_->is_alive()) {
        aim_target(target_);
        move(dt);
        attack();
    }
}

void Enemy::remove() {
    if (anim_die_->get_is_finished()) {
        need_remove_ = true;
    }
}

void Enemy::attack() {
    if ( !collider_ || !target_ || !target_->get_collider() ) return;

    if (collider_->is_colliding(target_->get_collider())) {
        if (states_ && target_->get_states()) {
            target_->take_damage(states_->get_damage());
        }
    }
}
