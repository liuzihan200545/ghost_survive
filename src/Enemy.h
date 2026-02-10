//
// Created by Lenovo on 2026/2/8.
//

#ifndef HELLO_ENERMY_H
#define HELLO_ENERMY_H


#include "player.h"

class Enemy : public Actor {

    enum class State {
        NORMAL,
        HURT,
        DIE
    };

    Player* target_ = nullptr;

    State current_state_ = State::NORMAL;

    SpriteAnim* anim_normal_ = nullptr;
    SpriteAnim* anim_hurt_ = nullptr;
    SpriteAnim* anim_die_ = nullptr;
    SpriteAnim* anim_current_ = nullptr;

public:
    static Enemy* addEnemyChild(Object* parent, const glm::vec2& pos, Player* target);

    void aim_target(Player* target);

    void checkState();
    void changeState(State );

    virtual void init() override;

    virtual void update(float dt) override;

    void remove();

    void attack();

    // getter and setter
    [[nodiscard]] Player * get_target() const {
        return target_;
    }

    void set_target(Player * const m_player) {
        this->target_ = m_player;
    }

};


#endif //HELLO_ENERMY_H