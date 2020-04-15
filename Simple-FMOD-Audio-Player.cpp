// Simple-FMOD-Audio-Player.cpp 
// Ross Hoyt

#include <iostream>
#include <fmod.hpp>
#include <Windows.h>

FMOD::System* sys; // FMOD's low-level audio system

const char* AUDIO_FILE = "mx_section_1.ogg"; // 30 second loopable music file
int nSeconds = 60;                           // how long to play sound

void playSoundFMOD(const char* filename, bool loop = false) {
    // sound    
    FMOD::Sound* sound;
    // the sound's channel
    FMOD::Channel* channel;
    // create sound
    sys->createSound(filename, loop ? FMOD_LOOP_NORMAL : FMOD_LOOP_OFF, 0, &sound);
    // assign channel and play sound
    sys->playSound(sound, 0, true /*start paused*/, &channel);
    // actually play sound
    channel->setPaused(false);
}

int main() {
    FMOD::System_Create(&sys);
    sys->init(32 /*max number of audio channels*/, FMOD_INIT_NORMAL, 0);
    playSoundFMOD(AUDIO_FILE, true);
    // let song play by sleeping main thread for some time
    Sleep(nSeconds * 1000);
    return 0;
}

