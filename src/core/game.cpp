//
// Created by Lenovo on 2026/2/5.
//

#include "game.h"
#include "../scene_main.h"

#include <iostream>

void Game::run() {
    while (m_is_running) {
        auto start = SDL_GetTicksNS();
        handle_events();
        update(m_dt);
        render();
        auto end = SDL_GetTicksNS();
        auto elapsed = end - start;
        if (elapsed < m_frame_delay) {
            SDL_DelayNS(m_frame_delay - elapsed);
            m_dt = m_frame_delay / 1.0e9;
        }
        else {
            m_dt = elapsed / 1.0e9;
        }

        //SDL_Log("FPS: %f", 1 / m_dt);
    }
}

void Game::init(std::string title, int width, int height) {
    m_screen_size = glm::vec2(width, height);
    // 1. SDL3初始化
    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO)) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,"SDL初始化失败: %s\n", SDL_GetError());
    }

    // 2. SDL_ttf 初始化
    // 注意：SDL3_ttf 的 Init 不需要传参数，返回 true 表示成功
    if (!TTF_Init()) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL_ttf 初始化失败: %s\n", SDL_GetError());
    }

    // 3. 初始化 SDL_mixer 核心系统 (返回 bool)
    if (!MIX_Init()) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL_mixer 初始化失败: %s\n", SDL_GetError());
        return;
    }

    // 4. 创建混合器设备 (Mixer Device)
    // SDL3_mixer 现在支持多设备，通过 MIX_CreateMixerDevice 创建
    // 参数 0 使用默认音频设备，NULL 使用默认音频参数 (通常为 48000Hz, Float32)
    MIX_Mixer *mixer = MIX_CreateMixerDevice(SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK, NULL);
    if (!mixer) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "创建 Mixer 失败: %s\n", SDL_GetError());
        return;
    }

    // 5.创建窗口与渲染器
    SDL_CreateWindowAndRenderer(title.c_str(),width,height,SDL_WINDOW_RESIZABLE,&m_window,&m_renderer);

    if (!m_window || !m_renderer) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,"创建窗口或渲染器失败%s\n", SDL_GetError());
    }

    // 6.设置逻辑分辨率
    SDL_SetRenderLogicalPresentation(m_renderer,width,height,SDL_LOGICAL_PRESENTATION_LETTERBOX);

    std::cout << "SDL初始化完毕" << std::endl;

    m_frame_delay = 1000000000 / m_fps;

    m_current_scene = new SceneMain();
    m_current_scene->init();
}

void Game::handle_events() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_EVENT_QUIT:
                m_is_running = false;
                break;
            default:
                m_current_scene->handle_events(event);
        }
    }
}

void Game::update(float dt) {
    m_current_scene->update(dt);
}

void Game::render() {
    SDL_SetRenderDrawColor(m_renderer,0,0,0,255);
    SDL_RenderClear(m_renderer);
    m_current_scene->render();
    SDL_RenderPresent(m_renderer);
}

void Game::clean() {
    if (m_current_scene) {
        m_current_scene->clean();
        delete m_current_scene;
    }

    if (m_renderer) {
        SDL_DestroyRenderer(m_renderer);
    }
    if (m_window) {
        SDL_DestroyWindow(m_window);
    }
    MIX_Quit();
    TTF_Quit();
    SDL_Quit();
}

void Game::drawGrid(const glm::vec2 &top_left, const glm::vec2 &bottom_right, float grid_width, SDL_FColor fcolor) {
    SDL_SetRenderDrawColorFloat(m_renderer,fcolor.r,fcolor.g,fcolor.b,fcolor.a);
    for (float x = top_left.x; x <= bottom_right.x; x += grid_width) {
        SDL_RenderLine(m_renderer,x,top_left.y,x,bottom_right.y);
    }
    for (float y = top_left.y; y <= bottom_right.y; y += grid_width) {
        SDL_RenderLine(m_renderer,top_left.x,y,bottom_right.x,y);
    }
    SDL_SetRenderDrawColorFloat(m_renderer,0,0,0,1);

}

void Game::drawBoundary(const glm::vec2 &top_left, const glm::vec2 &bottom_right, float boundary_width,
    SDL_FColor fcolor) {
    SDL_SetRenderDrawColorFloat(m_renderer,fcolor.r,fcolor.g,fcolor.b,fcolor.a);
    for (float i = 0; i < boundary_width; i ++) {
        SDL_FRect rect = {
            top_left.x - i,
            top_left.y - i,
            bottom_right.x - top_left.x + 2*i,
            bottom_right.y - top_left.y + 2*i,
        };
        SDL_RenderRect(m_renderer, &rect);
    }
    SDL_SetRenderDrawColorFloat(m_renderer,0,0,0,1);
}
