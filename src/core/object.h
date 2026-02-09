//
// Created by Lenovo on 2026/2/5.
//

#ifndef HELLO_OBJECT_H
#define HELLO_OBJECT_H

#include "game.h"
#include <vector>
#include "defs.h"

class Object {
protected:
    Game& m_game = Game::get_instance();
    std::vector<Object*> m_children;
    ObjectType m_type = ObjectType::NONE;
    bool m_is_active = true;
    bool need_remove_ = false;

public:
    [[nodiscard]] bool get_need_remove() const {
        return need_remove_;
    }

    void set_need_remove(bool need_remove) {
        need_remove_ = need_remove;
    }

    [[nodiscard]] bool get_is_active() const {
        return m_is_active;
    }

    void set_is_active(const bool is_active) {
        this->m_is_active = is_active;
    }

    Object() = default;
    virtual ~Object() = default;  // 所有的类不在构造函数和析构函数中做任何事

    virtual void init(){}  // 需要初始化的事物，在init中做
    virtual void handle_events(SDL_Event& event);
    virtual void update(float dt);
    virtual void render();
    virtual void clean(); // 需要销毁的事物，在clean中做

    virtual void addChild(Object* child);
    virtual void removeChild(Object* child);

    ObjectType get_type() const {
        return m_type;
    }



};

#endif //HELLO_OBJECT_H
