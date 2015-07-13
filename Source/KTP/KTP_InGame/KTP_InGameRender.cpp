#include "common.h"

extern SDL_Window * g_Window;
extern SDL_Renderer * g_Renderer;
extern bool bDJKIsMoving;
extern bool bMSHIsMoving;

SDL_Rect StudentRect [5][5];
SDL_Rect PhoneRect	= {145,105,30,50};
SDL_Rect DJ_KRect	= {120,20,80,80};
SDL_Rect MSHRect	= {680,500,80,80};

SDL_Rect DJ_KRadarRect= {120,100,80,480};
SDL_Rect MSHRadarRect = {120,100,580,80};

SDL_Rect DangerRect = {20,100,100,420};

SDL_Surface * pScreenSurface;
SDL_Surface * pBGImage;
SDL_Surface * pStudentImage;
SDL_Surface * pPhoneImage;
SDL_Surface * pDJ_KImage;
SDL_Surface * pMSHImage;
SDL_Surface * pDRadarImage;
SDL_Surface * pMRaderImage;
SDL_Surface * pDangerImage;

void KTP_InGameRenderInit()
{
	printf("KTP_InGameRenderInit\n");
	pScreenSurface = SDL_GetWindowSurface(g_Window);
	pBGImage = IMG_Load("./Image/BackgroundGame.png");
	pStudentImage = IMG_Load("./Image/Student.png");
	pPhoneImage = IMG_Load("./Image/Phone.png");

	pDJ_KImage = IMG_Load("./Image/DJ_K.png");
	pMSHImage = IMG_Load("./Image/MSH.png");

	pDRadarImage = IMG_Load("./Image/DJ_KRadar.png");
	pMRaderImage = IMG_Load("./Image/MSHRadar.png");

	pDangerImage = IMG_Load("./Image/danger.png");

	StudentRect[0][0].x=15;
	StudentRect[0][0].y=15;

	PhoneRect.x = 145; 
	DJ_KRect.x = 120;
	MSHRect.x = 680;
	PhoneRect.y = 105; 
	DJ_KRect.y = 20;
	MSHRect.y = 500;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			StudentRect[i][j].w = 80;
			StudentRect[i][j].h = 80;
			StudentRect[i][j].x = (StudentRect[i][0].x*j) + StudentRect[i][j].w + 40;
			StudentRect[i][j].y = (StudentRect[0][j].y*i) + StudentRect[i][j].h + 20;
			printf("[%d][%d]x: %d	y : %d\n", i, j, StudentRect[i][j].x, StudentRect[i][j].y);
		}
	}
}

void KTP_InGameRenderPhone()
{
	SDL_BlitSurface(pPhoneImage, NULL, pScreenSurface, &PhoneRect);
}

void KTP_InGameRenderTeacher()
{
	SDL_BlitSurface(pDJ_KImage, NULL, pScreenSurface, &DJ_KRect);
	SDL_BlitSurface(pMSHImage, NULL, pScreenSurface, &MSHRect);
}

void KTP_InGameRenderRadar()
{
	SDL_BlitSurface(pDRadarImage, NULL, pScreenSurface, &DJ_KRadarRect);
	SDL_BlitSurface(pMRaderImage, NULL, pScreenSurface, &MSHRadarRect);
}

void KTP_InGameRenderDanger()
{
	SDL_BlitSurface(pDangerImage, NULL, pScreenSurface, &DangerRect);
}

void KTP_InGameRender(bool Radar)
{
	//printf("KTP_InGameRender\n");

	SDL_BlitSurface(pBGImage, NULL, pScreenSurface, NULL);
	
	

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5;  j++)
		{
			SDL_BlitSurface(pStudentImage, NULL, pScreenSurface, &StudentRect[i][j]);
		}
	}
	if (Radar)
	{
		KTP_InGameRenderRadar();
	}
	KTP_InGameRenderDanger();
	KTP_InGameRenderTeacher();
	KTP_InGameRenderPhone();
	SDL_UpdateWindowSurface(g_Window);	
}


void KTP_InGameRenderRelease()
{
	printf("KTP_InGameRenderRelease\n");
	SDL_FreeSurface(pBGImage);
	SDL_FreeSurface(pStudentImage);
	SDL_FreeSurface(pDJ_KImage);
	SDL_FreeSurface(pMSHImage);
	SDL_FreeSurface(pScreenSurface);
}

void KTP_InGameRenderGameOver()
{
	SDL_Surface * pScreenSurface = SDL_GetWindowSurface(g_Window);
	SDL_Surface * pBGImage;

	printf("---------game over---------\n\n\n");

	pBGImage = IMG_Load("./Image/BackgroundGameOver.png");
	SDL_BlitSurface(pBGImage, NULL, pScreenSurface, NULL);

	while (1)
	{
		SDL_Event iGameover;
		SDL_PollEvent(&iGameover);
		SDL_UpdateWindowSurface(g_Window);
		if (iGameover.key.keysym.sym == SDLK_ESCAPE)
		{
			SDL_FreeSurface(pBGImage);
			SDL_FreeSurface(pScreenSurface);
			SDL_UpdateWindowSurface(g_Window);
			return;
		}
	}
}



