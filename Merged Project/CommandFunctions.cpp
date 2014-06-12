//Cory J 6/5
#include "CommandFunctions.h"

void Look()
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
			cout << it->GetDesc() << endl;
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
	Room* room = PC->GetCurrentRoom();
	Character opponent = room->GetNPC(p_target);
	if (opponent.GetName() != "NULL")
	{
		cout << "You have entered combat with " << opponent.GetName() << "!" << endl;
		battle = Combat(PC->GetStats(), opponent.GetStats());
		switch (battle)
		{
		case DEAD:
			cout << "Game over." << endl;
			system("pause");
			exit(0);
			break;
		case FLED:
			//I don't think anything happens here, we can decide if we do want something to happen other than ending combat
			//Remove debuffs placed on the player and enemy?
			cout << "You got away." << endl;
			break;
		case KILLED:
			if (opponent.GetInventory().size() > 0)
			{
				list<Item> loot = opponent.GetInventory();
				for (list<Item>::iterator it = loot.begin(); it != loot.end(); ++it)
				{
					room->AddItem(*it);
				}
			}
			PC->AwardExperience(opponent.GetStats()->GetExp());
			room->RemoveNpc(opponent.GetName());
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
			if(PC->GetLevel() >= it->m_unlockLevel)// if PC->GetLevel() is greater than or equal to it->m_unlockedLevel
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
		if(PC->GetLevel() >= pcAbil[userInput].m_unlockLevel)// if PC->GetLevel() is greater than or equal to it->m_unlockedLevel
		{
			cout << "Name: " << pcAbil[userInput].m_name << endl;
			cout << "Description: " << pcAbil[userInput].m_desc;
			cout << "Cool Down: " << pcAbil[userInput].m_cooldown << endl;
			cout << "HP Cost: " << pcAbil[userInput].m_hpCost << endl;
			cout << "MP Cost: " << pcAbil[userInput].m_mpCost << endl;
			cout << "Target: " << pcAbil[userInput].m_target << endl;
			cout << "Affects: " << pcAbil[userInput].m_type << endl;
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
	cout << "'score' or 'sc' will show you your current stats." << endl;
	cout << "'abilities' or 'ab' will show you all of your current abilities and what they do." << endl;
	cout << "'growth' or 'grow' will allow you to choose your primary and secondary stat growths." << endl;
	cout << "'inventory' or 'i' will show you all the items you are carrying." << endl;
	cout << "'use' will let you activate an item for its affects. Ex: 'use weakherb' will use an herb in your inventory to restore your HP." << endl;
	cout << "'equipment' or 'eq' will show you all the items you are wearing." << endl;
	cout << "'examine <inventory/equipment/look>' or 'exa' will allow you to see the names of all valid targets. Ex: 'exa eq' will show you the names of all worn items." << endl;
	cout << "'quit' or 'q' will quit the game." << endl;
}

void Growth()
{
	cout << "You can set your primary and secondary stat growths. Your primary stat will grow the fastest, while your secondary stat will grow at a rate between your primary stat and the rest of your stats.\n"
		"These can be changed at any time outside of combat, and only come into play during a level up." << endl;
	PC->ChangeStatFocus();
}

bool Quit()
{
	return true;
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
	Room* room = PC->GetCurrentRoom();
	Item gotItem = room->GetItem(p_target);
	if (gotItem.GetName() != "none")
	{
		cout << "You get " << gotItem.GetShort() << "." << endl;
		PC->AddItem(gotItem);
		room->RemoveItem(p_target);
	}
	else
		cout << "You do not see that item here." << endl;
}

void Drop(string p_target)
{
	Room* room = PC->GetCurrentRoom();
	list<Item> items = PC->GetInventory();
	for (list<Item>::iterator it = items.begin(); it != items.end(); ++it)
	{
		if (it->GetName() == p_target)
		{
			cout << "You drop " << it->GetShort() << "." << endl;
			room->AddItem(*it);
			PC->RemoveItem(p_target);
			return;
		}
	}
	cout << "You do not have that item." << endl;
}

void Use(string p_target)
{
	Room* room = PC->GetCurrentRoom();
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
			}
			else
				cout << "You cannot use this item." << endl;
			return;
		}
	}
	cout << "You do not have that item." << endl;
}