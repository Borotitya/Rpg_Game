#include "GameState.h"

// Constructor 
GameState::GameState(sf::RenderWindow* window)
	: State(window)
{
}

GameState::~GameState()
{
}

void GameState::end_state()
{
}

void GameState::update(const float dt)
{
	
}

void GameState::render(sf::RenderTarget* target)
{
	std::cout << "Rendering GameState" << std::endl;	
}
