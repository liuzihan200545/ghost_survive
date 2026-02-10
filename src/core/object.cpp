//
// Created by Lenovo on 2026/2/7.
//

#include "object.h"
#include <algorithm>
#include <iostream>

void Object::handle_events(SDL_Event &event) {
    for (auto& child : children_) {
        if (child -> get_is_active()) {
            child->handle_events(event);
        }
    }
}

void Object::update(float dt) {
    for (auto& child : object_to_add_) {
        addChild(child);
    }
    object_to_add_.clear();

    for (auto it = children_.begin(); it != children_.end();) {
        auto child = *it;
        if (child -> get_need_remove()) {
            std::cout << "Delete and Remove a child--------------------------" << std::endl;
            it = children_.erase(it);
            child->clean();
            delete child;
            child = nullptr;
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
    for (auto& child : children_) {
        if (child -> get_is_active()) {
            child->render();
        }
    }
}

void Object::clean() {
    for (auto& child : children_) {
        if (child -> get_is_active()) {
            child->clean();
        }
    }
    children_.clear();
}

void Object::addChild(Object *child) {
    children_.push_back(child);
}

void Object::removeChild(Object *child) {
    children_.erase(std::remove(children_.begin(), children_.end(), child), children_.end());
}
