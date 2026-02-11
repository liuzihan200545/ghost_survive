//
// Created by Lenovo on 2026/2/11.
//

#ifndef HELLO_AFFILIATE_BAR_H
#define HELLO_AFFILIATE_BAR_H

#include "../core/object_affiliate.h"

class AffiliateBar : public ObjectAffiliate {
protected:
    float percentage_{1.0f};
    SDL_FColor color_high_ = {0.0f, 1.0f, 0.0f, 1.0f};
    SDL_FColor color_mid_ = {1.0f, 0.65f, 0.0f, 1.0f};
    SDL_FColor color_low_ = {1.0f, 0.0f, 0.0f, 1.0f};
public:
    // main functions
    static AffiliateBar* addAffiliateBarChild(ObjectScreen* parent, glm::vec2 size, Anchor anchor);
    void render() override;

    // getters and setters
    float get_percentage() const { return percentage_; }
    void set_percentage(float percentage) { percentage_ = percentage; }
};


#endif //HELLO_AFFILIATE_BAR_H