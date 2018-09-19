#pragma once
//------------------------------
// INCLUDED LIBRARIES
//------------------------------
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


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

	//process input on the critter
	void Input(sf::Event _gameEvent);




	//---------------------------
	// END BEHAVIOUR

	//---------------------------
	// DATA
	//---------------------------

private:

	sf::Sprite m_sprite;
	sf::Texture m_texture;
	bool m_alive;
	sf::Sound m_deathSound;
	sf::SoundBuffer m_deathBuffer;

	//---------------------------
	// END DATA




}; //end critter class
