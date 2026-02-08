//
// Created by Lenovo on 2026/2/6.
//

#include "asset_store.h"


void AssetStore::loadImage(const std::string &file_path) {
    SDL_Texture * texture = IMG_LoadTexture(m_renderer, file_path.c_str());
    if (texture == nullptr) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "IMG_LoadTexture() failed: %s of the file %s", SDL_GetError(), file_path.c_str());
        return;
    }
    m_textures.emplace(file_path, texture);
}

void AssetStore::loadSound(const std::string &file_path) {
    MIX_Audio *sound = MIX_LoadAudio(m_mix,file_path.c_str(),true);

    if (sound == nullptr)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to load sound: %s", SDL_GetError());
        return;
    }
    m_sounds.emplace(file_path, sound);

}

void AssetStore::loadMusic(const std::string &file_path) {
    MIX_Audio *music = MIX_LoadAudio(m_mix,file_path.c_str(),true);

    if (music == nullptr)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to load music: %s", SDL_GetError());
        return;
    }
    m_music.emplace(file_path, music);
}

void AssetStore::loadFont(const std::string &file_path, int font_size) {
    TTF_Font * font = TTF_OpenFont(file_path.c_str(),font_size);
    if (font == nullptr) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to load font: %s", SDL_GetError());
    }
    m_fonts.emplace(file_path+std::to_string(font_size), font);
}

SDL_Texture * AssetStore::getImage(const std::string &file_path) {
    auto it = m_textures.find(file_path);
    if (it == m_textures.end()) {
        loadImage(file_path);
        it = m_textures.find(file_path);
    }
    if (it == m_textures.end()) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to get texture: %s", SDL_GetError());
        return nullptr;
    }
    return it->second;
}

MIX_Audio * AssetStore::getSound(const std::string &file_path) {
    auto it = m_sounds.find(file_path);
    if (it == m_sounds.end()) {
        loadSound(file_path);
        it = m_sounds.find(file_path);
    }
    if (it == m_sounds.end()) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to get sound: %s", SDL_GetError());
        return nullptr;
    }
    return it->second;
}

MIX_Audio * AssetStore::getMusic(const std::string &file_path) {
    auto it = m_music.find(file_path);
    if (it == m_music.end()) {
        loadMusic(file_path);
        it = m_music.find(file_path);
    }
    if (it == m_music.end()) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to get music: %s", SDL_GetError());
        return nullptr;
    }
    return it->second;
}

TTF_Font * AssetStore::getFont(const std::string &file_path, int font_size) {
    auto it = m_fonts.find(file_path+std::to_string(font_size));
    if (it == m_fonts.end()) {
        loadFont(file_path, font_size);
        it = m_fonts.find(file_path+std::to_string(font_size));
    }
    if (it == m_fonts.end()) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to get font: %s", SDL_GetError());
        return nullptr;
    }
    return it->second;
}

void AssetStore::clean() {
    for (auto& texture : m_textures) {
        SDL_DestroyTexture(texture.second);
    }
    m_textures.clear();

    for (auto& sound : m_sounds) {
        MIX_DestroyAudio(sound.second);
    }
    m_sounds.clear();

    for (auto& music : m_music) {
        MIX_DestroyAudio(music.second);
    }
    m_music.clear();

    for (auto& font : m_fonts) {
        TTF_CloseFont(font.second);
    }
    m_fonts.clear();
}
