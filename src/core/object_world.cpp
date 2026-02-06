//
// Created by Lenovo on 2026/2/6.
//

#include "object_world.h"

#include "scene.h"

void ObjectWorld::update(float dt) {
    ObjectScreen::update(dt);
    m_render_position = m_game.getCurrentScene()->worldToScreen(m_position);
}

void ObjectWorld::setPosition(const glm::vec2 &position) {
    m_position = position;
    m_render_position = m_game.getCurrentScene()->worldToScreen(position);
}

void ObjectWorld::setRenderPosition(const glm::vec2 &position) {
    m_render_position = position;
    m_position = m_game.getCurrentScene()->ScreenToWorld(position);
}
