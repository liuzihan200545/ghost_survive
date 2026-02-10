//
// Created by Lenovo on 2026/2/6.
//

#include "object_world.h"

#include "scene.h"

void ObjectWorld::update(float dt) {
    ObjectScreen::update(dt);
    m_render_position = m_game.get_current_scene()->worldToScreen(m_position);
}

void ObjectWorld::set_position(const glm::vec2 &position) {
    m_position = position;
    m_render_position = m_game.get_current_scene()->worldToScreen(position);
}

void ObjectWorld::set_render_position(const glm::vec2 &position) {
    m_render_position = position;
    m_position = m_game.get_current_scene()->ScreenToWorld(position);
}

glm::vec2 ObjectWorld::get_position() const {
    return m_position;
}
