//
// Created by Lenovo on 2026/2/9.
//

#include "states.h"

void States::update(float dt) {
    Object::update(dt);
    regen_mana(dt);
    if (is_invisible()) {
        invisible_timer += dt;
        if (invisible_timer >= invisible_time_) {
            set_invisible(false);
            invisible_timer = 0.0f;
        }
    }
}

States * States::addStatesChild(Actor *parent, float health, float max_health, float mana, float max_mana, float damage,
    float mana_regen) {
    States* state = new States();
    state->set_parent(parent);
    state->set_health(health);
    state->set_max_health(max_health);
    state->set_mana(mana);
    state->set_max_mana(max_mana);
    state->set_damage(damage);
    state->set_mana_regen(mana_regen);
    parent->set_states(state);
    parent->addChild(state);
    return state;
}

bool States::can_use_mana(float mana_cost) {
    return mana_ >= mana_cost;
}

void States::regen_mana(float dt) {
    mana_ = std::min(mana_ + mana_regen_ * dt, max_mana_);
}

void States::use_mana(float mana_cost) {
    if (can_use_mana(mana_cost)) {
        mana_ -= mana_cost;
    }
}

void States::take_damage(float damage) {
    if (!is_invisible()) {
        health_ -= damage;
        if (health_ <= 0) {
            health_ = 0;
            is_alive_ = false;
        }
        std::cout << "Took damage: " << damage << ", current health: " << health_ << std::endl;
        set_invisible(true);
        set_invisible_timer(0.0f);
    }
}
