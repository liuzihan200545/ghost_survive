//
// Created by Lenovo on 2026/2/6.
//

#include "actor.h"
#include "../raw/states.h"
#include "../affiliate/affiliate_bar.h"

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

void Actor::update_health_bar() {
    if (!health_bar_ || !states_) {
        return;
    }
    health_bar_->set_percentage(states_->get_health() / states_->get_max_health());
}

void Actor::update(float dt) {
    ObjectWorld::update(dt);
    update_health_bar();
}
