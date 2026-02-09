//
// Created by Lenovo on 2026/2/6.
//

#include "actor.h"
#include "../raw/states.h"

void Actor::take_damage(float damage) {
    if (!states_) {
        return;
    }
    states_->take_damage(damage);
}

bool Actor::is_alive() const {
    if (!states_) {
        return true;
    }
    return states_->is_alive();
}
