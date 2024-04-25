#include "Game.h"


//Static Functions 

//Initialiser Functions
void Game::init_window()
{
	this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "RPG Game");
}

//Constructors / Destructors
Game::Game() {

	this->init_window();
}

Game::~Game() {

	delete this->window;
}

// Function Realisation 
void Game::update_sfml_events()
{
	while (this->window->pollEvent(this->sfml_event))
	{
		if(this->sfml_event.type == sf::Event::Closed)
			this->window->close();
	}
}

void Game::update()
{
	this->update_sfml_events();
}

void Game::render()
{
	this->window->clear();

	//Render items

	this->window->display();
}

void Game::run()
{
	while (this->window->isOpen())
	{
		this->update_sfml_events();
		this->update();
		this->render();
	}
}
