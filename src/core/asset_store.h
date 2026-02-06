//
// Created by Lenovo on 2026/2/6.
//

#ifndef HELLO_ASSET_STORE_H
#define HELLO_ASSET_STORE_H

#include <string>
#include <unordered_map>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_mixer/SDL_mixer.h>
#include <SDL3_ttf/SDL_ttf.h>

class AssetStore {
private:
    std::unordered_map<std::string,SDL_Texture*> m_textures;
    std::unordered_map<std::string,MIX_Audio*> m_sounds;
    std::unordered_map<std::string,MIX_Audio*> m_music;
    std::unordered_map<std::string,TTF_Font*> m_fonts;

    SDL_Renderer* m_renderer = nullptr;

    MIX_Mixer* m_mix = nullptr;

public:
    AssetStore(SDL_Renderer* renderer, MIX_Mixer* mix) {
        m_renderer = renderer;
        m_mix = mix;
    }
    ~AssetStore() = default;

    // 载入函数
    void loadImage(const std::string& file_path);
    void loadSound(const std::string& file_path);
    void loadMusic(const std::string& file_path);
    void loadFont(const std::string& file_path, int font_size);

    // 读取函数
    SDL_Texture* getImage(const std::string& file_path);
    MIX_Audio* getSound(const std::string& file_path);
    MIX_Audio* getMusic(const std::string& file_path);
    TTF_Font* getFont(const std::string& file_path, int font_size);

    void clean();
};

#endif //HELLO_ASSET_STORE_H