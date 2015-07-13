#include "common.h"
#include "KTP_InGame.h"
#include "KTP_Credit.h"
#include "KTP_Sound.h"


extern SDL_Window * g_Window;
extern SDL_Renderer * g_Renderer;

SDL_Event Menu;

void KTP_Menu()
{
	printf("KTP_Menu\n");

	SDL_Surface * pScreenSurface = SDL_GetWindowSurface(g_Window);
	SDL_Surface * pBGImage;

	pBGImage = IMG_Load("./Image/BackgroundMenu.png");
	SDL_BlitSurface(pBGImage, NULL, pScreenSurface, NULL);
	
	KTP_SoundPlay(MENUBGM);

	while (1)
	{
		SDL_UpdateWindowSurface(g_Window);
		
		while(SDL_PollEvent(&Menu))
		{
			if (Menu.type == SDL_KEYDOWN)
			{
				KTP_SoundPlay(KEYEFFECT);
				switch (Menu.key.keysym.sym)
				{
				case SDLK_1:
					printf("SDLK_1 PUSH!\n");
					KTP_SoundStop(MENUBGM);
					KTP_InGame();
					KTP_SoundPlay(MENUBGM);
					break;

				case SDLK_2:
					printf("SDLK_2 PUSH!\n");
					KTP_Credit();
					break;

				case SDLK_ESCAPE:
					printf("SDLK_ESCAPE PUSH!\n");
					KTP_SoundStop(MENUBGM);
					SDL_FreeSurface(pBGImage);
					SDL_FreeSurface(pScreenSurface);
					return;

				default:
					break;
				}
				SDL_BlitSurface(pBGImage, NULL, pScreenSurface, NULL);

			}
		}
		KTP_SoundUpdate();
	}
	

}


