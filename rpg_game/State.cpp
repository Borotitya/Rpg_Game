#include "State.h"

State::State(sf::RenderWindow* window, std::map<std::string, int>* supported_keys) // Constructor with parameters
{
	this->window = window; // Set the window to the window passed in
	this->supported_keys = supported_keys; // Set the supported keys to the supported keys passed in
	this->quit = false; // Set the quit to false
}

State::~State()
{
}

const bool& State::get_quit() const
{
	return this->quit; // Return the quit
}

void State::check_for_quit()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE")))) { // If escape is pressed
		this->quit = true; // Quit if escape is pressed
	}
}
