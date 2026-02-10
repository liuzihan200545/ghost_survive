//
// Created by Lenovo on 2026/2/10.
//

#ifndef HELLO_UI_MOUSE_H
#define HELLO_UI_MOUSE_H

#include "../affiliate/sprite.h"
#include "../core/object_screen.h"


class UIMouse : public ObjectScreen {
protected:
    Sprite* sprite1_ = nullptr;
    Sprite* sprite2_ = nullptr;
    float timer_ = 0.0f;
public:

    // main functions
    void update(float dt) override;

    static UIMouse* addUIMouseChild(Object* parent, const std::string& file_path_1, const std::string& file_path_2, float scale ,Anchor anchor = Anchor::CENTER);

    // setter and getter
    void set_sprite_1(Sprite* sprite) { sprite1_ = sprite; }
    Sprite* get_sprite_1() const { return sprite1_; }
    void set_sprite_2(Sprite* sprite) { sprite2_ = sprite; }
    Sprite* get_sprite_2() const { return sprite2_; }

};


#endif //HELLO_UI_MOUSE_H