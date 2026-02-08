//
// Created by Lenovo on 2026/2/6.
//

#ifndef HELLO_PLAYER_H
#define HELLO_PLAYER_H

#include "core/actor.h"
#include "affiliate/spriteAnim.h"

class Player : public Actor {
    SpriteAnim* m_sprite_idle = nullptr;
    SpriteAnim* m_sprite_move  = nullptr;
    bool is_moving = false;
public:
    virtual void init() override;
    virtual void handle_events(SDL_Event &event) override;
    virtual void update(float dt) override;
    virtual void render() override;
    virtual void clean() override;

    void KeyBoardControl();

    void syncCamera();

    void checkState();

    void changeState(bool is_moving);

};

#endif //HELLO_PLAYER_H