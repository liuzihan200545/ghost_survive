//
// Created by Lenovo on 2026/2/10.
//

#ifndef HELLO_WEAPON_H
#define HELLO_WEAPON_H

#include "../core/object.h"

class Spell; class Actor;

class Weapon : public Object {
protected:
    Actor* parent_ = nullptr;
    float cool_down_ = 1.0f;
    float mana_cost_ = 0.0f;
    float cool_down_timer_ = 0.0f;

public:
    // main functions
    virtual void update(float dt) override;

    void attack(glm::vec2 pos,Spell* spell); // 确认创建这个函数的时候一定执行attack逻辑

    bool can_attack();

    // getters and setters

    float get_cool_down() const { return cool_down_; }
    void set_cool_down(float cool_down) { cool_down_ = cool_down; }

    float get_mana_cost() const { return mana_cost_; }
    void set_mana_cost(float mana_cost) { mana_cost_ = mana_cost; }

    Actor* get_parent() const { return parent_; }
    void set_parent(Actor* parent) { parent_ = parent; }

};


#endif //HELLO_WEAPON_H