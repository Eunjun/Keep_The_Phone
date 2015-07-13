#include "common.h"

#define NUM_OF_SOUND	5

FMOD_SYSTEM *g_System = nullptr;
FMOD_SOUND *g_Sound[NUM_OF_SOUND] = { nullptr };
FMOD_CHANNEL *g_Channel[NUM_OF_SOUND] = { nullptr };

enum { MENUBGM, GAMEBGM, GAMEOVER, KEYEFFECT, RADAR };


void KTP_SoundInit()
{
	FMOD_System_Create(&g_System);
	FMOD_System_Init(g_System, 32, FMOD_INIT_NORMAL, NULL);

	FMOD_System_CreateSound(g_System, "./Sound/KTP_MenuBgm.mp3", FMOD_LOOP_NORMAL, 0, &g_Sound[MENUBGM]);
	FMOD_System_CreateSound(g_System, "./Sound/KTP_GameBgm.mp3", FMOD_LOOP_NORMAL, 0, &g_Sound[GAMEBGM]);
	FMOD_System_CreateSound(g_System, "./Sound/KTP_Gameover.mp3", FMOD_LOOP_NORMAL, 0, &g_Sound[GAMEOVER]);
	FMOD_System_CreateSound(g_System, "./Sound/KTP_KeyEffect.mp3", FMOD_DEFAULT, 0, &g_Sound[KEYEFFECT]);
	FMOD_System_CreateSound(g_System, "./Sound/KTP_Radar.wav", FMOD_DEFAULT, 0, &g_Sound[RADAR]);
}

void KTP_SoundRelease()
{
	int i;
	for (i = 0; i < NUM_OF_SOUND; i++)
	{
		FMOD_Sound_Release(g_Sound[i]);
	}
	FMOD_System_Close(g_System);
	FMOD_System_Release(g_System);
}

void KTP_SoundPlay(int soundnumber)
{
	FMOD_System_PlaySound(g_System,FMOD_CHANNEL_FREE, g_Sound[soundnumber], 0, &g_Channel[soundnumber]);
}

void KTP_SoundStop(int channelnumber)
{
	FMOD_Channel_Stop(g_Channel[channelnumber]);
}

void KTP_SoundUpdate()
{
	FMOD_System_Update(g_System);
}


