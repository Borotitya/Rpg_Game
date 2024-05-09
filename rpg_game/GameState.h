#pragma once

#include "State.h"

class GameState:
	public State
{
private:
	Entity player;

	//Functions 
	void init_keybinds(); // Initialise the keybinds

public:
	GameState(sf::RenderWindow* window, std::map<std::string, int>* supported_keys); // Constructor with parameters 

	virtual ~GameState(); // Destructor 

	//Functions 
	void end_state(); // End the state
	void update_input(const float& dt); // Update the input of the state 
	void update(const float dt); // Update the state
	void render(sf::RenderTarget* target = NULL);  // Render the state
};

