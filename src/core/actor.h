//
// Created by Lenovo on 2026/2/6.
//

#ifndef HELLO_ACTOR_H
#define HELLO_ACTOR_H

#include "object_world.h"


class Actor : public ObjectWorld{
protected:
    glm::vec2 m_velocity = glm::vec2(0.0f);
    float m_max_speed = 100.0f;
public:
    // getter and setter
    glm::vec2 GetVelocity() const { return m_velocity; }
    float GetMaxSpeed() const { return m_max_speed; }
    void SetVelocity(const glm::vec2& v) { m_velocity = v; }
    void SetMaxSpeed(float v) { m_max_speed = v; }
    void set_max_speed(float v) { m_max_speed = v; }
};


#endif //HELLO_ACTOR_H