//
// Created by Lenovo on 2026/2/5.
//

#ifndef HELLO_SCENE_MAIN_H
#define HELLO_SCENE_MAIN_H

#include "core/scene.h"

class Player;

class SceneMain : public Scene {
    Player *m_player = nullptr;
public:
    SceneMain() = default;
    virtual ~SceneMain() = default;
    virtual void init()override;
    virtual void handle_events(SDL_Event& event) override;
    virtual void update(float dt)override;
    virtual void render()override;
    virtual void clean()override;
};

#endif //HELLO_SCENE_MAIN_H