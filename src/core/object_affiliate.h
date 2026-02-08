//
// Created by Lenovo on 2026/2/8.
//

#ifndef HELLO_OBJECT_AFFILIATE_H
#define HELLO_OBJECT_AFFILIATE_H

#include "object_screen.h"

class ObjectAffiliate : public Object{
protected:
    ObjectScreen* m_parent = nullptr;

public:
    // getter and setter

    [[nodiscard]] ObjectScreen * get_parent() const {
        return m_parent;
    }

    void set_parent(ObjectScreen * const parent) {
        this->m_parent = parent;
    }

    [[nodiscard]] glm::vec2 get_offset() const {
        return m_offset;
    }

    void set_offset(const glm::vec2 &offset) {
        this->m_offset = offset;
    }

    [[nodiscard]] glm::vec2 get_size() const {
        return m_size;
    }

    void set_size(const glm::vec2 &size) {
        this->m_size = size;
    }

protected:
    glm::vec2 m_offset = glm::vec2(0,0);
    glm::vec2 m_size = glm::vec2(0,0);

public:
    // getters and setters

};


#endif //HELLO_OBJECT_AFFILIATE_H