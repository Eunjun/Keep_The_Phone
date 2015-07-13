#include "common.h"
#include "KTP_InGameRender.h"
#include "KTP_Sound.h"

//
extern SDL_Window * g_Window;
extern SDL_Renderer * g_Renderer;
extern SDL_Rect PhoneRect;
extern SDL_Rect DJ_KRect;
extern SDL_Rect MSHRect;
extern SDL_Rect DJ_KRadarRect;
extern SDL_Rect MSHRadarRect;
//

//
int iDJKRadarIndex;
int iMSHRadarIndex;
int iRowIndex;
int iColIndex;
int iChecktime;
int iScore;
//


//
bool bHavePhone[5][5];
bool bDJKIsMoving;
bool bMSHIsMoving;
bool bRadar;
//

//
clock_t Curtime;
clock_t Oldtime;
//

SDL_Event Start;


void KTP_InGame()
{
	printf("KTP_InGame\n");

	KTP_SoundPlay(GAMEBGM);
	//KTP_SoundPlay(EFFECT);

	srand((unsigned int)time(NULL));

	Oldtime = clock();
	KTP_InGameRenderInit();
	KTP_InGameRender(false);

	iDJKRadarIndex = 0;
	iMSHRadarIndex = 4;
	iRowIndex = 0;
	iColIndex = 0;
	iScore = 0;

	iChecktime= 1700;
	bHavePhone[0][0] = true;
	bDJKIsMoving = false;
	bMSHIsMoving = false;
	bRadar = false;

	while (1)
	{
		Curtime = clock();
		while(SDL_PollEvent(&Start))
		{
			if (Start.type == SDL_KEYDOWN)
			{
				switch(Start.key.keysym.sym)
				{
				case SDLK_ESCAPE :
					puts("Start_returned!");
					bHavePhone[iRowIndex][iColIndex]=false;
					KTP_InGameRenderRelease();
					printf("Score : %d\n", iScore);
					return;

				case SDLK_LEFT :
					if(iRowIndex!=0)
					{
						PhoneRect.x -= 120;
						bHavePhone[iRowIndex][iColIndex]=false;
						bHavePhone[--iRowIndex][iColIndex]=true;
					}
					break;

				case SDLK_RIGHT :
					if(iRowIndex!=4)
					{
						PhoneRect.x += 120;
						bHavePhone[iRowIndex][iColIndex]=false;
						bHavePhone[++iRowIndex][iColIndex]=true;
					}
					break;

				case SDLK_UP :
					if(iColIndex!=0)
					{
						PhoneRect.y -= 100;
						bHavePhone[iRowIndex][iColIndex]=false;
						bHavePhone[iRowIndex][--iColIndex]=true;
					}
					break;

				case SDLK_DOWN :
					if(iColIndex!=4)
					{
						PhoneRect.y += 100;
						bHavePhone[iRowIndex][iColIndex]=false;
						bHavePhone[iRowIndex][++iColIndex]=true;
					}
					break;

				default :
					break;

				}
				//printf("iRowIndex : %d\n",iRowIndex);
				//printf("iColIndex : %d\n",iColIndex);
				SDL_Delay(100);
				KTP_InGameRender(bRadar);
			}
		}

		if (bDJKIsMoving == false && bMSHIsMoving == false && Curtime - Oldtime > 1000)
		{
			iDJKRadarIndex = rand() % 5;
			iMSHRadarIndex = rand() % 5;
			printf("djk index : %d\nmsh index : %d\n", iDJKRadarIndex, iMSHRadarIndex);
			DJ_KRect.x = 120 * (iDJKRadarIndex + 1);
			MSHRect.y = 100 * (iMSHRadarIndex + 1);
			DJ_KRadarRect.x = 120 * (iDJKRadarIndex + 1);
			MSHRadarRect.y = 100 * (iMSHRadarIndex + 1);
			bDJKIsMoving = true;
			bMSHIsMoving = true;
			KTP_SoundPlay(RADAR);
		}

		if (bDJKIsMoving == true && bMSHIsMoving == true)
		{
			bRadar = true;
			KTP_InGameRender(bRadar);
		}

		else
		{
			if (bRadar == true)
			{
				KTP_InGameRender(bRadar);
				bRadar = false;
				KTP_SoundStop(RADAR);
			}
		}

		if (Curtime - Oldtime > iChecktime && bDJKIsMoving == true && bMSHIsMoving == true)
		{
			printf("Phone Check!!\n");
			for(int i = 0; i < 5; i++)
			{
				if(bHavePhone[iDJKRadarIndex][i] == true)
				{
					printf("Phone Taken!!\n");
					KTP_SoundStop(GAMEBGM);
					SDL_Delay(1000);

					KTP_SoundPlay(GAMEOVER);
					KTP_InGameRenderGameOver();
					KTP_SoundStop(GAMEOVER);

					bHavePhone[iRowIndex][iColIndex]=false;
					KTP_InGameRenderRelease();
					
					printf("Score : %d\n", iScore);
					return;
				}
			}
			for(int j = 0; j < 5; j++)
			{
				if(bHavePhone[j][iMSHRadarIndex] == true)
				{
					printf("Phone Taken!!\n");
					KTP_SoundStop(GAMEBGM);
					SDL_Delay(1000);

					KTP_SoundPlay(GAMEOVER);
					KTP_InGameRenderGameOver();
					KTP_SoundStop(GAMEOVER);

					bHavePhone[iRowIndex][iColIndex]=false;
					KTP_InGameRenderRelease();

					printf("Score : %d\n", iScore);
					return;
				}
			}
			Oldtime = Curtime;
			bDJKIsMoving = false;
			bMSHIsMoving = false;
			iScore++;
			bRadar = true;
			if (iChecktime>=1100)
			{
				iChecktime -= 20;
			}
			printf("iChecktime : %d\n",iChecktime);
			printf("Score : %d\n",iScore);
		}
		KTP_InGameRender(bRadar);
		KTP_SoundUpdate();
	}
}
