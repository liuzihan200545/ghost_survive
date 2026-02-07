//
// Created by Lenovo on 2026/2/7.
//

#ifndef HELLO_BACKGROUND_MAIN_H
#define HELLO_BACKGROUND_MAIN_H

#include "core/object.h"
#include <glm/glm.hpp>

class BackgroundMain : public Object {
public:
    BackgroundMain(glm::vec2 world_size, const glm::vec2& camera_pos)
        : m_world_size(world_size), m_camera_position(camera_pos) {}
private:
    glm::vec2 m_world_size;
    const glm::vec2& m_camera_position; // 引用场景中的摄像机位置变量

    virtual void render() override ;
};


#endif //HELLO_BACKGROUND_MAIN_H