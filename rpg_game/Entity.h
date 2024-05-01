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
class Entity
{
private:

protected:
	sf::RectangleShape shape; // Entity shape 
	float movement_speed; // Movement speed 

public:
	Entity();

	virtual ~Entity();

	//Functions 
	virtual void move(const float& dt, const float x, const float y);
	virtual void update(const float& dt); 
	 virtual void render(sf::RenderTarget* target);
};

