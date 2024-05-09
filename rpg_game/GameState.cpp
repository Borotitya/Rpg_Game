#include "GameState.h"

// Constructor 
GameState::GameState(sf::RenderWindow* window, std::map<std::string, int>* supported_keys)
	: State(window, supported_keys) // Call the State constructor with the window and supported keys passed in
{
  this->init_keybinds(); // Initialize the keybinds
}

// Destructor
GameState::~GameState()
{
}

void GameState::end_state()
{
	std::cout << "Ending GameState" << std::endl; // Output to the console that the game state is ending
}

void GameState::init_keybinds() { // Initialize the keybinds
	std::ifstream ifs("D:\\projectC++\\GameDemo\\rpgGame\\rpg_game\\rpg_game\\gamestate_keys.ini"); // Open the file gamestate_keys.ini
	if (ifs.is_open()) {  // If the file is open
		std::string key = "";  // Create a string variable called key
		std::string key2 = ""; // Create a string variable called key2
		while (ifs >> key >> key2) {  // While the file is not at the end
			this->keybinds[key] = this->supported_keys->at(key2);  // Add the key and value to the map keybinds with the value of key2 from the map supported_keys 
		}
	}
	ifs.close(); // Close the file
}

void GameState::update_input(const float& dt) // 
{
	this->check_for_quit(); // Check for the quit event

	// Update player input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_LEFT"))))	// If the A key is pressed
		this->player.move(dt, -1.f, 0.f); // Move the shape left
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_RIGHT"))))	// If the D key is pressed
		this->player.move(dt, 1.f, 0.f); // Move the shape right
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_UP"))))	// If the W key is pressed
		this->player.move(dt, 0.f, -1.f); // Move the shape up
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_DOWN"))))	// If the S key is pressed
		this->player.move(dt, 0.f, 1.f); // Move the shape down
}

void GameState::update(const float dt)
{
	this->update_input(dt); // Update the keybinds with the delta time variable 
	this->player.update(dt); // Update the player with the delta time variable
}

void GameState::render(sf::RenderTarget* target)
{
	if(!target)
		target = this->window; // If the target is not set, set it to the window
	this->player.render(this->window); // Render the player to the window passed in the function call 
}
