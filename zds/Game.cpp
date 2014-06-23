#include "Game.h"

Game::Game()
{
	logger.write("Game Initilization..");

	this->running = gameInitialize();

	gameLoop();
}

bool Game::gameInitialize()
{
	this->SCREEN_WIDTH = 640;
	this->SCREEN_HEIGHT = 480;

	this->window = NULL;
	this->screenSurface = NULL;
	logger.write("Screen width and height set..");

	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		logger.write("failed to initialize SDL!");
		return false;
	}
	
	else
	{
		logger.write("SDL Initialized..");

		window = SDL_CreateWindow("ZDS", SDL_WINDOWPOS_UNDEFINED, 
			SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

		if(window == NULL)
		{
			logger.write("Failed to create a window!");
			return false;
		}

		else
		{	
			logger.write("Window created..");

			int imgFlags = IMG_INIT_PNG;
			if (!(IMG_Init( imgFlags) &imgFlags))
			{
				logger.write("Failed to load SDL_Image!");
			}
			else
			{
				screenSurface = SDL_GetWindowSurface( window );
				logger.write("Loaded surface to window..");
			}
			
		}
	}

	if(!loadMedia())
	{
		logger.write("Failed to load media!");
		return false;
	}
	else
	{
		logger.write("Successfully loaded media..");
	}

	logger.write("Game initialized!");
	return true;
}

bool Game::loadMedia()
{
	this->background = NULL;

	SDL_Surface* loadedImage = IMG_Load("back.png");

	if(loadedImage == NULL)
	{
		logger.write("Failed to load image!");
		return false;
	}

	else
	{
		logger.write("Successfully loaded image..");
		background = SDL_ConvertSurface(loadedImage, screenSurface->format, NULL);
		if(background == NULL)
		{
			logger.write("Failed to optimize image");
			return false;
		}

		SDL_FreeSurface(loadedImage);
	}

	return true;
}

void Game::gameInput()
{
	while(SDL_PollEvent(&e) != 0)
	{
		if(e.type == SDL_QUIT)
		{
			running = false;
		}
	}

}

void Game::gameRender()
{
	SDL_BlitSurface(background, NULL, screenSurface, NULL);
	SDL_UpdateWindowSurface(window);
}

void Game::gameLoop()
{
	while(running)
	{
		gameInput();
		gameRender();
	}
}

Game::~Game()
{	
	SDL_FreeSurface(background);
	background = NULL;
	SDL_DestroyWindow(window);
	window = NULL;
	SDL_Quit();
}
