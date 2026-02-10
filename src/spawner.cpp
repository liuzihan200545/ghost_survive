//
// Created by Lenovo on 2026/2/10.
//

#include "spawner.h"
#include "Enemy.h"
#include "core/scene.h"

void Spawner::update(float dt) {
    Object::update(dt);

    if (!target_ || target_->is_alive()) {
        timer_ += dt;
        if (timer_ >= interval_) {
            timer_ = 0.0f;
            for (int i = 0; i < num_; i++) {
                // spawn the enemy
                auto pos = m_game.random_vec2(m_game.get_current_scene()->getCameraPosition(),m_game.get_current_scene()->getCameraPosition()+m_game.get_screen_size());
                auto enemy = Enemy::addEnemyChild(nullptr, pos, target_);
                Effect::addEffectChild(m_game.get_current_scene(),"assets/effect/184_3.png",pos,1.0f,enemy);
            }
        }
    }
}
