#include "Character.h"
#include "Commands.h"
#include "world.h"
#include "Room.h"
#include "ItemStructure.h"
#include "Combat.h"
#include "Save and Load.h"
#include "Interface.h"
#include "Sound.h"
#include "Items.h"
#include <time.h>

int main()
{
	BackgroundSound(L"POL-mecha-world-short.wav");
	cout << " DDD      A      R R R  K   K   GGGGG U    U N      N \n"
		" D  D    A A     R   R  K  K    G     U    U N N    N \n"
		" D   D  A   A    R  R   K K     G     U    U N  N   N \n"
		" D   D A A A A   R R    K  K    G GGG U    U N   N  N \n"
		" D  D A       A  R   R  K   K   G   G U    U N    N N \n"
		" DDD A         A R    R K    K  GGGGG UUUUUU N     NN \n" << endl;
	
	string sInput;
	stringstream convertInput;
	int nKeyPress; // Holds the key pressed by the user
	bool bContinue = true;
	srand(time(NULL));
	Interface::GetInstance(); //create the instance of the interface, which loads in the world
	while ( bContinue )
	{
		// read a key here into nKeypress
		cout << " 1) New Game " << endl;
		cout << " 2) Load Game " << endl;
		cout << " 3) Credits " << endl;
		cout << " 4) Exit " << endl;
		cout << "\n What would you like to do? ";
		getline(cin, sInput);
		convertInput.str("");
		convertInput.clear();
		convertInput.str(sInput);
		while (!(convertInput >> nKeyPress))
		{
			convertInput.str("");
			convertInput.clear();
			cout << "Make sure to enter the NUMBER that is next to the option you want to choose: ";
			getline(cin, sInput);
			convertInput.str(sInput);
		}

		switch ( nKeyPress )
		{
		case 1:
			{cout << "\nNew game starting\n";
			PC->GenderNamePrompt();
			ability::AddAbilities();
			for (int i = 0; i < 0; i++)//Start level
				PC->LevelUp();
			WorldItems::SpawnItems();
			WorldItems::PlaceItems();
			Interface::GetInstance()->MainGame();}
			break;

		case 2:
			{cout << "\nYour game is loading\n";
			Load();
			ability::AddAbilities();
			WorldItems::SpawnItems();
			WorldItems::LoadItems();
			WorldItems::PlaceItems();
			Interface::GetInstance()->MainGame();}
			break;

		case 3:
			cout << "\nCredits\n";
			cout << "Storywriting: Joshua Silvers" << endl;
			cout << "World Design: Joshua Silvers" << endl;
			cout << "Level Design: Joshua Silvers" << endl;
			cout << "Engine Framework: Eric Huntzberry, Ashton Carr, & Cory Jacobs" << endl;
			cout << "Game Mechanics: Eric Huntzberry" << endl;
			cout << "Sound Framework: Ashton Carr" << endl;
			cout << "Combat: Walker Tatum & Eric Huntzberry" << endl;
			break;

		case 4:
			{exit(0);}
			break;

			//Other than 1, 2, 3, 4
		default : cout << "\n Invalid Selection ";
			// no break in the default case
		}
		cout << "\n";

		if( nKeyPress == 4 )
		{
			return (0);
		}
	}
}