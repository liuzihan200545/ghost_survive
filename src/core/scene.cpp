//
// Created by Lenovo on 2026/2/6.
//

#include "scene.h"
#include <algorithm>

void Scene::handle_events(SDL_Event &event) {
    Object::handle_events(event);
    for (auto& child : m_children_screen) {
        if (child->get_is_active()) {
            child->handle_events(event);
        }
    }
    for (auto& child : m_children_world) {
        if (child->get_is_active()) {
            child->handle_events(event);
        }
    }
}

void Scene::update(float dt) {
    Object::update(dt);
    for (auto it = m_children_world.begin(); it != m_children_world.end();) {
        auto child = *it;
        if (child->get_need_remove()) {
            SDL_Log("Delete and Remove a child--------------------------");
            it = m_children_world.erase(it);
            child->clean();
            delete child;
            child = nullptr;
        }
        else {
            if (child->get_is_active()) {
                child->update(dt);
            }
            ++it;
        }
    }
    for (auto it = m_children_screen.begin(); it != m_children_screen.end();) {
        auto child = *it;
        if (child->get_need_remove()) {
            SDL_Log("Delete and Remove a child--------------------------");
            it = m_children_screen.erase(it);
            child->clean();
            delete child;
            child = nullptr;
        }
        else {
            if (child->get_is_active()) {
                child->update(dt);
            }
            ++it;
        }
    }
}

void Scene::render() {
    Object::render();
    for (auto& child : m_children_world) {
        if (child->get_is_active()) {
            child->render();
        }
    }
    for (auto& child : m_children_screen) {
        if (child->get_is_active()) {
            child->render();
        }
    }
}

void Scene::clean() {
    Object::clean();
    for (auto& child : m_children_screen) {
        if (child->get_is_active()) {
            child->clean();
        }
    }
    for (auto& child : m_children_world) {
        if (child->get_is_active()) {
            child->clean();
        }
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
            children_.push_back(dynamic_cast<Object *>(child));
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
            children_.erase(std::remove(children_.begin(), children_.end(), child), children_.end());
            break;
    }
}

void Scene::setCameraPosition(const glm::vec2 &camera_position) {

    m_camera_position = camera_position;
    m_camera_position = glm::clamp(m_camera_position, glm::vec2(0.0f, 0.0f) - glm::vec2(20.0f), m_world_size - m_game.getScreenSize() + glm::vec2(20.0f));

}
