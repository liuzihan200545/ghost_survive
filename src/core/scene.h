//
// Created by Lenovo on 2026/2/5.
//

#ifndef HELLO_SCENE_H
#define HELLO_SCENE_H

#include "object.h"
#include <glm/glm.hpp>
#include <vector>
#include "object_world.h"

class Scene: public Object {
protected:
    glm::vec2 m_camera_position = glm::vec2(0); // 相机位置
    glm::vec2 m_world_size = glm::vec2(0);
    std::vector<ObjectScreen *> m_children_screen;
    std::vector<ObjectWorld *> m_children_world;
public:
    Scene() = default;
    virtual ~Scene() = default;

    virtual void init() override{};
    virtual void handle_events(SDL_Event& event) override;
    virtual void update(float dt) override;
    virtual void render() override;
    virtual void clean() override;

    virtual void addChild(Object* child) override;
    virtual void removeChild(Object* child) override;

    glm::vec2 worldToScreen(const glm::vec2 &world_position) {
        return world_position - m_camera_position;
    }

    glm::vec2 ScreenToWorld(const glm::vec2 &screen_position) {
        return screen_position + m_camera_position;
    }

    // getter and setter of camera
    glm::vec2 getCameraPosition() const {
        return m_camera_position;
    }

    void setCameraPosition(const glm::vec2 &camera_position);

    // getter and setter of world size
    glm::vec2 getWorldSize() const {
        return m_world_size;
    }

    void setWorldSize(const glm::vec2 &world_size) {
        m_world_size = world_size;
    }

};



#endif //HELLO_SCENE_H