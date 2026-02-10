//
// Created by Lenovo on 2026/2/10.
//

#include "weapon.h"
#include "../world/spell.h"
#include "states.h"
#include "../core/actor.h"
#include "../core/scene.h"

void Weapon::update(float dt) {
    Object::update(dt);
    cool_down_timer_ += dt;
}

void Weapon::attack(glm::vec2 pos, Spell* spell) {
    if (spell == nullptr) { return; }
    parent_->get_states()->use_mana(mana_cost_);
    cool_down_timer_ = 0.0f;
    spell->set_render_position(pos);
    m_game.get_current_scene()->safe_add_child(spell);
}

bool Weapon::can_attack() {
    if (cool_down_timer_ < cool_down_) { return false; }
    if (!parent_->get_states()->can_use_mana(mana_cost_)) { return false; }
    return true;
}
