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
	std::cout << "Ending GameState" << std::endl;
}

void GameState::update_keybinds(const float& dt)
{
	this->check_for_quit();
}

void GameState::update(const float dt)
{
	this->update_keybinds(dt);
	this->player.update(dt);
}

void GameState::render(sf::RenderTarget* target)
{
	this->player.render(this->window);
}
