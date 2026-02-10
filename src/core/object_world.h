//
// Created by Lenovo on 2026/2/6.
//

#ifndef HELLO_OBJECTWORLD_H
#define HELLO_OBJECTWORLD_H

#include "object_screen.h"
#include "../affiliate/collider.h"

class ObjectWorld: public ObjectScreen{
protected:
    glm::vec2 m_position = glm::vec2(0);
    Collider* collider_ = nullptr;

public:
    [[nodiscard]] Collider * get_collider() const {
        return collider_;
    }

    void set_collider(Collider *collider) {
        collider_ = collider;
    }

    virtual void init() override {
        m_type = ObjectType::OBJECT_WORLD;
    }

    virtual void update(float dt) override;

    virtual void set_render_position(const glm::vec2& position) override;

    [[nodiscard]] virtual glm::vec2 get_position() const override;

    void set_position(const glm::vec2& position);

    virtual void take_damage(float damage) {}


};


#endif //HELLO_OBJECTWORLD_H