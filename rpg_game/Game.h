#pragma once

#include"GameState.h"

class Game
{
private:
		//Variables
	sf::RenderWindow* window; //Pointer to a window
	sf::Event sfml_event; //Event variable
	sf::Clock dtClock; // Clock variable for delta time 
	float dt; // Delta time variable

	std::stack<State*> states; // Stack of pointers to the base class State

	std::map<std::string, int> supported_keys; // Map of supported keys

	//Initializations 
	void init_window();  // Initialise the window
	void init_states(); // Initialise the states
	void init_keys(); // Initialize the supported keys
public:
	//Constructors / Destructors
	Game();
	virtual ~Game(); // Virtual keyword is used to make sure that the destructor is called when the object is deleted

	//Functions 
	
	//Regular
	void end_application(); // End the application

	//Update functions
	void update_dt(); // Update delta time
	void update_sfml_events(); // Update SFML events
	void update();// Update the game

	//Render function
	void render(); // Render the game

	//Core 
	void run();	 // Run the game
};

