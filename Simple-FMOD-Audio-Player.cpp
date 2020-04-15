// Simple-FMOD-Audio-Player.cpp 
// Ross Hoyt

#include <iostream>
#include <fmod.hpp>
#include <Windows.h>

FMOD::System* sys;                           // FMOD's low-level audio system
const char* AUDIO_FILE = "mx_section_1.ogg"; // 00:31:30 loopable music file

void playSoundFMOD(const char* filename, bool loop = false, int nLoops = 1) {
    // sound    
    FMOD::Sound* sound;
    // the sound's channel
    FMOD::Channel* channel;
    // create sound
    sys->createSound(filename, loop ? FMOD_LOOP_NORMAL : FMOD_LOOP_OFF, 0, &sound);
    
    // get length of sound file (to allow sound playback by sleeping main thread for this amt of time)
    unsigned int msLen; 
    sound->getLength(&msLen, FMOD_TIMEUNIT_MS);
    //msLen *= nLoops; // adjust playback length by number of requested loops

    // assign channel and begin to play sound
    sys->playSound(sound, 0, true /*start paused*/, &channel);
    // actually start the sound
    channel->setPaused(false);

    // let song play by sleeping main thread for some time
    Sleep(msLen * nLoops);
}

int main() {
    FMOD::System_Create(&sys);
    sys->init(32 /*max number of audio channels*/, FMOD_INIT_NORMAL, 0);
    playSoundFMOD(AUDIO_FILE, true, 1);
    return 0;
}

