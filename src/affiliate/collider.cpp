//
// Created by Lenovo on 2026/2/9.
//

#include "collider.h"

bool Collider::is_Colliding(Collider *other) {
    if (type_ == Type::CIRCLE && other->type_ == Type::CIRCLE) {
        auto point1 = m_parent->getPosition() + m_size / 2.0f + m_offset;
        auto point2 = other->m_parent->getPosition() + other->m_size / 2.0f + other->m_offset;

        if (glm::length(point2 - point1) < (m_size.x + other->m_size.x) / 2.0f) {
            return true;
        }
    }

    //TODO: 其他形状的检测
    return false;
}

Collider * Collider::addColliderChild(ObjectScreen *parent, glm::vec2 size, Type type, Anchor anchor) {
    auto collider = new Collider();
    collider->init();
    collider->set_parent(parent);
    collider->set_size(size);
    collider->type_ = type;
    collider->setOffsetByAnchor(anchor);
    parent->addChild(collider);
    return collider;
}

void Collider::render() {
#ifdef MY_DEBUG
    ObjectAffiliate::render();
    auto pos = m_parent->getRenderPosition() + m_offset;
    m_game.renderCircle(pos,m_size,0.3);
#endif
}
