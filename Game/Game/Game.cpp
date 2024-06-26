#include "Game.h"

SDL_Texture* player_red_texture;
SDL_Texture* player_blue_texture;
SDL_Rect player_blue;
SDL_Rect player_red;

Game::Game()
{

}

Game::~Game()
{

}

void Game::init(const char* title, int width, int height, bool fullscreen)
{
	int flags = 0;

	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
		renderer = SDL_CreateRenderer(window, -1, 0);

		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		}

		isRunning = true;
	}
}

void Game::handleEvents()
{
	SDL_Event event;

	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}

void Game::update(int window_width, int window_height)
{
	
	player_blue.w = 32 * window_height / 480;
	player_blue.h = 32 * window_height  /480;
	player_blue.x = window_width / 2 - player_blue.w / 2 - 150;
	player_blue.y = window_height / 2 - player_blue.w / 2;

	player_red.w = 32;
	player_red.h = 32;
	player_red.x = window_width / 2 - player_red.w / 2 + 150;
	player_red.y = window_height / 2 - player_red.w / 2;

	SDL_Surface* tmpSurface_red_player = IMG_Load("assets/player_red.png");
	SDL_Surface* tmpSurface_blue_player = IMG_Load("assets/player_blue.png");
	player_red_texture = SDL_CreateTextureFromSurface(renderer, tmpSurface_red_player);
	player_blue_texture = SDL_CreateTextureFromSurface(renderer, tmpSurface_blue_player);
	SDL_FreeSurface(tmpSurface_red_player);
	SDL_FreeSurface(tmpSurface_blue_player);
}

void Game::render()
{
	


	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, player_blue_texture, NULL, &player_blue);
	SDL_RenderCopy(renderer, player_red_texture, NULL, &player_red);
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}