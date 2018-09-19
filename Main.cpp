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


	const int NUM_CRITTERS = 5;
	Critter critters[NUM_CRITTERS];
	critters[0].Setup("graphics/whale.png", 5);
	critters[1].Setup("graphics/walrus.png", 10);
	critters[2].Setup("graphics/sloth.png",15);
	critters[3].Setup("graphics/moose.png", 20);
	critters[4].Setup("graphics/elephant.png", 25);

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
		
			for (int i = 0; i < NUM_CRITTERS; ++i)
			{
				critters[i].Input(event);
			}

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

		for (int i = 0; i < NUM_CRITTERS; ++i)
		{
			score += critters[i].GetPendingScore();
			critters[i].ClearPendingScore();
		}

		
		
		scoreText.setString("Score:  " + std::to_string(score));
		
	
			//end update
			//---------------------------------


			//---------------------------------
			// DRAW
			//---------------------------------


			//clear window to single colour
			gameWindow.clear();

		//draw everything

			for (int i = 0; i < NUM_CRITTERS; ++i)
			{
				critters[i].Draw(gameWindow);
			}

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
