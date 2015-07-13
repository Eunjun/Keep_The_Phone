#include "common.h"

extern SDL_Window * g_Window;
extern SDL_Renderer * g_Renderer;

void KTP_Credit()
{
	printf("KTP_Credit\n");

	SDL_Surface * pScreenSurface = SDL_GetWindowSurface(g_Window);
	SDL_Surface * pBGImage;

	pBGImage = IMG_Load("./Image/BackgroundCredit.png");
	SDL_BlitSurface(pBGImage, NULL, pScreenSurface, NULL);

	while (1)
	{
		SDL_Event iCredit;
		SDL_PollEvent(&iCredit);
		SDL_UpdateWindowSurface(g_Window);
		if (iCredit.type == SDL_KEYDOWN)
		{
			puts("Credit_returned!");
			SDL_FreeSurface(pBGImage);
			SDL_FreeSurface(pScreenSurface);
			return;
		}
	}
}
