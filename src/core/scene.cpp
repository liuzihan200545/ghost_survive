//
// Created by Lenovo on 2026/2/6.
//

#include "scene.h"
#include <algorithm>

void Scene::handle_events(SDL_Event &event) {
    Object::handle_events(event);
    for (auto& child : m_children_screen) {
        child->handle_events(event);
    }
    for (auto& child : m_children_world) {
        child->handle_events(event);
    }
}

void Scene::update(float dt) {
    Object::update(dt);
    for (auto& child : m_children_world) {
        child->update(dt);
    }
    for (auto& child : m_children_screen) {
        child->update(dt);
    }
}

void Scene::render() {
    Object::render();
    for (auto& child : m_children_world) {
        child->render();
    }
    for (auto& child : m_children_screen) {
        child->render();
    }
}

void Scene::clean() {
    Object::clean();
    for (auto& child : m_children_screen) {
        child->clean();
    }
    for (auto& child : m_children_world) {
        child->clean();
    }
}

void Scene::addChild(Object *child) {
    switch (child->get_type()) {
        case ObjectType::OBJECT_SCREEN:
            m_children_screen.push_back(dynamic_cast<ObjectScreen *>(child));
            break;
        case ObjectType::OBJECT_WORLD:
            m_children_world.push_back(dynamic_cast<ObjectWorld *>(child));
            break;
        default:
            m_children.push_back(dynamic_cast<Object *>(child));
            break;
    }
}

void Scene::removeChild(Object *child) {
    switch (child->get_type()) {
        case ObjectType::OBJECT_SCREEN:
            m_children_screen.erase(std::remove(m_children_screen.begin(), m_children_screen.end(), child), m_children_screen.end());
            break;
        case ObjectType::OBJECT_WORLD:
            m_children_world.erase(std::remove(m_children_world.begin(), m_children_world.end(), child), m_children_world.end());
            break;
        default:
            m_children.erase(std::remove(m_children.begin(), m_children.end(), child), m_children.end());
            break;
    }
}

void Scene::setCameraPosition(const glm::vec2 &camera_position) {

    m_camera_position = camera_position;
    m_camera_position = glm::clamp(m_camera_position, glm::vec2(0.0f, 0.0f) - glm::vec2(20.0f), m_world_size - m_game.getScreenSize() + glm::vec2(20.0f));

}
