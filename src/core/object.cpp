//
// Created by Lenovo on 2026/2/7.
//

#include "object.h"
#include <algorithm>

void Object::handle_events(SDL_Event &event) {
    for (auto& child : m_children) {
        child->handle_events(event);
    }
}

void Object::update(float dt) {
    for (auto& child : m_children) {
        child->update(dt);
    }
}

void Object::render() {
    for (auto& child : m_children) {
        child->render();
    }
}

void Object::clean() {
    for (auto& child : m_children) {
        child->clean();
    }
    m_children.clear();
}

void Object::addChild(Object *child) {
    m_children.push_back(child);
}

void Object::removeChild(Object *child) {
    m_children.erase(std::remove(m_children.begin(), m_children.end(), child), m_children.end());
}
