#pragma once
//------------------------------
// INCLUDED LIBRARIES
//------------------------------
#include <SFML/Graphics.hpp>


class Critter
{

	//---------------------------
	// BEHAVIOUR
	//---------------------------

public:

	//Constructor
	Critter();

	//Render critter to target
	void Draw(sf::RenderTarget& _target);



	//---------------------------
	// END BEHAVIOUR

	//---------------------------
	// DATA
	//---------------------------

private:

	sf::Sprite m_sprite;
	sf::Texture m_texture;

	//---------------------------
	// END DATA




}; //end critter class
