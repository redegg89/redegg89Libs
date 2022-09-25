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

    int audio_rate = 44100;
    int audio_buffers = 4096;
    int audio_channels = 2;
    Mix_Chunk *sound = NULL;

void playSound(char file[], int isBGM, int track)
{
    SDL_Init(SDL_INIT_AUDIO);
    Mix_OpenAudio(audio_rate, AUDIO_S16, audio_channels, audio_buffers);
    sound = Mix_LoadWAV(file); //Loads WAV file from first argument
    int channel;
    channel = Mix_PlayChannel(track, sound, isBGM); //Plays the sound defined above on the channel specified (-1 is first non-playing track), with second argument being used for looping the audio
}

void FreeSound()
{
    Mix_FreeChunk(sound);
    Mix_CloseAudio();
    SDL_Quit();
}