// game.cpp
/*
Finished_Add gold to game-- gold_reward was added in Map.  It is the first parameter for each monster
Multiple Enemies
Items
Store 566 pg182
Random encounters during rest
Magic points 564 pg 181
Modify leveling up so that wizards get more mana and warriors get more strength


Add #include <stdlib.h> // system("CLS"); to clear screen
*/
#include "Map.h"
#include "Player.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int main()
{
	srand( time(0) );
	// Class objects
	Map gameMap; 

	Player mainPlayer;

	mainPlayer.createClass();

	// Begin adventure.
	bool done = false;
	while( !done )
	{
		// Each loop cycly we output the player position and 
		// a selection menu.

		gameMap.printPlayerPos();
	
		int selection = 1;
		cout << "1) Move, 2) Rest, 3) View Stats, 4) Quit: ";
		cin >> selection;

		Monster* monster = 0;
		switch( selection )
		{
		case 1:
			gameMap.movePlayer();

			// Check for a random encounter.  This function
			// returns a null pointer if no monsters are
			// encountered.
			monster = gameMap.checkRandomEncounter();

			// 'monster' not null, run combat simulation.
			if( monster != 0 )
			{
				
				// Loop until a 'break' statement.
				while( true )
				{
					// Display hitpoints.
					mainPlayer.displayHitPoints();
					monster->displayHitPoints();
					cout << endl;

					// Player's turn to attack first.
					bool runAway = mainPlayer.attack(*monster);

					if( runAway )
						break;

					if( monster->isDead() )
					{
						mainPlayer.victory(monster->getXPReward(),monster->get_goldreward());
						mainPlayer.levelUp();
						
						// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
						break;
					}

					monster->attack(mainPlayer);

					if( mainPlayer.isDead() )
					{
						mainPlayer.gameover();
						done = true;
						break;
					}
				}

				// The pointer to a monster returned from
				// checkRandomEncounter was allocated with
				// 'new', so we must delete it to avoid
				// memory leaks.
				delete monster;
				monster = 0;
			}

			break;
		case 2:
			mainPlayer.rest();
			break;
		case 3:
			mainPlayer.viewStats();
			break;
		case 4:
			done = true;
			break;
		}
	}	
}