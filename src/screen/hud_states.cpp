//
// Created by Lenovo on 2026/2/11.
//

#include "hud_states.h"
#include "../core/actor.h"
#include "../raw/states.h"
#include "../affiliate/sprite.h"

void HUDStates::update_health_bar() {
    if (!target_ || !health_bar_ || !health_bar_bg_) return;
    health_bar_->set_percentage({target_->get_states()->get_health() / target_->get_states()->get_max_health(),1.0f});
}

void HUDStates::update_mana_bar() {
    if (!target_ || !mana_bar_ || !mana_bar_bg_) return;
    mana_bar_->set_percentage({target_->get_states()->get_mana() / target_->get_states()->get_max_mana(),1.0f});
}

void HUDStates::update(float dt) {
    ObjectScreen::update(dt);
    // 获取Actor的血量百分比，然后设置对应的sprite
    update_health_bar();
    update_mana_bar();
}

void HUDStates::init() {
    ObjectScreen::init();
    health_bar_bg_ = Sprite::addSpriteChild(this,"assets/UI/bar_bg.png",3.0f,Anchor::CENTER_LEFT);
    health_bar_bg_->set_offset(health_bar_bg_->get_offset() + glm::vec2(30,0));
    health_bar_ = Sprite::addSpriteChild(this,"assets/UI/bar_red.png",3.0f,Anchor::CENTER_LEFT);
    health_bar_->set_offset(health_bar_->get_offset() + glm::vec2(30,0));
    health_icon_ = Sprite::addSpriteChild(this,"assets/UI/Red Potion.png",0.5f,Anchor::CENTER_LEFT);

    mana_bar_bg_ = Sprite::addSpriteChild(this,"assets/UI/bar_bg.png",3.0f,Anchor::CENTER_LEFT);
    mana_bar_bg_->set_offset(mana_bar_bg_->get_offset() + glm::vec2(300,0));
    mana_bar_ = Sprite::addSpriteChild(this,"assets/UI/bar_blue.png",3.0f,Anchor::CENTER_LEFT);
    mana_bar_->set_offset(mana_bar_->get_offset() + glm::vec2(300,0));
    mana_icon_ = Sprite::addSpriteChild(this,"assets/UI/Blue Potion.png",0.5f,Anchor::CENTER_LEFT);
    mana_icon_->set_offset(mana_icon_->get_offset() + glm::vec2(270,0));

}

HUDStates * HUDStates::addHUDStatesChild(Object *parent, Actor *target, const glm::vec2 &render_pos) {
    auto hud_states = new HUDStates();
    hud_states->init();
    hud_states->set_target(target);
    hud_states->set_render_position(render_pos);
    if (parent) {parent->addChild(hud_states);}
    return hud_states;
}
