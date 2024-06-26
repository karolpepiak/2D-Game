#include "Game.h"

Game* game = nullptr;



int main(int argc, char* argv[])
{
	int w_width = 0;
	int w_height = 0;
	int r_choice = 0;
	char f_choice = 0;
	bool fullscrean_mode = false;

	std::cout << "Set window resolution:\n" << "[1] 680x480\n" << "[2] 800x600\n" << "[3] 1024x768\n" << "[4] 1280x720\n" << "[5] 1280x1024\n" << "[6] 1366x768\n" << "[7] 1600x900\n" << "[8] 1920x1080\n";
	std::cin >> r_choice;
	switch (r_choice)
	{
	case 1:
		w_width = 680;
		w_height = 480;
		break;
	case 2:
		w_width = 800;
		w_height = 600;
		break;
	case 3:
		w_width = 1024;
		w_height = 768;
		break;
	case 4:
		w_width = 1280;
		w_height = 720;
		break;
	case 5:
		w_width = 1280;
		w_height = 1024;
		break;
	case 6:
		w_width = 1366;
		w_height = 768;
		break;
	case 7:
		w_width = 1600;
		w_height = 900;
		break;
	case 8:
		w_width = 1920;
		w_height = 1080;
		break;
	default:
		break;
	}
	std::cout << "Run Game in fullscrean mode? Yes[Y]/No[N]\n";
	std::cin >> f_choice;
	if (f_choice == 'Y' || f_choice == 'y')
	{
		fullscrean_mode = true;
	}
	else
	{
		fullscrean_mode = false;
	}



	game = new Game();
	game->init("GameWindow", w_width, w_height, fullscrean_mode);

	while (game->running())
	{
		game->handleEvents();
		game->update(w_width, w_height);
		game->render();
	}

	game->clean();
	return 0;
}