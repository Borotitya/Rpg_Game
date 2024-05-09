#pragma once

#include "Entity.h"

class State
{
private:

protected:
	sf:: RenderWindow* window; // Pointer to a window
	std::map<std::string, int>* supported_keys; // Pointer to a map of supported keys
	std::map<std::string, int> keybinds; // Map of keybinds
	bool quit;

	//Resources
	std::vector<sf::Texture> textures; // Vector of textures 

	//Functions 
	virtual void init_keybinds() = 0; // Pure virtual function


public: 
	State(sf::RenderWindow* window, std::map<std::string, int>* supported_keys); // Constructor with parameters 
	virtual ~State();

	const bool& get_quit() const; // Get the quit variable
	virtual void check_for_quit(); // Pure virtual function 

	virtual void end_state() = 0;
	virtual void update_input(const float& dt) = 0;
	virtual void update(const float dt) = 0; // Pure virtual function
	virtual void render(sf::RenderTarget* target = nullptr) = 0; // Pure virtual function
};

