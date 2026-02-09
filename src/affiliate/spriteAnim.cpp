//
// Created by Lenovo on 2026/2/8.
//

#include "spriteAnim.h"

void SpriteAnim::update(float dt) {
    Sprite::update(dt);
    if (is_finished_) {
        return;
    }
    m_frame_timer += dt;
    if (m_frame_timer >= 1.0f / m_fps) {
        m_current_frame ++;
        if (m_current_frame >= m_total_frames) {
            m_current_frame = 0;
            if (!is_loop_) {
                is_finished_ = true;
            }
        }
        m_frame_timer = 0.0f;
    }

    m_texture.src_rect.x = m_texture.src_rect.w * m_current_frame;
}

