//
// Created by Lenovo on 2026/2/6.
//

#ifndef HELLO_ACTOR_H
#define HELLO_ACTOR_H

#include "object_world.h"

class States; class AffiliateBar;

class Actor : public ObjectWorld{
protected:
    glm::vec2 m_velocity = glm::vec2(0.0f);
    float m_max_speed = 100.0f;
    States *states_ = nullptr;
    AffiliateBar *health_bar_ = nullptr;
public:
    // getter and setter
    [[nodiscard]] glm::vec2 get_velocity() const { return m_velocity; }
    [[nodiscard]] float get_max_speed() const { return m_max_speed; }
    void set_velocity(const glm::vec2& v) { m_velocity = v; }
    void set_max_speed(float v) { m_max_speed = v; }
    [[nodiscard]] States *get_states() const {
        return states_;
    }
    void set_states(States *states) {
        states_ = states;
    }

    // main functions
    void move(float dt) {
        this->set_position(m_position += m_velocity * dt);
    }

    // game play
    void take_damage(float damage) override;
    bool is_alive() const;

    void update(float dt) override;

private:
    void update_health_bar();

};


#endif //HELLO_ACTOR_H