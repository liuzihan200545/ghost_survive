//
// Created by Lenovo on 2026/2/10.
//

#ifndef HELLO_WEAPON_THUNDER_H
#define HELLO_WEAPON_THUNDER_H

#include "raw/weapon.h"

class Actor;

class WeaponThunder : public Weapon {
protected:

public:
    virtual void handle_events(SDL_Event &event) override;

    static WeaponThunder* addWeaponThunderChild(Actor* parent, float cool_down, float mana_cost);

};


#endif //HELLO_WEAPON_THUNDER_H