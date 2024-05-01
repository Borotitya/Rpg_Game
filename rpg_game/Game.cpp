#include "Game.h"

//Static Functions 

//Initialiser Functions
void Game::init_window()
{
	std::ifstream ifs("D:\\projectC++\\GameDemo\\rpgGame\\rpg_game\\rpg_game\\windiw.ini");

	std::string title = "None"; // Create a string variable called title
	sf::VideoMode window_bounds(800, 600); // Create a video mode object
	unsigned framerate_limit = 120; // Create an unsigned integer called framerate_limit
	bool vertical_sync_enabled = false; // Create a boolean called vertical_sync_enabled
	if (ifs.is_open()) { // If the file is open
		std::getline(ifs, title); // Get the title from the file
		ifs >> window_bounds.width >> window_bounds.height; // Get the width and height from the file
		ifs >> framerate_limit; // Get the framerate limit from the file
		ifs >> vertical_sync_enabled; // Get the vertical sync from the file
	}
	ifs.close(); // Close the file

	this->window = new sf::RenderWindow(window_bounds, title); // Create a window
	this->window->setFramerateLimit(framerate_limit); // Set the frame rate limit
	this->window->setVerticalSyncEnabled(vertical_sync_enabled); // Set the vertical sync to false
}

void Game::init_states()
{
	this->states.push(new GameState(this->window)); // Push a new game state onto the stack
}

//Constructors / Destructors
Game::Game() {

	this->init_window(); // Initialise the window
	this->init_states(); // Initialise the states
}

Game::~Game() {

	delete this->window; // Delete the window object

	while (!this->states.empty()) {
		delete this->states.top(); // Delete the top state
		this->states.pop(); // Remove the top state
	} 
}

// Function Realisation 
void Game::end_application() {

	std::cout << "Ending Application" << std::endl;
}

void Game::update_sfml_events()
{
	while (this->window->pollEvent(this->sfml_event)) // Polls the event and stores it in the sfml_event
	{
		if(this->sfml_event.type == sf::Event::Closed) // If the window is closed
			this->window->close(); // Close the window
	}
}

void Game::update_dt()
{
	/* Updates the delta time variable with the tine it takes to update and render one frame */

	this->dt = this->dtClock.restart().asSeconds(); // Update the delta time variable

}

void Game::update()
{
	this->update_sfml_events();

	if (!this->states.empty()) { // If the stack is not empty

		this->states.top()->update(this->dt); // Update the top state

		if (this->states.top()->get_quit()) { // If the top state is quit

			this->states.top()->end_state(); // End the top state
			delete this->states.top(); // Delete the top state
			this->states.pop(); // Remove the top state
		}
	}
	//Applicaion end
	else {
		this->end_application();
		this->window->close(); // Close the window if the stack is empty and there are no states in the stack
	}
}

void Game::render()
{
	this->window->clear();

	//Render items
	if(!this->states.empty())// If the stack is not empty
		this->states.top()->render(this->window); // Render the top state

	this->window->display();
}

void Game::run()
{
	while (this->window->isOpen())
	{
		this->update_dt(); // Update the delta time
		this->update_sfml_events();
		this->update();
		this->render();
	}
}
