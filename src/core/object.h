//
// Created by Lenovo on 2026/2/5.
//

#ifndef HELLO_OBJECT_H
#define HELLO_OBJECT_H

#include "game.h"

class Object {
protected:
    Game& m_game = Game::get_instance();
public:
    Object() = default;
    virtual ~Object() = default;  // 所有的类不在构造函数和析构函数中做任何事

    virtual void init(){}  // 需要初始化的事物，在init中做
    virtual void handle_events(SDL_Event& event){}
    virtual void update(float dt){}
    virtual void render(){}
    virtual void clean(){} // 需要销毁的事物，在clean中做

};


#endif //HELLO_OBJECT_H