//
// Created by Lenovo on 2026/2/5.
//

#include "scene_main.h"
#include "player.h"
#include "Enemy.h"

void SceneMain::init() {
    m_world_size = m_game.getScreenSize() * 3.0f;
    m_camera_position = glm::vec2(m_world_size/2.0f - m_game.getScreenSize().x/2.0f);

    m_player = new Player();
    m_player->init();
    addChild(m_player);
    m_player->setPosition(m_world_size/2.0f);

    auto enemy = new Enemy();
    enemy->init();
    addChild(enemy);
    enemy->setPosition(m_world_size/2.0f + 200.f);
    enemy->set_target(m_player);
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
