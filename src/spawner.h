//
// Created by Lenovo on 2026/2/10.
//

#ifndef HELLO_SPAWNER_H
#define HELLO_SPAWNER_H

#include "core/object.h"

class Player;

class Spawner : public Object {
protected:
    int num_ = 20;
    float timer_ = 0.0f;
    float interval_ = 3.0f;
    Player* target_ = nullptr;
public:

    // update
    void update(float dt) override;

    // getter and setter
    int get_num() { return num_; }
    void set_num(int num) { num_ = num; }
    float get_timer() { return timer_; }
    void set_timer(float timer) { timer_ = timer; }
    float get_interval() { return interval_; }
    void set_interval(float interval) { interval_ = interval; }
    Player *get_target() const {
        return target_;
    }
    void set_target(Player *target) {
        target_ = target;
    }

};


#endif //HELLO_SPAWNER_H
