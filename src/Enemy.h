//
// Created by Lenovo on 2026/2/8.
//

#ifndef HELLO_ENERMY_H
#define HELLO_ENERMY_H


#include "player.h"

class Enemy : public Actor {

    Player* m_player = nullptr;

public:

    void aim_target(Player* target);

    virtual void init() override;

    virtual void update(float dt) override;

    // getter and setter
    [[nodiscard]] Player * get_target() const {
        return m_player;
    }

    void set_target(Player * const m_player) {
        this->m_player = m_player;
    }

};


#endif //HELLO_ENERMY_H