//
// Created by Lenovo on 2026/2/5.
//

#ifndef HELLO_SCENE_MAIN_H
#define HELLO_SCENE_MAIN_H

#include "core/scene.h"

class SceneMain : public Scene {
    glm::vec2 m_world_size = glm::vec2(0);
public:
    SceneMain() = default;
    virtual ~SceneMain() = default;
    virtual void init()override;
    virtual void handle_events(SDL_Event& event) override;
    virtual void update(float dt)override;
    virtual void render()override;
    virtual void clean()override;

private:
    void renderBackground();
};

#endif //HELLO_SCENE_MAIN_H