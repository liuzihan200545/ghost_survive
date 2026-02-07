//
// Created by Lenovo on 2026/2/6.
//

#ifndef HELLO_OBJECT_SCREEN_H
#define HELLO_OBJECT_SCREEN_H

#include "object.h"

class ObjectScreen : public Object {

protected:
    glm::vec2 m_render_position = glm::vec2(0);
public:
    virtual void init() override{
        m_type = ObjectType::OBJECT_SCREEN;
    }

    glm::vec2 getRenderPosition() const {
        return m_render_position;
    }

    virtual void setRenderPosition(const glm::vec2& _render_position) {
        this->m_render_position = _render_position;
    }

};

#endif //HELLO_OBJECT_SCREEN_H