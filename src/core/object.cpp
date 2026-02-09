//
// Created by Lenovo on 2026/2/7.
//

#include "object.h"
#include <algorithm>
#include <iostream>

void Object::handle_events(SDL_Event &event) {
    for (auto& child : m_children) {
        if (child -> get_is_active()) {
            child->handle_events(event);
        }
    }
}

void Object::update(float dt) {
    for (auto it = m_children.begin(); it != m_children.end();) {
        auto child = *it;
        if (child -> get_need_remove()) {
            std::cout << "Delete and Remove a child--------------------------" << std::endl;
            it = m_children.erase(it);
            child->clean();
            delete child;
        }
        else {
            if (child -> get_is_active()) {
                child->update(dt);
            }
            ++it;
        }
    }
}

void Object::render() {
    for (auto& child : m_children) {
        if (child -> get_is_active()) {
            child->render();
        }
    }
}

void Object::clean() {
    for (auto& child : m_children) {
        if (child -> get_is_active()) {
            child->clean();
        }
    }
    m_children.clear();
}

void Object::addChild(Object *child) {
    m_children.push_back(child);
}

void Object::removeChild(Object *child) {
    m_children.erase(std::remove(m_children.begin(), m_children.end(), child), m_children.end());
}
