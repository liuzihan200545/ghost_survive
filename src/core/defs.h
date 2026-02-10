//
// Created by Lenovo on 2026/2/7.
//

#ifndef HELLO_DEFS_H
#define HELLO_DEFS_H

#include <ostream>
#include <iostream>

enum class ObjectType {
    NONE,
    OBJECT_SCREEN,
    OBJECT_WORLD,
    ENEMY
};

enum class Anchor
{
    NONE,
    TOP_LEFT,
    TOP_CENTER,
    TOP_RIGHT,
    CENTER_LEFT,
    CENTER,
    CENTER_RIGHT,
    BOTTOM_LEFT,
    BOTTOM_CENTER,
    BOTTOM_RIGHT,
};

inline std::ostream& operator<<(std::ostream& os, const ObjectType& type) {
    switch (type) {
        case ObjectType::NONE:          os << "NONE"; break;
        case ObjectType::OBJECT_SCREEN: os << "OBJECT_SCREEN"; break;
        case ObjectType::OBJECT_WORLD:  os << "OBJECT_WORLD"; break;
        case ObjectType::ENEMY:        os << "ENEMY"; break;
        default:                        os << "UNKNOWN"; break;
    }
    return os;
}

#endif //HELLO_DEFS_H