//
// Created by Lenovo on 2026/2/9.
//

#ifndef HELLO_COLLIDER_H
#define HELLO_COLLIDER_H

#include "../core/object_affiliate.h"

class Collider : public ObjectAffiliate {
protected:
    enum class Type {
        CIRCLE,  // size_的x轴为直径  默认 y == x
        RECTANGLE,
    };

    Type type_ = Type::CIRCLE;
public:
    bool is_Colliding(Collider* other);

    static Collider * addColliderChild(ObjectScreen* parent,glm::vec2 size,Type type = Type::CIRCLE, Anchor anchor = Anchor::CENTER);

    virtual void render() override;
};


#endif //HELLO_COLLIDER_H