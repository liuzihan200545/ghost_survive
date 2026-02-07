//
// Created by Lenovo on 2026/2/7.
//

#include "background_main.h"

void BackgroundMain::render() {
    Object::render();
    auto start = 0.f - m_camera_position;
    auto end = m_world_size - m_camera_position;

    m_game.drawGrid(start, end, 80.f, {0.5, 0.5, 0.5, 1.0});
    m_game.drawBoundary(start, end, 10.f, {0.5, 0.5, 0.5, 1.0});
}
