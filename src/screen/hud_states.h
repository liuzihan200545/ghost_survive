//
// Created by Lenovo on 2026/2/11.
//

#ifndef HELLO_HUD_STATES_H
#define HELLO_HUD_STATES_H

#include "../core/object_screen.h"

class Sprite; class Actor;

class HUDStates : public ObjectScreen {
protected:
    Actor* target_ = nullptr;

    Sprite* health_bar_ = nullptr;
    Sprite* health_bar_bg_ = nullptr;
    Sprite* health_icon_ = nullptr;
    Sprite* mana_bar_ = nullptr;
    Sprite* mana_bar_bg_ = nullptr;
    Sprite* mana_icon_ = nullptr;

    float health_percentage_ = 1.0f;
    float mana_percentage_ = 1.0f;

private:
    void update_health_bar();
    void update_mana_bar();

public:
    // main functions
    void update(float dt) override;

    void init() override;

    static HUDStates* addHUDStatesChild(Object* parent, Actor* target, const glm::vec2& render_pos);

    // getters and setters
    Actor* get_target() const { return target_; }
    void set_target(Actor* target) { target_ = target; }

    float get_health_percentage() const { return health_percentage_; }
    void set_health_percentage(float health_percentage) { health_percentage_ = health_percentage; }

    float get_mana_percentage() const { return mana_percentage_; }
    void set_mana_percentage(float mana_percentage) { mana_percentage_ = mana_percentage; }

    Sprite* get_health_bar() const { return health_bar_; }
    Sprite* get_health_bar_bg() const { return health_bar_bg_; }
    Sprite* get_health_icon() const { return health_icon_; }
    Sprite* get_mana_bar() const { return mana_bar_; }
    Sprite* get_mana_bar_bg() const { return mana_bar_bg_; }
    Sprite* get_mana_icon() const { return mana_icon_; }

    void set_health_bar(Sprite* health_bar) { health_bar_ = health_bar; }
    void set_health_bar_bg(Sprite* health_bar_bg) { health_bar_bg_ = health_bar_bg; }
    void set_health_icon(Sprite* health_icon) { health_icon_ = health_icon; }
    void set_mana_bar(Sprite* mana_bar) { mana_bar_ = mana_bar; }
    void set_mana_bar_bg(Sprite* mana_bar_bg) { mana_bar_bg_ = mana_bar_bg; }
    void set_mana_icon(Sprite* mana_icon) { mana_icon_ = mana_icon; }
};


#endif //HELLO_HUD_STATES_H