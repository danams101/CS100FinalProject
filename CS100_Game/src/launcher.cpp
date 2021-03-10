#include "stdafx.h"
#include "Game.h"

// PROPER LIBRARIES PER OS
#ifdef _WIN32
#include <Windows.h>
#endif

int main()
{
  Game game;
	
  game.run();
	
	return 0;
}
