// Simple-FMOD-Audio-Player.cpp 
// Ross Hoyt

#include <iostream>
#include <fmod.hpp>
#include <Windows.h>

FMOD::System* sys;
int nSeconds = 10;

void playSoundFMOD(const char* filename) {
    // sound    
    FMOD::Sound* sound;
    // the sound's channel
    FMOD::Channel* channel;
    // create sound
    sys->createSound(filename, FMOD_LOOP_OFF, 0, &sound);
    // assign channel and play sound
    sys->playSound(sound, 0, true /*start paused*/, &channel);
    // actually play sound
    channel->setPaused(false);
}

int main()
{
    FMOD::System_Create(&sys);
    sys->init(32 /*maximum number of audio channels*/, FMOD_INIT_NORMAL, 0);  
    playSoundFMOD("mx_section_1.ogg");
    // let song play for 10 seconds to test we're getting correct audio output
    Sleep(nSeconds * 1000);
    return 0;
}
