#include "Game.h"

//Create SDL Rectangles and textures

SDL_Texture* player_texture;
SDL_Texture* enemy_texture;
SDL_Texture* background_texture;

SDL_Rect background_rect;
SDL_Rect player_rect;
SDL_Rect enemy_rect;

Game::Game()
{

}

Game::~Game()
{

}

//Window constructor
void Game::init(const char* title, int width, int height, bool fullscreen)
{
	int flags = 0;

	//if full-screen mode on set fullscreen arg in constructor to SDL one
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	//Create window
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
		renderer = SDL_CreateRenderer(window, -1, 0);

		//draw white background
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		}

		//set game main loop flag to true
		isRunning = true;
	}
}

void Game::texture_loader()
{
	img_loader("background");
	img_loader("player");
	img_loader("enemy");
}

//window events handler
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

//updates game status and textures
void Game::update(int window_width, int window_height, int cnt)
{
	background_rect.w = window_width / 480;
	background_rect.h = window_height / 480;
	background_rect.x = window_width/2 - background_rect.w / 2;
	background_rect.y = window_height / 2 - background_rect.h / 2;
	
	player_rect.w = 32 * window_height / 480;
	player_rect.h = 32 * window_height  /480;
	player_rect.x = window_width / 2 - player_rect.w / 2 - 150 + cnt;
	player_rect.y = window_height / 2 - player_rect.w / 2;

	enemy_rect.w = 32 * window_height / 480;
	enemy_rect.h = 32 * window_height / 480;
	enemy_rect.x = window_width / 2 - enemy_rect.w / 2 + 150;
	enemy_rect.y = window_height / 2 - enemy_rect.w / 2 + 30;

	
	std::cout << cnt << std::endl;
}

//Renders the set game view
void Game::render()
{

	SDL_RenderCopy(renderer, background_texture, NULL, NULL);
	SDL_RenderCopy(renderer, player_texture, NULL, &player_rect);
	SDL_RenderCopy(renderer, enemy_texture, NULL, &enemy_rect);
	SDL_RenderPresent(renderer);
	SDL_RenderClear(renderer);
}

//closing window and operations trace
void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

void Game::img_loader(std::string entity)
{
	std::string temp_s;
	temp_s = "assets/" + entity + ".png";
	
	if (entity == "player")
	{
		SDL_Surface* tmpSurface_player = IMG_Load(temp_s.c_str());
		player_texture = SDL_CreateTextureFromSurface(renderer, tmpSurface_player);
		SDL_FreeSurface(tmpSurface_player);
	}
	else if (entity == "enemy") 
	{
		SDL_Surface* tmpSurface_enemy = IMG_Load(temp_s.c_str());
		enemy_texture = SDL_CreateTextureFromSurface(renderer, tmpSurface_enemy);
		SDL_FreeSurface(tmpSurface_enemy);
	}
	else if (entity == "background")
	{
		SDL_Surface* tmpSurface_background = IMG_Load(temp_s.c_str());
		background_texture = SDL_CreateTextureFromSurface(renderer, tmpSurface_background);
		SDL_FreeSurface(tmpSurface_background);
	}
}

