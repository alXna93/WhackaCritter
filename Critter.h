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

	//getter for pending score data
	int GetPendingScore();

	//clear pending score
	void ClearPendingScore();

	// Set critter type
	void Setup(std::string _textureFile, int _pointValue);

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
	int m_pendingScore;
	int m_scoreValue;

	//---------------------------
	// END DATA




}; //end critter class
