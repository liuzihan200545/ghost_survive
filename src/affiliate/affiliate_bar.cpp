//
// Created by Lenovo on 2026/2/11.
//

#include "affiliate_bar.h"

AffiliateBar * AffiliateBar::
addAffiliateBarChild(ObjectScreen *parent, glm::vec2 size, Anchor anchor) {
    auto bar = new AffiliateBar();
    bar->init();
    bar->set_size(size);
    bar->set_anchor(anchor);
    if (parent) {
        parent->addChild(bar);
        bar->set_parent(parent);
    }
    return bar;
}

void AffiliateBar::render() {
    ObjectAffiliate::render();
    auto pos = parent_->get_render_position() + m_offset;
    if (percentage_ > 0.7f) {
        Game::get_instance().renderHBar(pos, m_size, percentage_, color_high_);
    } else if (percentage_ > 0.3f) {
        Game::get_instance().renderHBar(pos, m_size, percentage_, color_mid_);
    } else {
        Game::get_instance().renderHBar(pos, m_size, percentage_, color_low_);
    }
}
