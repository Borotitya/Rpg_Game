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

	//Initializations 
	void init_window(); 
	void init_states();
public:
	//Constructors / Destructors
	Game();
	virtual ~Game(); // Virtual keyword is used to make sure that the destructor is called when the object is deleted

	//Functions 
	void update_dt(); // Update delta time
	void update_sfml_events(); // Update SFML events
	void update(); // Update the game
	void render(); // Render the game
	void run();	 // Run the game
};

