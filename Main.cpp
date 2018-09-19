//------------------------------
// INCLUDED LIBRARIES
//------------------------------
#include <SFML/Graphics.hpp>
#include <cstdlib> //gives access to random fucntion
#include <ctime> //gives access to time function

//------------------------------
// INCLUDED IN PROJECT
//------------------------------
#include "Critter.h"

int main()
{

	//----------------------------------------------
	//GAME SETUP
	//----------------------------------------------
	sf::RenderWindow gameWindow;
	gameWindow.create(sf::VideoMode::getDesktopMode(), "WhackaCritter",
	sf::Style::Titlebar | sf::Style::Close);

	//Timer function
	sf::Clock gameClock;

	//seed our random number generator
	srand(time(NULL));

	//create instance of critter class
	Critter Whaley;

	//end game setup

	//------------------------------------------------
	// GAME LOOP
	//------------------------------------------------

	while (gameWindow.isOpen())
	{
		//--------------------------------------------
		// INPUT
		//--------------------------------------------

		sf::Event event;
		while (gameWindow.pollEvent(event))
		{


			if (event.type == sf::Event::Closed)
			{
				gameWindow.close();
			}//endif
		}//end event polling loop



	// END INPUT
	//-------------------------------------


	//--------------------------------------
	// UPDATE
	//--------------------------------------
		sf::Time frameTime = gameClock.restart();

			//end update
			//---------------------------------


			//---------------------------------
			// DRAW
			//---------------------------------


			//clear window to single colour
			gameWindow.clear();

		//draw everything
			Whaley.Draw(gameWindow);

		//display window contents to screen
		gameWindow.display();

		//---------------------------------
		//end draw
		//--------------------------------

	} //end of game while loop
	//end of game loop
	//-----------------------------------


	//exit point of program
	return 0;
} //end of main function()
