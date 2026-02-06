//
// Created by Lenovo on 2026/2/5.
//

#include "scene_main.h"

#include "player.h"

void SceneMain::init() {
    m_world_size = m_game.getScreenSize() * 3.0f;
    m_camera_position = glm::vec2(m_world_size/2.0f - m_game.getScreenSize().x/2.0f);

    m_player = new Player();
    m_player->init();
    m_player->setPosition(m_world_size/2.0f);
}

void SceneMain::handle_events(SDL_Event& event) {

}

void SceneMain::update(float dt) {
    m_player->update(dt);
}

void SceneMain::render() {
    renderBackground();
    m_player->render();
}

void SceneMain::clean() {
    m_player->clean();
    delete m_player;
}

void SceneMain::renderBackground() {
    auto start = 0.f - m_camera_position;
    auto end = m_world_size - m_camera_position;
    m_game.drawGrid(start,end,80.f,{0.5,0.5,0.5,1.0});
    m_game.drawBoundary(start,end,10.f,{0.5,0.5,0.5,1.0});
}
