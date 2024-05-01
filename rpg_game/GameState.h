#pragma once

#include "State.h"

class GameState:
	public State
{
private:
	Entity player;

public:
	GameState(sf::RenderWindow* window);

	~GameState();

	//Functions 
	void end_state(); // End the state
	void update_keybinds(const float& dt); // Update the keybinds of the player 
	void update(const float dt); // Update the state
	void render(sf::RenderTarget* target = NULL);  // Render the state


};

