//
// Created by Lenovo on 2026/2/6.
//

#include "scene.h"

void Scene::setCameraPosition(const glm::vec2 &camera_position) {

    m_camera_position = camera_position;
    m_camera_position = glm::clamp(m_camera_position, glm::vec2(0.0f, 0.0f) - glm::vec2(20.0f), m_world_size - m_game.getScreenSize() + glm::vec2(20.0f));

}
