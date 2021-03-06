//Cory J 6/5
#include "CommandFunctions.h"

void Look()
{		
	switch (PC->GetCurrentRoom()->GetRoomId())
	{
	case 9:
		PC->SetMusic(1);
		break;

	case 10:
		PC->SetMusic(1);
		break;

	case 21:
		PC->SetMusic(1);
		break;

	case 22:
		PC->SetMusic(1);
		break;

	case 29:
		PC->SetMusic(1);
		break;

	case 30:
		PC->SetMusic(1);
		break;		

	case 44:
		PC->SetMusic(1);
		break;

	case 45:
		PC->SetMusic(1);
		break;

	case 55:
		PC->SetMusic(1);
		break;

	case 56:
		PC->SetMusic(1);
		break;

	case 57:
		PC->SetMusic(1);
		break;
	
	case 58:
		PC->SetMusic(1);
		break;

	case 66:
		PC->SetMusic(1);
		break;
	
	case 67:
		PC->SetMusic(1);
		break;

	case 71:
		PC->SetMusic(1);
		break;
	
	case 72:
		PC->SetMusic(1);
		break;

	case 80:
		PC->SetMusic(1);
		break;
	
	case 81:
		PC->SetMusic(1);
		break;

	case 85:
		PC->SetMusic(1);
		break;
	
	case 86:
		PC->SetMusic(1);
		break;

	case 89:
		PC->SetMusic(1);
		break;
	
	case 90:
		PC->SetMusic(1);
		break;

	case 91:
		PC->SetMusic(1);
		break;

	case 93:
		PC->SetMusic(1);
		break;

	case 94:
		PC->SetMusic(1);
		break;

	case 95:
		PC->SetMusic(1);
		break;

	case 99:
		PC->SetMusic(1);
		break;

	case 100:
		PC->SetMusic(1);
		break;

	case 101:
		PC->SetMusic(1);
		break;

	case 102:
		PC->SetMusic(1);
		break;

	case 103:
		PC->SetMusic(1);
		break;

	case 104:
		PC->SetMusic(1);
		break;

	case 105:
		PC->SetMusic(1);
		break;

	case 120:
		PC->SetMusic(1);
		break;

	case 121:
		PC->SetMusic(1);
		break;

	case 124:
		PC->SetMusic(1);
		break;

	case 125:
		PC->SetMusic(1);
		break;

	default :
		break;
	}

	//Map 1 Forest = 0 - 9 : Forest Track
	if((PC->GetCurrentRoom()->GetRoomId() >= 0) && (PC->GetCurrentRoom()->GetRoomId() <= 9))
	{
		if(PC->GetMusic() != true)
		{
			BackgroundSound(L"POL-quiet-woodlands-short.wav");
			PC->SetMusic(0);
		}
	}		

	//Map 2 Dartosk kingdom = 10 - 21 : city/Kingdom track
	if((PC->GetCurrentRoom()->GetRoomId() >= 10) && (PC->GetCurrentRoom()->GetRoomId() <= 21))
	{
		if(PC->GetMusic() != true)
		{
			BackgroundSound(L"POL-into-the-castle-short.wav");
			PC->SetMusic(0);
		}
	}

	//Map 3 Fedvel Forest = 22 - 29 : Forest Track or Forest Track 2 if you want variety
	if((PC->GetCurrentRoom()->GetRoomId() >= 22) && (PC->GetCurrentRoom()->GetRoomId() <= 29))
	{
		if(PC->GetMusic() != true)
		{
			BackgroundSound(L"POL-wind-valley-short.wav");
			PC->SetMusic(0);
		}
	}

	//Map 4 Fedvel Dungeon = 30 - 44 : Dungeon Track
	if((PC->GetCurrentRoom()->GetRoomId() >= 30) && (PC->GetCurrentRoom()->GetRoomId() <= 44))
	{
		if(PC->GetMusic() != true)
		{
			BackgroundSound(L"POL-bridge-over-darkness-short.wav");
			PC->SetMusic(0);
		}
	}

	//Map 5 Fedvel Castle = 45 - 55 : Castle Track
	if((PC->GetCurrentRoom()->GetRoomId() >= 45) && (PC->GetCurrentRoom()->GetRoomId() <= 55))
	{
		if(PC->GetMusic() != true)
		{
			BackgroundSound(L"POL-into-the-castle-short.wav");
			PC->SetMusic(0);
		}
	}

	//Map 6 Helot A Area = 56 � 57, 72 - 80 : Weird track A
	if(((PC->GetCurrentRoom()->GetRoomId() >= 56) && (PC->GetCurrentRoom()->GetRoomId() <= 57)) || ((PC->GetCurrentRoom()->GetRoomId() >= 72) && (PC->GetCurrentRoom()->GetRoomId() <= 80)))
	{
		if(PC->GetMusic() != true)
		{
			BackgroundSound(L"POL-focus-short.wav");
			PC->SetMusic(0);
		}
	}

	//Map 6 Helot B Area = 58 - 66 : Weird Track b or beach music
	if((PC->GetCurrentRoom()->GetRoomId() >= 58) && (PC->GetCurrentRoom()->GetRoomId() <= 66))
	{
		if(PC->GetMusic() != true)
		{
			BackgroundSound(L"POL-blue-horizon-short.wav");
			PC->SetMusic(0);
		}
	}

	//Map 6 Helot C Area = 67 - 71 : Weird Track C or comic book related music
	if((PC->GetCurrentRoom()->GetRoomId() >= 67) && (PC->GetCurrentRoom()->GetRoomId() <= 71))
	{
		if(PC->GetMusic() != true)
		{
			BackgroundSound(L"Comic_music.wav");
			PC->SetMusic(0);
		}
	}

	//Map 7 Grandhole Inn = 81 � 85, 90 : Forest Track or Forest Track 3 for Variety
	if(((PC->GetCurrentRoom()->GetRoomId() >= 81) && (PC->GetCurrentRoom()->GetRoomId() <= 85)) || (PC->GetCurrentRoom()->GetRoomId() == 90))
	{
		if(PC->GetMusic() != true)
		{
			BackgroundSound(L"POL-jungle-short.wav");
			PC->SetMusic(0);
		}
	}
	
	//Map 7 Grandhole Inn Area = 86 - 89 : Inn Track
	if((PC->GetCurrentRoom()->GetRoomId() >= 86) && (PC->GetCurrentRoom()->GetRoomId() <= 89))
	{
		if(PC->GetMusic() != true)
		{
			BackgroundSound(L"inn_music.wav");
			PC->SetMusic(0);
		}
	}

	//Map 8 Mogan Mountain/ Thieves Den A1- A10 = 91 � 93, 95 � 99, 101 - 102 : Mountain Track
	if(((PC->GetCurrentRoom()->GetRoomId() >= 91) && (PC->GetCurrentRoom()->GetRoomId() <= 93)) || ((PC->GetCurrentRoom()->GetRoomId() >= 95) && (PC->GetCurrentRoom()->GetRoomId() <= 99)))
	{
		if(PC->GetMusic() != true)
		{
			BackgroundSound(L"mountain.wav");
			PC->SetMusic(0);
		}
	}

	if((PC->GetCurrentRoom()->GetRoomId() >= 101) && (PC->GetCurrentRoom()->GetRoomId() <= 102))
	{
		if(PC->GetMusic() != true)
		{
			BackgroundSound(L"mountain.wav");
			PC->SetMusic(0);
		}
	}
	//Map 8 Everything After = 94, 100, 103 - 104 : City/ Thieves Den Track
	if((PC->GetCurrentRoom()->GetRoomId() == 94) && (PC->GetCurrentRoom()->GetRoomId() == 100))
	{
		if(PC->GetMusic() != true)
		{
			BackgroundSound(L"thief_city.wav");
			PC->SetMusic(0);
		}
	}

	if((PC->GetCurrentRoom()->GetRoomId() >= 103) && (PC->GetCurrentRoom()->GetRoomId() <= 104))
	{
		if(PC->GetMusic() != true)
		{
			BackgroundSound(L"thief_city.wav");
			PC->SetMusic(0);
		}
	}

	//Map 9 Mogan Castle = 105 - 120 : Castle Track or Castle Track 2
	if((PC->GetCurrentRoom()->GetRoomId() >= 105) && (PC->GetCurrentRoom()->GetRoomId() <= 120))
	{
		if(PC->GetMusic() != true)
		{
			BackgroundSound(L"POL-sadistic-game-short.wav");
			PC->SetMusic(0);
		}
	}
	//Map 10 Dartosk Castle = 121 - 124 : Castle Track or Castle Track 3
	if((PC->GetCurrentRoom()->GetRoomId() >= 121) && (PC->GetCurrentRoom()->GetRoomId() <= 124))
	{
		if(PC->GetMusic() != true)
		{
			BackgroundSound(L"POL-hurry-up-short.wav");
			PC->SetMusic(0);
		}
	}

	//Epilogue = 125 -126
	if((PC->GetCurrentRoom()->GetRoomId() >= 125) && (PC->GetCurrentRoom()->GetRoomId() <= 126))
	{
		if(PC->GetMusic() != true)
		{
			BackgroundSound(L"POL-goodbye-short.wav");
			PC->SetMusic(0);
		}
	}
		
	cout << endl << Player::GetInstance()->GetCurrentRoom()->GetName() << endl;
	cout << PC->GetCurrentRoom()->GetDesc() << endl;
	cout << "EXITS:"; PC->GetCurrentRoom()->DisplayExits(); cout << endl;	
	if (PC->GetCurrentRoom()->GetNumNpc() > 0)
	{
		cout << "-Others here with you-" << endl;
		vector<Character> others = PC->GetCurrentRoom()->NpcList();
		for (vector<Character>::iterator it = others.begin(); it != others.end(); ++it)
		{
			if(it->GetStats()->GetLife() != "D")
			{
				cout << it->GetDesc() << endl;
			}
		}
	}
	vector<Item> roomItems = PC->GetCurrentRoom()->ItemList();
	if (roomItems.size() > 0)
	{
		cout << "-Items in the area-" << endl;
		for (vector<Item>::iterator it = roomItems.begin(); it != roomItems.end(); ++it)
			cout << it->GetDesc() << endl;
	}
}

void Kill(string p_target)
{
	combat_outcome battle;
	Character opponent = PC->GetCurrentRoom()->GetNPC(p_target);
	if (opponent.GetName() != "none" && opponent.GetStats()->GetLife() != "D")
	{
		cout << "You have entered combat with " << opponent.GetName() << "!" << endl;
		PC->SetMusic(1);
		BackgroundSound(L"battletheme.wav");
		battle = Combat(PC->GetStats(), opponent.GetStats());
		switch (battle)
		{
		case DEAD:
			BackgroundSound(L"Player_Death.wav");
			cout << "Game over." << endl;
			system("pause");
			exit(0);
			break;
		case FLED:
			//I don't think anything happens here, we can decide if we do want something to happen other than ending combat
			//Remove debuffs placed on the player and enemy?
			SoundEffect(L"Run_Success.wav", L"battletheme.wav");
			cout << "You got away." << endl;
			break;
		case KILLED:
			if (opponent.GetInventory().size() > 0)
			{
				list<Item> loot = opponent.GetInventory();
				for (list<Item>::iterator it = loot.begin(); it != loot.end(); ++it)
				{
					PC->GetCurrentRoom()->AddItem(*it);
					WorldItems::m_items[it->GetItemId()].SetSaveLocation(IN_ROOM);
					WorldItems::m_items[it->GetItemId()].SetRoomId(PC->GetCurrentRoom()->GetRoomId());
				}
			}
			SoundEffect(L"enemy_death.wav", L"battletheme.wav");
			PC->AwardExperience(opponent.GetStats()->GetExp());			
			//opponent.SetLife("D");
			
			int tempNum = 0;
			tempNum = PC->GetCurrentRoom()->GetNumNpc() - 1;
			string npcLine = static_cast<ostringstream*>( &(ostringstream() << tempNum) )->str();
			PC->GetCurrentRoom()->SetNumNpc(atoi(npcLine.c_str()));
			//PC->GetCurrentRoom()->RemoveNpc(opponent.GetName());
			break;
		}
		Look();
	}
	else
		cout << "That is not a valid target." << endl;
}

void North()
{
	if (PC->GetCurrentRoom()->GetNumNpc() > 0)
	{
		cout << "Enemies are blocking your path!" << endl;
		return;
	}
	if (PC->GetCurrentRoom()->CheckExit(NORTH))
	{
		PC->SetCurrentRoom(PC->GetCurrentRoom()->GetN());
		Look();
	}
	else
		cout << "There is no exit that way." << endl;
}

void South()
{
	if (PC->GetCurrentRoom()->GetNumNpc() > 0)
	{
		cout << "Enemies are blocking your path!" << endl;
		return;
	}
	if (PC->GetCurrentRoom()->CheckExit(SOUTH))
	{
		PC->SetCurrentRoom(PC->GetCurrentRoom()->GetS());
		Look();
	}
	else
		cout << "There is no exit that way." << endl;
}

void East()
{
	if (PC->GetCurrentRoom()->GetNumNpc() > 0)
	{
		cout << "Enemies are blocking your path!" << endl;
		return;
	}
	if (PC->GetCurrentRoom()->CheckExit(EAST))
	{
		PC->SetCurrentRoom(PC->GetCurrentRoom()->GetE());
		Look();
	}
	else
		cout << "There is no exit that way." << endl;
}

void West()
{
	if (PC->GetCurrentRoom()->GetNumNpc() > 0)
	{
		cout << "Enemies are blocking your path!" << endl;
		return;
	}
	if (PC->GetCurrentRoom()->CheckExit(WEST))
	{
		PC->SetCurrentRoom(PC->GetCurrentRoom()->GetW());
		Look();
	}
	else
		cout << "There is no exit that way." << endl;
}

void Up()
{
	if (PC->GetCurrentRoom()->GetNumNpc() > 0)
	{
		cout << "Enemies are blocking your path!" << endl;
		return;
	}
	if (PC->GetCurrentRoom()->CheckExit(UP))
	{
		PC->SetCurrentRoom(PC->GetCurrentRoom()->GetU());
		Look();
	}
	else
		cout << "There is no exit that way." << endl;
}

void Down()
{
	if (PC->GetCurrentRoom()->GetNumNpc() > 0)
	{
		cout << "Enemies are blocking your path!" << endl;
		return;
	}
	if (PC->GetCurrentRoom()->CheckExit(DOWN))
	{
		PC->SetCurrentRoom(PC->GetCurrentRoom()->GetD());
		Look();
	}
	else
		cout << "There is no exit that way." << endl;
}

void Score()
{
	//Output score screen
	cout << "Name: " << PC->GetName() << endl;
	cout << "Gender: " << PC->GetDesc() << endl;
	cout << "Level: " << PC->GetLevel() << endl;
	cout << "Exp: " << PC->GetExperience() << endl;
	cout << "HP: " <<  PC->GetStats()->GetHp() << "/" << PC->GetStats()->GetMaxHp() << endl;
	cout << "MP: " <<  PC->GetStats()->GetMp() << "/" << PC->GetStats()->GetMaxMp() << endl;
	cout << "Strength: " <<  PC->GetStats()->GetStr() << endl;
	cout << "Agility: " <<  PC->GetStats()->GetAgi() << endl;
	cout << "Armor: " << PC->GetStats()->GetAs() << endl;
}

void Inventory()
{
	list<Item> inventory = PC->GetInventory();
	cout << "You are carrying " << inventory.size() << " items in your inventory." << endl;
	for (list<Item>::iterator it = inventory.begin(); it != inventory.end(); ++it)
	{
		cout << it->GetShort() << endl;
	}
	cout << endl;
}

void Abilities()
{
	PC->UpdateAbilityEquations();
	vector<ability> pcAbil = PC->GetAbilities();
	string sInput;
	int userInput; // Holds the key pressed by the user
	stringstream convertInput;
	while (true)
	{
		int i = -1;
		for (vector<ability>::iterator it = pcAbil.begin();	it != pcAbil.end();	++it)
		{
			i++;
			if(it->IsUnlocked())// if PC->GetLevel() is greater than or equal to it->m_unlockedLevel
			{
				cout << "Ability " << i+1 << ": " << it->m_name << endl;
			}
		}
		cout << "Enter the number of the ability to see its full effects or 0 to quit: ";
		getline(cin, sInput);
		convertInput.str("");
		convertInput.clear();
		convertInput.str(sInput);
		while (!(convertInput >> userInput))
		{
			convertInput.str("");
			convertInput.clear();
			cout << "Make sure to enter the NUMBER that is next to the ability you want to see: ";
			getline(cin, sInput);
			convertInput.str(sInput);
		}
		cout << endl;
		userInput--;
		if (userInput == -1)
			break;
		if(pcAbil[userInput].IsUnlocked())// if PC->GetLevel() is greater than or equal to it->m_unlockedLevel
		{
			cout << "Name: " << pcAbil[userInput].m_name << endl;
			cout << "Description: " << pcAbil[userInput].m_desc;
			cout << "Cool Down: " << pcAbil[userInput].m_cooldown << endl;
			cout << "HP Cost: " << pcAbil[userInput].m_hpCost << endl;
			cout << "MP Cost: " << pcAbil[userInput].m_mpCost << endl;
			cout << "Target: " << pcAbil[userInput].m_target << endl;
			cout << "Affects: " << pcAbil[userInput].GetType() << endl;
			cout << "Amount: " << pcAbil[userInput].m_amount << endl;
		}
		else
		{
			cout << "That is not an unlocked ability." << endl;
		}
		cout << endl;
	}
}

void Help()
{
	cout << "If there are ' marks around a word, that means it is a command. You do not type in the ' marks around the command." << endl;
	cout << "'look' or 'l' will show you the contents of the room you are in." << endl;
	cout << "'north' or 'n' will move you north if it is a valid exit for the room you are in. The other directions have similar commands." << endl;
	cout << "'kill <target>' or 'k <target>' will attempt battle with an npc. Note this command requires a target. Ex: 'kill ogre' would attempt battle with the ogre in the room." << endl;
	cout << "The name you must enter to kill an enemy is in the brackets. Ex. Unknown Soldier Sword {Sword}. You would type 'kill Sword'. Unless there is no brackets. Ex. Rat, Type 'kill Rat'." << endl;
	cout << "'score' or 'sc' will show you your current stats." << endl;
	cout << "'abilities' or 'ab' will show you all of your current abilities and what they do." << endl;
	cout << "'growth' or 'grow' will allow you to choose your primary and secondary stat growths." << endl;
	cout << "'inventory' or 'i' will show you all the items you are carrying." << endl;
	cout << "'use' will let you activate an item for its affects. Ex: 'use weakherb' will use an herb in your inventory to restore your HP." << endl;
	cout << "'equipment' or 'eq' will show you all the items you are wearing." << endl;
	cout << "'examine <inventory/equipment/look>' or 'exa' will allow you to see the names of all valid targets. Ex: 'exa eq' will show you the names of all worn items." << endl;
	cout << "'quit' or 'q' will quit the game." << endl;
	cout << "'save' will save the game." << endl;
}

void Growth()
{
	cout << "You can set your primary and secondary stat growths. Your primary stat will grow the fastest, while your secondary stat will grow at a rate between your primary stat and the rest of your stats.\n"
		"These can be changed at any time outside of combat, and only come into play during a level up." << endl;
	PC->ChangeStatFocus();
}

void Quit()
{
	
	string input = "n";
	do
	{
		cout << "Are you SURE you want to quit? All unsaved progress will be lost (y/n): ";
		getline(cin, input);
	} while (input != "y" && input != "n");
	if (input == "y")
	{
		exit(0);
	}
}

void Equipment()
{
	unordered_map<wear_slot, Item> equipment = PC->GetEquipment();
	cout << "Head: " << equipment[HEAD].GetShort() << endl;
	cout << "Shoulders: " << equipment[SHOULDERS].GetShort() << endl;
	cout << "Arms: " << equipment[ARMS].GetShort() << endl;
	cout << "Hands: " << equipment[HANDS].GetShort() << endl;
	if (PC->GetLevel() < 3) //whatever level the dark gun is gained at
		cout << "Mainhand: a magitech sword" << endl;
	else
		cout << "Mainhand: the Dark Gun" << endl;
	cout << "Offhand: " << equipment[OFFHAND].GetShort() << endl;
	cout << "Body: " << equipment[BODY].GetShort() << endl;
	cout << "Legs: " << equipment[LEGS].GetShort() << endl;
	cout << "Feet: " << equipment[FEET].GetShort() << endl;
}

void Wear(string p_target)
{
	list<Item> inventory = PC->GetInventory();
	for (list<Item>::iterator it = inventory.begin(); it != inventory.end(); ++it)
	{
		if (it->GetName() == p_target)
		{
			if (it->GetWearSlot() != NONE)
			{
				PC->EquipItem(*it);
				return;
			}
			break;
		}
	}
	cout << "That is not a valid item." << endl;
}

void Remove(string p_target)
{
	unordered_map<wear_slot, Item> equipment = PC->GetEquipment();
	for (int it = HEAD; it != FEET; ++it)
	{
		if (equipment[(wear_slot)it].GetName() == p_target)
		{
			PC->UnequipItem(equipment[(wear_slot)it]);
			return;
		}
	}
	cout << "That is not a valid item." << endl;
}

void ExaInv()
{
	list<Item> inventory = PC->GetInventory();
	cout << "You are carrying " << inventory.size() << " items in your inventory." << endl;
	for (list<Item>::iterator it = inventory.begin(); it != inventory.end(); ++it)
	{
		cout << "(" << it->GetName() << ") " << it->GetShort() << endl;
	}
	cout << endl;
}

void ExaEquip()
{
	unordered_map<wear_slot, Item> equipment = PC->GetEquipment();
	cout << "Head: " << "(" << equipment[HEAD].GetName() << ") " << equipment[HEAD].GetShort() << endl;
	cout << "Shoulders: " << "(" << equipment[SHOULDERS].GetName() << ") " << equipment[SHOULDERS].GetShort() << endl;
	cout << "Arms: " << "(" << equipment[ARMS].GetName() << ") " << equipment[ARMS].GetShort() << endl;
	cout << "Hands: " << "(" << equipment[HANDS].GetName() << ") " << equipment[HANDS].GetShort() << endl;
	if (PC->GetLevel() < 3) //whatever level the dark gun is gained at
		cout << "Mainhand: (no name) a magitech sword" << endl;
	else
		cout << "Mainhand: (no name) the Dark Gun" << endl;
	cout << "Offhand: " << "(" << equipment[OFFHAND].GetName() << ") " << equipment[OFFHAND].GetShort() << endl;
	cout << "Body: " << "(" << equipment[BODY].GetName() << ") " << equipment[BODY].GetShort() << endl;
	cout << "Legs: " << "(" << equipment[LEGS].GetName() << ") " << equipment[LEGS].GetShort() << endl;
	cout << "Feet: " << "(" << equipment[FEET].GetName() << ") " << equipment[FEET].GetShort() << endl;
}

void ExaLook()
{
	cout << endl << PC->GetCurrentRoom()->GetName() << endl;
	cout << PC->GetCurrentRoom()->GetDesc() << endl;
	cout << "EXITS:"; PC->GetCurrentRoom()->DisplayExits(); cout << endl;	
	if (PC->GetCurrentRoom()->GetNumNpc() > 0)
	{
		cout << "-Others here with you-" << endl;
		vector<Character> others = PC->GetCurrentRoom()->NpcList();
		for (vector<Character>::iterator it = others.begin(); it != others.end(); ++it)
		{
			cout << "(" << it->GetName() << ") " << it->GetDesc() << endl;
		}
	}
	vector<Item> roomItems = PC->GetCurrentRoom()->ItemList();
	if (roomItems.size() > 0)
	{
		cout << "-Items in the area-" << endl;
		for (vector<Item>::iterator it = roomItems.begin(); it != roomItems.end(); ++it)
			cout << "(" << it->GetName() << ") " << it->GetDesc() << endl;
	}
}

void Get(string p_target)
{
	Item gotItem = PC->GetCurrentRoom()->GetItem(p_target);
	if (gotItem.GetName() != "none")
	{
		cout << "You get " << gotItem.GetShort() << "." << endl;
		PC->AddItem(gotItem);
		PC->GetCurrentRoom()->RemoveItem(p_target);
		WorldItems::m_items[gotItem.GetItemId()].SetSaveLocation(IN_INVENTORY);
	}
	else
		cout << "You do not see that item here." << endl;
}

void Drop(string p_target)
{
	list<Item> items = PC->GetInventory();
	for (list<Item>::iterator it = items.begin(); it != items.end(); ++it)
	{
		if (it->GetName() == p_target)
		{
			cout << "You drop " << it->GetShort() << "." << endl;
			PC->GetCurrentRoom()->AddItem(*it);
			PC->RemoveItem(p_target);
			WorldItems::m_items[it->GetItemId()].SetSaveLocation(IN_ROOM);
			WorldItems::m_items[it->GetItemId()].SetRoomId(PC->GetCurrentRoom()->GetRoomId());
			return;
		}
	}
	cout << "You do not have that item." << endl;
}

void Use(string p_target)
{
	list<Item> items = PC->GetInventory();
	for (list<Item>::iterator it = items.begin(); it != items.end(); ++it)
	{
		if (it->GetName() == p_target)
		{
			if (it->GetWearSlot() == NONE)
			{
				cout << "You use " << it->GetShort() << "." << endl;
				switch(it->GetUseAffect())
				{
				case HP: //restores health
					PC->GetStats()->SetHp(PC->GetStats()->GetHp()+it->GetUseAffectAmount());
					if (PC->GetStats()->GetHp() > PC->GetStats()->GetMaxHp())
						PC->GetStats()->SetHp(PC->GetStats()->GetMaxHp());
					break;
				case MP: //restores mana
					PC->GetStats()->SetMp(PC->GetStats()->GetMp()+it->GetUseAffectAmount());
					if (PC->GetStats()->GetMp() > PC->GetStats()->GetMaxMp())
						PC->GetStats()->SetMp(PC->GetStats()->GetMaxMp());
					break;
				case STR: //increases strength permanently
					PC->GetStats()->SetStr(PC->GetStats()->GetStr()+it->GetUseAffectAmount());
					PC->GetStats()->SetMaxStr(PC->GetStats()->GetMaxStr()+it->GetUseAffectAmount());
					break;
				case AGI: //increases agility permanently
					PC->GetStats()->SetAgi(PC->GetStats()->GetAgi()+it->GetUseAffectAmount());
					PC->GetStats()->SetMaxAgi(PC->GetStats()->GetMaxAgi()+it->GetUseAffectAmount());
					break;
				case AS: //increases armor score permanently
					PC->GetStats()->SetAs(PC->GetStats()->GetAs()+it->GetUseAffectAmount());
					PC->GetStats()->SetMaxAs(PC->GetStats()->GetMaxAs()+it->GetUseAffectAmount());
					break;
				}
				PC->RemoveItem(p_target);
				WorldItems::m_items[it->GetItemId()].SetSaveLocation(NOWHERE);
			}
			else
				cout << "You cannot use this item." << endl;
			return;
		}
	}
	cout << "You do not have that item." << endl;
}

void SavePlayer()
{
	Save();
	WorldItems::SaveItems();
}