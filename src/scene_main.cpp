//
// Created by Lenovo on 2026/2/5.
//

#include "scene_main.h"

void SceneMain::init() {
    m_world_size = m_game.getScreenSize() * 3.0f;
    m_camera_position = glm::vec2(-100.f);
}

void SceneMain::handle_events(SDL_Event& event) {

}

void SceneMain::update(float dt) {
    m_camera_position += glm::vec2(100.f,100.0f) * dt;
}

void SceneMain::render() {
    renderBackground();
}

void SceneMain::clean() {

}

void SceneMain::renderBackground() {
    auto start = 0.f - m_camera_position;
    auto end = m_world_size - m_camera_position;
    m_game.drawGrid(start,end,80.f,{0.5,0.5,0.5,1.0});
    m_game.drawBoundary(start,end,10.f,{0.5,0.5,0.5,1.0});
}
