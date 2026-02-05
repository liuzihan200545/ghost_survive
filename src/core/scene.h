//
// Created by Lenovo on 2026/2/5.
//

#ifndef HELLO_SCENE_H
#define HELLO_SCENE_H

#include "object.h"
#include <glm/glm.hpp>
#include <vector>

class Scene: public Object {
protected:
    glm::vec2 m_camera_position = glm::vec2(0); // 相机位置
    std::vector<Object*> m_objects; // 场景中的物体
public:
    Scene() = default;
    virtual ~Scene() = default;

    virtual void init() override{};
    virtual void handle_events(SDL_Event& event) override{};
    virtual void update(float dt) override{};
    virtual void render() override{};
    virtual void clean() override{};

};



#endif //HELLO_SCENE_H