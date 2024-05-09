#include "Entity.h"

Entity::Entity()
{
	this->shape.setFillColor(sf::Color::White); // Set the color of the shape to white
	this->shape.setSize(sf::Vector2f(50.f, 50.f)); // Set the size of the shape to 50x50
	this->movement_speed = 100.f; // Set the movement speed to 100
}

Entity::~Entity()
{

}

void Entity::move(const float& dt, const float direction_x, const float direction_y) // Function to move the shape
{
	this->shape.move(direction_x * this->movement_speed * dt, direction_y * this->movement_speed * dt); // Move the shape by the x and y values multiplied by the movement speed and the delta time
}

void Entity::update(const float& dt)
{
	
}

void Entity::render(sf::RenderTarget* target)
{
	target->draw(this->shape); // Draw the shape
}
