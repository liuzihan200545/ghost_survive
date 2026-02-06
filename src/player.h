//
// Created by Lenovo on 2026/2/6.
//

#ifndef HELLO_PLAYER_H
#define HELLO_PLAYER_H

#include "core/actor.h"

class Player : public Actor {

public:
    virtual void init() override;
    virtual void handle_events(SDL_Event &event) override;
    virtual void update(float dt) override;
    virtual void render() override;
    virtual void clean() override;

    void KeyBoardControl();

    void move(float dt);

    void syncCamera();

};

#endif //HELLO_PLAYER_H