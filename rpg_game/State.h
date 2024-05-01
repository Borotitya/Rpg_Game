#pragma once

#include "Entity.h"

class State
{
private:

protected:
	sf:: RenderWindow* window; // Pointer to a window
	std::vector<sf::Texture> textures; // Vector of textures 
	bool quit;


public: 
	State(sf::RenderWindow* window);
	virtual ~State();

	const bool& get_quit() const; // Get the quit variable
	virtual void check_for_quit(); // Pure virtual function 

	virtual void end_state() = 0;
	virtual void update_keybinds(const float& dt) = 0;
	virtual void update(const float dt) = 0; // Pure virtual function
	virtual void render(sf::RenderTarget* target = nullptr) = 0; // Pure virtual function
};

