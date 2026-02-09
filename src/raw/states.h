//
// Created by Lenovo on 2026/2/9.
//

#ifndef HELLO_STATES_H
#define HELLO_STATES_H

#include "../core/object.h"
#include "../core/actor.h"


class States : public Object {
protected:
    // The variables of the states
    float health_ = 100.0f;
    float max_health_ = 100.0f;
    float mana_ = 100.0f;
    float max_mana_ = 100.0f;
    float damage_ = 40.0f;
    float mana_regen_ = 10.0f;
    float invisible_time_ = 5.0f; // seconds
    float invisible_timer = 0.0f; // seconds
    bool is_alive_ = true;
    bool is_invisible_ = false;

    // parent
    Actor *parent_ = nullptr;

public:

    // engine functions
    virtual void update(float dt) override;
    // static function to create the state and add to child, input all the states
    static States* addStatesChild(Actor *parent, float health = 100.0f, float max_health = 100.0f, float mana = 100.0f, float max_mana = 100.0f, float damage = 40.0f, float mana_regen = 10.0f);

    // functions about mana
    bool can_use_mana(float mana_cost);
    void regen_mana(float dt);
    void use_mana(float mana_cost);

    // functions about health
    void take_damage(float damage);

    // getters and setters of the states
    [[nodiscard]] float get_health() const {
        return health_;
    }

    void set_health(float health) {
        health_ = health;
    }

    [[nodiscard]] float get_max_health() const {
        return max_health_;
    }

    void set_max_health(float max_health) {
        max_health_ = max_health;
    }

    [[nodiscard]] float get_mana() const {
        return mana_;
    }

    void set_mana(float mana) {
        mana_ = mana;
    }

    [[nodiscard]] float get_max_mana() const {
        return max_mana_;
    }

    void set_max_mana(float max_mana) {
        max_mana_ = max_mana;
    }

    [[nodiscard]] float get_mana_regen() const {
        return mana_regen_;
    }

    void set_mana_regen(float mana_regen) {
        mana_regen_ = mana_regen;
    }

    [[nodiscard]] float get_damage() const {
        return damage_;
    }

    void set_damage(float damage) {
        damage_ = damage;
    }

    [[nodiscard]] bool is_alive() const {
        return is_alive_;
    }

    void set_alive(bool alive) {
        is_alive_ = alive;
    }

    [[nodiscard]] bool is_invisible() const {
        return is_invisible_;
    }

    void set_invisible(bool invisible) {
        std::cout << "Set invisible: " << invisible << std::endl;
        is_invisible_ = invisible;
    }

    [[nodiscard]] float get_invisible_time() const {
        return invisible_time_;
    }

    void set_invisible_time(float invisible_time) {
        invisible_time_ = invisible_time;
    }

    // setter and getter of invisible_timer
    [[nodiscard]] float get_invisible_timer() const {
        return invisible_timer;
    }

    void set_invisible_timer(float invisible_timer) {
        States::invisible_timer = invisible_timer;
    }


    [[nodiscard]] Actor *get_parent() const {
        return parent_;
    }

    void set_parent(Actor *parent) {
        parent_ = parent;
    }

};


#endif //HELLO_STATES_H