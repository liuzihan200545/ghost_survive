//
// Created by Lenovo on 2026/2/6.
//

#ifndef HELLO_OBJECTWORLD_H
#define HELLO_OBJECTWORLD_H

#include "object_screen.h"

class ObjectWorld: public ObjectScreen{
protected:
    glm::vec2 m_position = glm::vec2(0);
public:
    virtual void init() override {
        m_type = ObjectType::OBJECT_WORLD;
    }

    virtual void update(float dt) override;

    virtual void setRenderPosition(const glm::vec2& position) override;

    [[nodiscard]] glm::vec2 getPosition() const;

    void setPosition(const glm::vec2& position);
};


#endif //HELLO_OBJECTWORLD_H