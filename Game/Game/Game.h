#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include <string.h>
#include <Windows.h>

class Game
{
public:
	Game();
	~Game();

	void init(const char* title, int width, int height, bool fullscreen);

	void texture_loader();
	void handleEvents();
	void update(int width, int height, int cnt);
	bool running() { return isRunning; }
	void render();
	void clean();
	void img_loader(std::string entity);
private:

	std::string entity;
	bool isRunning = false;
	int cnt = 0;
	SDL_Window* window;
	SDL_Renderer* renderer;
};

