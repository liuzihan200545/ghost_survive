//
// Created by Lenovo on 2026/2/10.
//

#include "spell.h"

#include "../core/scene.h"

void Spell::update(float dt) {
    ObjectWorld::update(dt);
    if (sprite_->get_is_finished()) { need_remove_ = true; }
    attack();
}

void Spell::attack() {
    auto objects = m_game.get_current_scene()->get_children_world();
    std::cout << objects.size() << std::endl;
    for (auto& obj : objects) {
        if (obj->get_type() != ObjectType::ENEMY) {
            continue;
        }
        if (!obj->get_collider()) {
            std::cout << "collider_ is null!" << std::endl;
        }
        if (collider_ && obj->get_collider() && collider_->is_colliding(obj->get_collider())) {
            std::cout << "Spell hit enemy!" << std::endl;
            obj->take_damage(damage_);
        }
    }
}
