#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "SFML/Network.hpp"

class Game
{
private:
		//Variables
	sf::RenderWindow* window;
	sf::Event sfml_event;

	//Initializations 
	void init_window();
public:
	//Constructors / Destructors
	Game();
	virtual ~Game();

	//Functions 
	void update_sfml_events();
	void update();
	void render();
	void run();	
};

