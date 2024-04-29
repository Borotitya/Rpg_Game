#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "SFML/Network.hpp"

#include <stack> // Stack 
#include<map> // Map 
#include<fstream> // File stream
#include<sstream> // String stream
#include<ctime> // Time
#include<cstdlib> // Random
#include<iostream> // Input and output
#include<vector> // Vector

class State
{
private:
	sf:: RenderWindow* window; // Pointer to a window
	std::vector<sf::Texture*> textures; // Vector of textures 


public: 
	State(sf::RenderWindow* window);
	virtual ~State();

	virtual void end_state() = 0; // Pure virtual function
	virtual void update(const float dt) = 0; // Pure virtual function
	virtual void render(sf::RenderTarget* target = nullptr) = 0; // Pure virtual function
};

