#ifndef __KTP_SOUND_H_
#define __KTP_SOUND_H_

#define NUM_OF_SOUND	5

enum { MENUBGM, GAMEBGM, GAMEOVER, KEYEFFECT, RADAR };

void KTP_SoundInit();

void KTP_SoundRelease();

void KTP_SoundPlay(int soundnumber);

void KTP_SoundStop(int channelnumber);

void KTP_SoundUpdate();

#endif
