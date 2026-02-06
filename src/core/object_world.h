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
    virtual void update(float dt) override;
    void setPosition(const glm::vec2& position);
    virtual void setRenderPosition(const glm::vec2& position) override;
};


#endif //HELLO_OBJECTWORLD_H