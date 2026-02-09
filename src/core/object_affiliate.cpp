//
// Created by Lenovo on 2026/2/8.
//

#include "object_affiliate.h"

void ObjectAffiliate::setOffsetByAnchor(const Anchor &anchor) {
    anchor_ = anchor;
    switch (anchor) {
        case Anchor::TOP_LEFT:
            m_offset = glm::vec2(0, 0);
            break;
        case Anchor::TOP_CENTER:
            m_offset = glm::vec2(-m_size.x / 2, 0);
            break;
        case Anchor::TOP_RIGHT:
            m_offset = glm::vec2(-m_size.x, 0);
            break;
        case Anchor::CENTER_LEFT:
            m_offset = glm::vec2(0, -m_size.y / 2);
            break;
        case Anchor::CENTER:
            m_offset = glm::vec2(-m_size.x / 2, -m_size.y / 2);
            break;
        case Anchor::CENTER_RIGHT:
            m_offset = glm::vec2(-m_size.x, -m_size.y / 2);
            break;
        case Anchor::BOTTOM_LEFT:
            m_offset = glm::vec2(0, -m_size.y);
            break;
        case Anchor::BOTTOM_CENTER:
            m_offset = glm::vec2(-m_size.x / 2, -m_size.y);
            break;
        case Anchor::BOTTOM_RIGHT:
            m_offset = glm::vec2(-m_size.x, -m_size.y);
            break;
        default:
            break;
    }

}
