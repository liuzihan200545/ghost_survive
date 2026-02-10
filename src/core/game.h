//
// Created by Lenovo on 2026/2/5.
//

#ifndef HELLO_GAME_H
#define HELLO_GAME_H

#include <string>
#include "asset_store.h"
#include <glm/glm.hpp>
#include <random>

class Scene;
struct Texture;

class Game {
private:
    Game() = default; //私有构造函数
    glm::vec2 m_screen_size = glm::vec2(0);

    AssetStore* m_asset_store = nullptr;

    SDL_Window* m_window = nullptr;
    SDL_Renderer* m_renderer = nullptr;
    MIX_Mixer* m_mixer = nullptr;

    bool m_is_running = true;

    uint64_t m_fps = 60;
    uint64_t m_frame_delay = 0;  // 单位 ns
    float m_dt = 0.0f; // 单位 s

    Scene* m_current_scene = nullptr;

    std::mt19937 gen_ = std::mt19937(std::random_device{}());

public:
    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;

    static Game& get_instance() {
        static Game instance;
        return instance;
    }

    void run();
    void init(std::string title,int width,int height);
    void handle_events();
    void update(float dt);
    void render();
    void clean();

    glm::vec2 getScreenSize() const {
        return m_screen_size;
    }

    Scene* getCurrentScene() const {
        return m_current_scene;
    }

    AssetStore* getAssetStore() const {
        return m_asset_store;
    }

    // 工具函数
    void drawGrid(const glm::vec2& top_left, const glm::vec2& bottom_right, float grid_width, SDL_FColor fcolor);

    void drawBoundary(const glm::vec2& top_left, const glm::vec2& bottom_right, float boundary_width, SDL_FColor fcolor);

    void renderTexture(const Texture& texture, const glm::vec2& position, const glm::vec2& size);

    void renderCircle(const glm::vec2& position, const glm::vec2 &size, float alpha);

    // 随机数函数
    float random_float(float min, float max) {
        std::uniform_real_distribution<float> dist(min, max);
        return dist(gen_);
    }

    int random_int(int min, int max) {
        std::uniform_int_distribution<int> dist(min, max);
        return dist(gen_);
    }

    glm::vec2 random_vec2(glm::vec2 min, glm::vec2 max) {
        std::uniform_real_distribution<float> dist_x(min.x, max.x);
        std::uniform_real_distribution<float> dist_y(min.y, max.y);
        return {dist_x(gen_), dist_y(gen_)};
    }

    glm::ivec2 random_ivec2(glm::ivec2 min, glm::ivec2 max) {
        std::uniform_int_distribution<int> dist_x(min.x, max.x);
        std::uniform_int_distribution<int> dist_y(min.y, max.y);
        return {dist_x(gen_), dist_y(gen_)};
    }

};


#endif //HELLO_GAME_H