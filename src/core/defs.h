//
// Created by Lenovo on 2026/2/7.
//

#ifndef HELLO_DEFS_H
#define HELLO_DEFS_H

#include <ostream>

enum class ObjectType {
    NONE,
    OBJECT_SCREEN,
    OBJECT_WORLD,
};

inline std::ostream& operator<<(std::ostream& os, const ObjectType& type) {
    switch (type) {
        case ObjectType::NONE:          os << "NONE"; break;
        case ObjectType::OBJECT_SCREEN: os << "OBJECT_SCREEN"; break;
        case ObjectType::OBJECT_WORLD:  os << "OBJECT_WORLD"; break;
        default:                        os << "UNKNOWN"; break;
    }
    return os;
}

#endif //HELLO_DEFS_H