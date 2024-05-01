#include "State.h"

State::State(sf::RenderWindow* window)
{
	this->window = window; // Set the window to the window passed in
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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) { // If escape is pressed
		this->quit = true; // Quit if escape is pressed
	}
}
