//
// Created by Lenovo on 2026/2/5.
//

#include "scene_main.h"
#include "player.h"
#include "screen/ui_mouse.h"
#include "spawner.h"

void SceneMain::init() {
    //SDL_HideCursor();
    m_world_size = m_game.get_screen_size() * 3.0f;
    m_camera_position = glm::vec2(m_world_size/2.0f - m_game.get_screen_size().x/2.0f);

    player_ = new Player();
    player_->init();
    addChild(player_);
    player_->set_position(m_world_size/2.0f);

    spawner_ = new Spawner();
    spawner_->init();
    spawner_->set_target(player_);
    addChild(spawner_);

    ui_mouse_ = UIMouse::addUIMouseChild(this,"assets/UI/29.png","assets/UI/30.png",1.0f,Anchor::CENTER);

    /*auto enemy = new Enemy();
    enemy->init();
    enemy->set_position(m_world_size/2.0f + 200.f);
    enemy->set_target(m_player);

    Effect::addEffectChild(this,"assets/effect/184_3.png",m_world_size/2.0f + glm::vec2(200.f),1.5f, enemy);*/
}

void SceneMain::handle_events(SDL_Event& event) {
    Scene::handle_events(event);
}

void SceneMain::update(float dt) {
    Scene::update(dt);
}

void SceneMain::render() {
    renderBackground();
    Scene::render();
}

void SceneMain::clean() {
    Scene::clean();
}

void SceneMain::renderBackground() {
    auto start = 0.f - m_camera_position;
    auto end = m_world_size - m_camera_position;
    m_game.drawGrid(start,end,80.f,{0.5,0.5,0.5,1.0});
    m_game.drawBoundary(start,end,10.f,{0.5,0.5,0.5,1.0});
}
