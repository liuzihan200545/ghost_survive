//
// Created by Lenovo on 2026/2/10.
//

#include "weapon_thunder.h"
#include "world/spell.h"
#include "core/actor.h"

void WeaponThunder::handle_events(SDL_Event &event) {
    Weapon::handle_events(event);
    if (event.type == SDL_EVENT_MOUSE_BUTTON_DOWN) {
        if (event.button.button == SDL_BUTTON_LEFT) {
            if (can_attack()) {
                auto pos = m_game.get_mouse_position();
                auto spell = Spell::addSpellChild(nullptr,"assets/effect/Thunderstrike w blur.png",pos,40.0f,3.0f,Anchor::CENTER);
                attack(pos,spell);
            }
        }
    }
}

WeaponThunder * WeaponThunder::addWeaponThunderChild(Actor *parent, float cool_down, float mana_cost) {
    auto weapon = new WeaponThunder();
    weapon->init();
    if (parent ) {parent->addChild(weapon);}
    weapon->set_parent(parent);
    weapon->set_cool_down(cool_down);
    weapon->set_mana_cost(mana_cost);
    return weapon;
}
