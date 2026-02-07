//
// Created by Lenovo on 2026/2/5.
//

#include "scene_main.h"

#include "background_main.h"
#include "player.h"

void SceneMain::init() {
    m_world_size = m_game.getScreenSize() * 3.0f;
    m_camera_position = glm::vec2(m_world_size/2.0f - m_game.getScreenSize().x/2.0f);

    // 1. 创建并挂载背景
    // 注意：我们将 m_camera_position 传递给 Background，它会保存引用
    BackgroundMain* bg = new BackgroundMain(m_world_size, m_camera_position);
    bg->init(); // 如果Background有init逻辑
    addChild(bg); // 关键：先添加背景，这样它会先被渲染

    // 2. 创建并挂载角色
    m_player = new Player();
    m_player->init();
    addChild(m_player);
    m_player->setPosition(m_world_size/2.0f);
}

void SceneMain::handle_events(SDL_Event& event) {
    Scene::handle_events(event);
}

void SceneMain::update(float dt) {
    Scene::update(dt);
}

void SceneMain::render() {
    Scene::render();
}

void SceneMain::clean() {
    Scene::clean();
}

