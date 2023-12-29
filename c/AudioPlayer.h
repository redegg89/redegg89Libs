/*
    redegg89Libs - A C Libary for Shortcuts
    Copyright (C) 2022  redegg89

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; specifically
    version 2 of the License.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public
    License along with this library; if not, it can be found at https://www.gnu.org/licenses/old-licenses/lgpl-2.0.txt
*/
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define playSound(...) GET_MACRO(__VA_ARGS__, playSound3, playSound2, playSound1)(__VA_ARGS__)

//https://stackoverflow.com/questions/17302913/generics-for-multiparameter-c-functions-in-c11/25715458#25715458

    int audio_rate = 44100;
    int audio_buffers = 4096;
    int audio_channels = 2;
    Mix_Chunk *sound = NULL;

void playSound_init()
{
    if(SDL_Init(SDL_INIT_AUDIO) == -1)
    {
        #ifdef __LINUX__
        printf("SDL could not initialize. Please run one of the following commands as root:\nDebian-based: apt-get install libsdl2\nGentoo: emerge libsdl2\nFedora and similar: dnf install SDL2\nArch: pacman -S sdl2\n\nOther directions can be found at: https://wiki.libsdl.org/Installation\n");
        #elif _WIN32
        printf("SDL could not initialize. Please make sure \"SDL2.dll\" is in the game directory.\n");
        #endif
        exit(-1);
    }
    Mix_OpenAudio(audio_rate, AUDIO_S16, audio_channels, audio_buffers);
}

void playSound3(char file[], int loop, int track)    //Start of multi-argument playSound. Is there a better way to do this since it's a lot of copy-pasted code? Absolutely, it didn't even work right iirc
{
    playSound_init();
    sound = Mix_LoadWAV(file); /*Loads WAV file from first argument*/
    int channel;
    channel = Mix_PlayChannel(track, sound, loop); /*Plays the sound defined above on the channel specified (-1 is first non-playing track), with second argument being used for looping the audio*/
}

void playSound2(char file[], int loop) 
{
    playSound_init();
    playSound3(file, loop, -1);
}

void playSound1(char file[])
{
    playSound_init();
    playSound3(file, 0, -1);
}

void FreeSound() //Please note this kills the bgm as well
{
    Mix_FreeChunk(sound);
    Mix_CloseAudio();
    SDL_Quit();
}