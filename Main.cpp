//------------------------------
// INCLUDED LIBRARIES
//------------------------------
#include <SFML/Graphics.hpp>
#include <cstdlib> //gives access to random fucntion
#include <ctime> //gives access to time function
#include <string> //gives access to string function

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
	Whaley.Setup("graphics/whale.png", 5);
	Critter Russ;
	Russ.Setup("graphics/walrus.png", 10);

	//game font
	sf::Font gameFont;
	gameFont.loadFromFile("fonts/mainFont.ttf");

	//score tracking
	int score = 0;
	sf::Text scoreText;
	scoreText.setFont(gameFont);
	scoreText.setString("Score:  " + std::to_string(score));
	scoreText.setCharacterSize(50);
	scoreText.setFillColor(sf::Color::Cyan);
	scoreText.setPosition(50, 50);


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
			//Process inout on critters
			Whaley.Input(event);
			Russ.Input(event);

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

		// See if there is any pending score
		score += Whaley.GetPendingScore();
		Whaley.ClearPendingScore();
		scoreText.setString("Score:  " + std::to_string(score));
		
		//second critter
		score += Russ.GetPendingScore();
		Russ.ClearPendingScore();
		scoreText.setString("Score:  " + std::to_string(score));

			//end update
			//---------------------------------


			//---------------------------------
			// DRAW
			//---------------------------------


			//clear window to single colour
			gameWindow.clear();

		//draw everything
			Whaley.Draw(gameWindow);
			Russ.Draw(gameWindow);
			gameWindow.draw(scoreText);

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
