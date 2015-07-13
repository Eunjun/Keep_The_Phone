#include "common.h"
#include "KTP_Menu.h"
#include "KTP_Sound.h"

//#pragma comment(lib, "SDL2main.lib")
#pragma comment(lib, "SDL2.lib")
#pragma comment(lib, "SDL2_image.lib")
#pragma comment(lib, "fmodex_vc.lib")

#undef main

SDL_Window * g_Window = nullptr;
SDL_Renderer *g_Renderer = nullptr;

void Init();

void Release();

int main(int argc, char *argv[])
{
	Init();

	KTP_Menu();
	
	Release();

	return 0;
}

void Init()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	g_Window = SDL_CreateWindow("Keep The Phone!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
	g_Renderer = SDL_CreateRenderer(g_Window, 0, -1);
	SDL_RenderClear(g_Renderer);

	SDL_Surface * pScreenSurface = SDL_GetWindowSurface(g_Window);
	SDL_Surface * pBGImage = IMG_Load("./Image/Loading.png");
	SDL_BlitSurface(pBGImage, NULL, pScreenSurface, NULL);
	SDL_UpdateWindowSurface(g_Window);

	KTP_SoundInit();
}

void Release()
{
	KTP_SoundRelease();
	SDL_DestroyRenderer(g_Renderer);
	SDL_DestroyWindow(g_Window);
	SDL_Quit();
}

