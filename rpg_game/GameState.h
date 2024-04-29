#pragma once

#include "State.h"

class GameState:
	public State
{
private:

public:
	GameState(sf::RenderWindow* window);

	~GameState();

	//Functions 
	void end_state();
	void update(const float dt);
	void render(sf::RenderTarget* target = nullptr);

};

