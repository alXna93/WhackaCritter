//------------------------------
// INCLUDED IN PROJECT
//-----------------------------
#include "Critter.h"

//------------------------------
// INCLUDED LIBRARIES
//------------------------------
#include <cstdlib>


Critter::Critter()
//initialisation list
	: m_sprite()
	, m_texture()
	, m_alive(true)
	, m_deathSound()
	, m_deathBuffer()
{
	//set up sprite
	m_texture.loadFromFile("graphics/whale.png");
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(	rand() % sf::VideoMode::getDesktopMode().width, 
							rand() % sf::VideoMode::getDesktopMode().height );

	m_deathBuffer.loadFromFile("audio/buttonclick.ogg");
	m_deathSound.setBuffer(m_deathBuffer);

}

void Critter::Draw(sf::RenderTarget& _target)
{
	// only draw sprite if alive
	if (m_alive)
	{
		_target.draw(m_sprite);
	}

}


void Critter::Input(sf::Event _gameEvent)
{
	//onliy handle input if alive
	if (m_alive)
	{
	
	//check if this event is a click
	if (_gameEvent.type == sf::Event::MouseButtonPressed)
	{

		// Did they click on this critter?
		if (m_sprite.getGlobalBounds().contains(_gameEvent.mouseButton.x, _gameEvent.mouseButton.y))
		{
			//they clicked it!
			m_alive = false;

			m_deathSound.play();
		}

	} //endif
}
	}	