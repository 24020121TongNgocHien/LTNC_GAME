#pragma once

#include"CommonFunc.h"

class Music {
private:
    Mix_Music* music; 

public:

    Music(const std::string& filePath) {
        if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
            std::cerr << "error init SDL_mixer: " << Mix_GetError() << std::endl;
        }

        music = Mix_LoadMUS(filePath.c_str());
        if (!music) {
            std::cerr << "error load music: " << Mix_GetError() << std::endl;
        }
    }

    
    void play() {
        if (music) {
            Mix_PlayMusic(music, -1);
        }
    }

    void stop() {
        Mix_HaltMusic();
    }

    void setVolume(int volume) {
        Mix_VolumeMusic(volume);
    }

    
    ~Music() {
        Mix_FreeMusic(music);
        Mix_CloseAudio();
    }

    void effect(std::string path) {
        Mix_Chunk* effect = Mix_LoadWAV(path.c_str());
        if (!effect) {
            std::cout << "Failed to load MP3 effect: " << Mix_GetError() << std::endl;
            return;
        }

        Mix_PlayChannel(-1, effect, 0);
    }
};
