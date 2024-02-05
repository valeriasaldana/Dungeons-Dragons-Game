// CSCI 1300 Spring 2023
// Author: Valeria Saldana & Emiliano Medina
// Project 3

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <ctype.h>
#include <cassert>
#include "characters.h"
#include "items.h"
#include "map.h"
#include "monsters.h"
#include "status.h"

using namespace std;

using namespace std;

// end of the game if the player has beat the game
void endGameHappy(Characters characters, Items items, Status status)
{
    cout << "You escaped the dungeon!!! Congratulationss!!"<<endl;
    cout << "Here are the final stats:" << endl;
    cout << "+--------------+" << endl;

    string mainPlayer = characters.getPlayerName();
    int playerHealth = characters.getHealthMain();
    cout << "Main player: " << mainPlayer << ": " << playerHealth << endl;
    cout << "+--------------+" << endl;

    
    cout << "Party: " << endl;

    if (characters.isN1Alive() == true)
    {
        string player1 = characters.getn1Name();
    
        cout << player1 << ": " << characters.getHealth1() << endl;
    }
    if (characters.isN2Alive() == true)
    {
        string player2 = characters.getn2Name();
    
        cout << player2 << ": " << characters.getHealth2() << endl;
    }
    if (characters.isN3Alive() == true)
    {
        string player3 = characters.getn3Name();
    
        cout << player3 << ": " << characters.getHealth3() << endl;
    }
    if (characters.isN4Alive() == true)
    {
        string player4 = characters.getn4Name();
    
        cout << player4 << ": " << characters.getHealth4() << endl;
    }
    

    cout << "+--------------+" << endl;
    cout << "Rooms cleared: " << status.getNumRoomsCleared() << endl;
    cout << "+--------------+" << endl;

    cout << "Gold remaining: " << characters.getGold() << endl;
    cout << "+--------------+" << endl;

    cout << "Treasure: " << endl;
    cout << items.getNumRing() << " Silver Ring(s)." << endl;
    cout << items.getNumNecklace() << " Ruby Necklace(s)." << endl;
    cout << items.getNumBracelet() << " Emerald Bracelet(s)." << endl;
    cout << items.getNumCirclet() << " Diamond Circlet(s)." << endl;
    cout << items.getNumGoblet() << " Gem-encrusted goblet(s)." << endl;
    cout << "+--------------+" << endl;

    cout << "Number of spaces explored: " << status.getNumSpacesExplored() << endl;
    cout << "+--------------+" << endl;
    cout << "Number of monsters defeated: " << status.getNumMonstersDefeated() << endl;
    cout << "+--------------+" << endl;
    cout << "Number of turns elapsed: " << status.getNumTurns() << endl;
    cout << "+--------------+" << endl;

    int health[5] = {characters.getHealthMain() , characters.getHealth1(), characters.getHealth2(), characters.getHealth3(), characters.getHealth4()};
    string names[5] = {characters.getPlayerName(), characters.getn1Name(), characters.getn2Name(), characters.getn3Name(), characters.getn4Name()};

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4-i; j++) {
            if (health[j] < health[j+1]) {
                int tempHealth = health[j];
                health[j] = health[j+1];
                health[j+1] = tempHealth;

                string tempName = names[j];
                names[j] = names[j+1];
                names[j+1] = tempName;
            }
        }
    }

    cout << "Players sorted by fullness level:" << endl;
    for (int i = 0; i < 5; i++) {
        if (names[i] != "") {
            cout << names[i] << " : " << health[i] << " fullness level" << endl;
            cout << "+--------------+" << endl;
        }
    }
    //write on file
    ofstream myfile;
    myfile.open ("results.txt");

    myfile << "You escaped the dungeon!!! Congratulationss!!"<<endl;
    myfile << "Here are the final stats:" << endl;
    myfile << "+--------------+" << endl;

    string mainPlaye = characters.getPlayerName();
    int playerHealt = characters.getHealthMain();
    myfile << "Main player: " << mainPlayer << ": " << playerHealth << endl;
    myfile << "+--------------+" << endl;

    
    myfile << "Party: " << endl;

    if (characters.isN1Alive() == true)
    {
        string layer1 = characters.getn1Name();
    
        myfile << layer1 << ": " << characters.getHealth1() << endl;
    }
    if (characters.isN2Alive() == true)
    {
        string layer2 = characters.getn2Name();
    
        myfile << layer2 << ": " << characters.getHealth2() << endl;
    }
    if (characters.isN3Alive() == true)
    {
        string layer3 = characters.getn3Name();
    
        myfile << layer3 << ": " << characters.getHealth3() << endl;
    }
    if (characters.isN4Alive() == true)
    {
        string layer4 = characters.getn4Name();
    
        myfile << layer4 << ": " << characters.getHealth4() << endl;
    }
    

    myfile << "+--------------+" << endl;
    myfile << "Rooms cleared: " << status.getNumRoomsCleared() << endl;
    myfile << "+--------------+" << endl;

    myfile << "Gold remaining: " << characters.getGold() << endl;
    myfile << "+--------------+" << endl;

    myfile << "Treasure: " << endl;
    myfile << items.getNumRing() << " Silver Ring(s)." << endl;
    myfile << items.getNumNecklace() << " Ruby Necklace(s)." << endl;
    myfile << items.getNumBracelet() << " Emerald Bracelet(s)." << endl;
    myfile << items.getNumCirclet() << " Diamond Circlet(s)." << endl;
    myfile << items.getNumGoblet() << " Gem-encrusted goblet(s)." << endl;
    myfile << "+--------------+" << endl;

    myfile << "Number of spaces explored: " << status.getNumSpacesExplored() << endl;
    myfile << "+--------------+" << endl;
    myfile << "Number of monsters defeated: " << status.getNumMonstersDefeated() << endl;
    myfile << "+--------------+" << endl;
    myfile << "Number of turns elapsed: " << status.getNumTurns() << endl;
    myfile << "+--------------+" << endl;

    int healt[5] = {characters.getHealthMain() , characters.getHealth1(), characters.getHealth2(), characters.getHealth3(), characters.getHealth4()};
    string name[5] = {characters.getPlayerName(), characters.getn1Name(), characters.getn2Name(), characters.getn3Name(), characters.getn4Name()};

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4-i; j++) {
            if (healt[j] < healt[j+1]) {
                int tempHealt = healt[j];
                healt[j] = healt[j+1];
                healt[j+1] = tempHealt;

                string tempNam = name[j];
                name[j] = name[j+1];
                name[j+1] = tempNam;
            }
        }
    }

    myfile << "Players sorted by fullness level:" << endl;
    for (int i = 0; i < 5; i++) {
        if (name[i] != "") {
            myfile << name[i] << " : " << healt[i] << " fullness level" << endl;
            myfile << "+--------------+" << endl;
        }
    }

    myfile << endl;
    myfile << endl;
}
//end of game is the player gave up or died
void endGame(Characters characters, Items items, Status status)
{
    cout << "I regret to inform you that the explorers failed to escape the dungeon. They made heroic attempts, but the obstacles they faced proved to be too great for them to overcome"<<endl;
    cout << "RIP to the party and the players, may their example motivate present and future explorers to push themselves to the limit in the search for knowledge and adventure." << endl;
    cout << "Here are the final stats:" << endl;
    cout << "+--------------+" << endl;

    string mainPlayer = characters.getPlayerName();
    int playerHealth = characters.getHealthMain();
    cout << "Main player: " << mainPlayer << ": " << playerHealth << endl;
    cout << "+--------------+" << endl;

    
    cout << "Party: " << endl;

    if (characters.isN1Alive() == true)
    {
        string player1 = characters.getn1Name();
    
        cout << player1 << ": " << characters.getHealth1() << endl;
    }
    if (characters.isN2Alive() == true)
    {
        string player2 = characters.getn2Name();
    
        cout << player2 << ": " << characters.getHealth2() << endl;
    }
    if (characters.isN3Alive() == true)
    {
        string player3 = characters.getn3Name();
    
        cout << player3 << ": " << characters.getHealth3() << endl;
    }
    if (characters.isN4Alive() == true)
    {
        string player4 = characters.getn4Name();
    
        cout << player4 << ": " << characters.getHealth4() << endl;
    }

    cout << "+--------------+" << endl;
    cout << "Rooms cleared: " << status.getNumRoomsCleared() << endl;
    cout << "+--------------+" << endl;

    cout << "Gold remaining: " << characters.getGold() << endl;
    cout << "+--------------+" << endl;

    cout << "Treasure: " << endl;
    cout << items.getNumRing() << " Silver Ring(s)." << endl;
    cout << items.getNumNecklace() << " Ruby Necklace(s)." << endl;
    cout << items.getNumBracelet() << " Emerald Bracelet(s)." << endl;
    cout << items.getNumCirclet() << " Diamond Circlet(s)." << endl;
    cout << items.getNumGoblet() << " Gem-encrusted goblet(s)." << endl;
    cout << "+--------------+" << endl;

    cout << "Number of spaces explored: " << status.getNumSpacesExplored() << endl;
    cout << "+--------------+" << endl;
    cout << "Number of monsters defeated: " << status.getNumMonstersDefeated() << endl;
    cout << "+--------------+" << endl;
    cout << "Number of turns elapsed: " << status.getNumTurns() << endl;
    cout << "+--------------+" << endl;

    int health[5] = {characters.getHealthMain() , characters.getHealth1(), characters.getHealth2(), characters.getHealth3(), characters.getHealth4()};
    string names[5] = {characters.getPlayerName(), characters.getn1Name(), characters.getn2Name(), characters.getn3Name(), characters.getn4Name()};

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4-i; j++) {
            if (health[j] < health[j+1]) {
                int tempHealth = health[j];
                health[j] = health[j+1];
                health[j+1] = tempHealth;

                string tempName = names[j];
                names[j] = names[j+1];
                names[j+1] = tempName;
            }
        }
    }

    cout << "Players sorted by fullness level:" << endl;
    for (int i = 0; i < 5; i++) {
        if (names[i] != "") {
            cout << names[i] << " : " << health[i] << " fullness level" << endl;
            cout << "+--------------+" << endl;
        }
    }

    //writing results in file:
    ofstream myfile;
    myfile.open ("results.txt");

    myfile << "I regret to inform you that the explorers failed to escape the dungeon. They made heroic attempts, but the obstacles they faced proved to be too great for them to overcome"<<endl;
    myfile << "RIP to the party and the players, may their example motivate present and future explorers to push themselves to the limit in the search for knowledge and adventure." << endl;
    myfile << "Here are the final stats:" << endl;
    myfile << "+--------------+" << endl;

    string mainPlaye = characters.getPlayerName();
    int playerHealt = characters.getHealthMain();
    myfile << "Main player: " << mainPlaye << ": " << playerHealt << endl;
    myfile << "+--------------+" << endl;

    
    myfile << "Party: " << endl;

    if (characters.isN1Alive() == true)
    {
        string layer1 = characters.getn1Name();
    
        myfile << layer1 << ": " << characters.getHealth1() << endl;
    }
    if (characters.isN2Alive() == true)
    {
        string layer2 = characters.getn2Name();
    
        myfile << layer2 << ": " << characters.getHealth2() << endl;
    }
    if (characters.isN3Alive() == true)
    {
        string layer3 = characters.getn3Name();
    
        myfile << layer3 << ": " << characters.getHealth3() << endl;
    }
    if (characters.isN4Alive() == true)
    {
        string layer4 = characters.getn4Name();
    
        myfile << layer4 << ": " << characters.getHealth4() << endl;
    }

    myfile << "+--------------+" << endl;
    myfile << "Rooms cleared: " << status.getNumRoomsCleared() << endl;
    myfile << "+--------------+" << endl;

    myfile << "Gold remaining: " << characters.getGold() << endl;
    myfile << "+--------------+" << endl;

    myfile << "Treasure: " << endl;
    myfile << items.getNumRing() << " Silver Ring(s)." << endl;
    myfile << items.getNumNecklace() << " Ruby Necklace(s)." << endl;
    myfile << items.getNumBracelet() << " Emerald Bracelet(s)." << endl;
    myfile << items.getNumCirclet() << " Diamond Circlet(s)." << endl;
    myfile << items.getNumGoblet() << " Gem-encrusted goblet(s)." << endl;
    myfile << "+--------------+" << endl;

    myfile << "Number of spaces explored: " << status.getNumSpacesExplored() << endl;
    myfile << "+--------------+" << endl;
    myfile << "Number of monsters defeated: " << status.getNumMonstersDefeated() << endl;
    myfile << "+--------------+" << endl;
    myfile << "Number of turns elapsed: " << status.getNumTurns() << endl;
    myfile << "+--------------+" << endl;

    int healt[5] = {characters.getHealthMain() , characters.getHealth1(), characters.getHealth2(), characters.getHealth3(), characters.getHealth4()};
    string name[5] = {characters.getPlayerName(), characters.getn1Name(), characters.getn2Name(), characters.getn3Name(), characters.getn4Name()};

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4-i; j++) {
            if (healt[j] < healt[j+1]) {
                int tempHealt = healt[j];
                healt[j] = healt[j+1];
                healt[j+1] = tempHealt;

                string tempNam = name[j];
                name[j] = name[j+1];
                name[j+1] = tempNam;
            }
        }
    }

    myfile << "Players sorted by fullness level:" << endl;
    for (int i = 0; i < 5; i++) {
        if (name[i] != "") {
            myfile << name[i] << " : " << healt[i] << " fullness level" << endl;
            myfile << "+--------------+" << endl;
        }
    }

    myfile << endl;
    myfile << endl;

}
//to get random numbers for map
int random(int first, int last, int i)
{
    srand(time(NULL) + i);

    int myRand = rand();
    myRand = rand();
    myRand = myRand % last + first;
    return myRand;
}
//to call whenever there is a monster fight
int monsterFight (int numRoomsCleared, Status status, Characters characters, Items items, Monsters monsters)
{
    cout << "looks like a " << monsters.getMonsterName() << " has appeared!!" << endl;

                
    if (items.getNumWeapons() >= 1)
    {
        char fs;
        cout << "are you ready to fight? Or do you wish to surrender? (enter either f for fight or s for surrender)" << endl;
        cin >> fs;
        if (fs == 'f')
        {
            cout << "FIGHT" << endl;
            cout << "-----" << endl;
        }
        else if (fs == 's')
        {
            int randTrapped = (rand() % 4) + 1;
            if (randTrapped == 1)
            {
                cout << characters.getn1Name() << "  was unable to escape the wrath of the monster and is held captive!" << endl;
                cout << "Say your goodbyes..." << endl;
                characters.removeCharacters(characters.getn1Name());
                characters.killN1();
                characters.setHealth1(characters.getHealth1());
                return 11;
            }

            if (randTrapped == 2)
            {
                cout << characters.getn2Name() << "  was unable to escape the wrath of the monster and is held captive!" << endl;
                cout << "Say your goodbyes..." << endl;
                characters.removeCharacters(characters.getn2Name());
                characters.killN2();
                characters.setHealth2(characters.getHealth2());
                return 12;
            }

            if (randTrapped == 3)
            {
                cout << characters.getn3Name() << "  was unable to escape the wrath of the monster and is held captive!" << endl;
                cout << "Say your goodbyes..." << endl;
                characters.removeCharacters(characters.getn3Name());
                characters.killN3();
                characters.setHealth3(characters.getHealth3());
                return 13;
            }

            if (randTrapped == 4)
            {
                cout << characters.getn4Name() << "  was unable to escape the wrath of the monster and is held captive!" << endl;
                cout << "Say your goodbyes..." << endl;
                characters.removeCharacters(characters.getn4Name());
                characters.killN4();
                characters.setHealth4(characters.getHealth4());
                return 14;
            }
            return 3;
        }
    }
    if ((items.getNumWeapons() < 1)) 
    {
        cout << "Oh no! Looks like you have no weapons! You have to surrender this fight!" << endl;
        return 0;
    }

    return 0;
}



int main() 
{
    string input_nplayer;
    string input_n1;
    string input_n2;
    string input_n3;
    string input_n4;
    cout << "Ready to start the game?" << endl;
    cout << "Enter your name:" << endl;
    cin >> input_nplayer;
    cout << "Enter the names of the other four traveling companions" << endl;
    cin >> input_n1;
    cin >> input_n2;
    cin >> input_n3;
    cin >> input_n4;

    cout << "Between the 5 of you, you have 100 gold pieces." << endl;
    cout << "You will need to spend the some of your money on the following items: " << endl;
    cout << endl;
    cout << "- INGREDIENTS. To make food, you have to cook raw ingredients." << endl;
    cout << "- COOKWARE. If you want to cook, you have to have cookware first." << endl;
    cout << "- WEAPONS. You'll want at least one weapon per party member to fend off monsters." << endl;
    cout << "- ARMOR. Armor increases the chances of surviving a monster attack." << endl;
    cout << endl;
    cout << "You can spend all of your money here before you start your journey, or you can save some to spend on merchants along the way. But beware, some of the merchants in this dungeon are shady characters, and they won't always give you a fair price..." << endl;
    cout << endl;

    //defining class objects
    //setting all of the player's names
    Characters characters(input_nplayer, input_n1, input_n2, input_n3, input_n4, 100, 50, 50, 50, 50, 50);
    characters.addCharacters(input_nplayer);
    characters.addCharacters(input_n1);
    characters.addCharacters(input_n2);
    characters.addCharacters(input_n3);
    characters.addCharacters(input_n4);
    Items items;
    Status status;
    Map map;

    //to check the price depending on the rooms cleared
    double price;
   if (status.getNumRoomsCleared() == 0)
   {
        price = 1.00;
   }
   else if (status.getNumRoomsCleared() == 1)
   {
        price = 1.25;
   }
   else if (status.getNumRoomsCleared() == 2)
   {
        price = 1.50;
   }
   else if (status.getNumRoomsCleared() == 3)
   {
        price = 1.75;
   }
   else if (status.getNumRoomsCleared() == 4)
   {
        price = 2.00;
   }
    cout << "If you're looking to get supplies, you've come to the right place." << endl;
    cout << "I would be happy to part with some of my wares...for the proper price!" << endl;
    cout << endl;

    cout << "+--------------+" << endl;
    cout << "STATUS" << endl;
    cout << "+--------------+" << endl;
    cout << "Rooms Cleared: " << status.getNumRoomsCleared() << " | " << " Keys: " << status.getNumKeyFounds() << " | " << " Anger Level: " << status.getSorcerersAnger() << endl;
    cout << "+--------------+" << endl;
    cout << "INVENTORY" << endl;
    cout << "+--------------+" << endl;
    cout << "Gold: " << characters.getGold() << endl;
    cout << "Ingredients: " << items.getIngredientKg() << endl;
    cout << "Cookware: " << " P: " << items.getNumPot() <<  "| " << " F: " << items.getNumPan() << " | " << " C: "<< items.getNumCauldron()<<  endl;
    cout << "Weapons: " << " C: " << items.getNumClubs() <<  " | " << " S: " << items.getNumSpears() << " | " << " R: "<< items.getNumRapier() << " | " <<  " B: " << items.getNumAxe() << " | " <<  " L: " << items.getNumLongsword() << endl;
    cout << "Armor: " << items.numArmor() <<endl;
    cout << "Treasures: " << items.getNumTreasure() << " | " << " R: " << items.getNumRing() <<  " | " << " N: " << items.getNumNecklace() << " | " << " B: "<< items.getNumBracelet() << " | " <<  " C: " << items.getNumCirclet() << " | " << " G: " << items.getNumGoblet() << endl;
    cout << "+--------------+" << endl;

    char weapon;
    int ingredientkg;
    char cookWare;
    char carmor;

    //start of Merchant Menu
    int optionMerchantMenu = 0;
    while(optionMerchantMenu != 7)
    {
        cout << endl;
        //store0.getPresentStoreDisplay();
        cout << endl;
        cout << "Choose one of the following:" << endl;
        cout << "1. Ingredients: To make food, you have to cook raw ingredients." << endl;
        cout << "2. Cookware: You will need something to cook those ingredients." << endl;
        cout << "3. Weapons: It's dangerous to go alone, take this!" << endl;
        cout << "4. Armor: If you want to survive monster attacks, you will need some armor." << endl;
        cout << "5. Sell treasures: If you find anything shiny, I would be happy to take it off your hands." << endl;
        cout << "6. Leave: Make sure you get everything you need, I'm leaving after this sale!" << endl;
        cin >> optionMerchantMenu;

        if(optionMerchantMenu == 1)
        {
            int ingreds;
            while (ingreds != 1)
            {
                int ingrPrice = floor(1*price);
                cout << "How many kg of ingredients do you need [" << ingrPrice << " Gold/kg]? (Enter a positive mulitple of 5, or 1 to cancel)" << endl;
                cin >> ingreds;
                if (ingreds == 1)
                {
                    break;
                }
                else if (!(ingreds % 5 == 0))
                {
                    cout << "Invalid input." << endl;
                    break;
                }
                char choice;
                cout << "You want to buy " << ingreds << "kg of ingredients for " << ingreds * ingrPrice << " Gold? (y/n)" << endl;
                cin >> choice;
                if (choice == 'y')
                {
                    if(characters.getGold() >= ingreds * ingrPrice)
                    {
                        characters.setGold(ingreds * ingrPrice);
                        cout << "Thank you for your patronage! What else can I get for you?" << endl;
                        items.setIngredientKg(ingreds);
                        cout << "You have " << characters.getGold() << " Gold." << endl;
                        ingreds = 0;
                    }
                    else
                    {
                        cout << "You don't have enough Gold!" << endl;
                        cout << "You have " << characters.getGold() << " Gold." << endl;
                        break;
                    }
                }
                else if (choice == 'n')
                {
                    ingreds = 0;
                }
                else
                {
                    cout << "Invalid input." << endl;
                }
            }
        }
        else if(optionMerchantMenu == 2)
        {
            //item.cookware
            cout << "I have a several types of cookware, which one would you like?" <<endl;
            cout << "Each type has a different probability of breaking when used, marked with (XX%)." << endl;
            cout << endl;
            int choiceCookware;
            while(choiceCookware != 4)
            {
                int ceramic_pot_price = floor(2 * price);
                int frying_pan_price = floor(10 * price);
                int cauldron_price = floor(20 * price);
                cout << "Choose one of the following:" << endl;
                cout << "1. (25%) Ceramic Pot ["<< ceramic_pot_price << " Gold]" << endl;
                cout << "2. (10%) Frying Pan [" << frying_pan_price <<" Gold]" << endl;
                cout << "3. ( 2%) Cauldron [" << cauldron_price << " Gold]" << endl;
                cout << "4. Cancel" << endl;
                cin >> choiceCookware;

                if(choiceCookware == 1)
                {
                    if(characters.getGold() >= ceramic_pot_price)
                    {
                        characters.setGold(ceramic_pot_price);
                        items.setCookware('P');
                        cout << "You bought a Ceramic Pot for " << ceramic_pot_price << " Gold!" << endl;
                        cout << "You have " << characters.getGold() << " Gold." << endl;
                    }
                    else
                    {
                        cout << "You don't have enough Gold to buy a Ceramic Pot!" << endl;
                        cout << "You have " << characters.getGold() << " Gold." << endl;
                    }
                }
                    else if(choiceCookware == 2)
                    {
                        if(characters.getGold() >= frying_pan_price)
                        {
                            characters.setGold(frying_pan_price);
                            items.setCookware('F');
                            cout << "You bought a Frying Pan for " << frying_pan_price << " Gold!" << endl;
                            cout << "You have " << characters.getGold() << " Gold." << endl;
                        }
                        else
                        {
                            cout << "You don't have enough Gold to buy a Frying Pan!" << endl;
                            cout << "You have " << characters.getGold() << " Gold." << endl;
                        }
                    }
                    else if(choiceCookware == 3)
                    {
                        if(characters.getGold() >= cauldron_price)
                        {
                            characters.setGold(cauldron_price);
                            items.setCookware('C');
                            cout << "You bought a Cauldron for " << cauldron_price << " Gold!" << endl;
                            cout << "You have " << characters.getGold() << " Gold." << endl;
                        }
                        else
                        {
                            cout << "You don't have enough Gold to buy a Cauldron!" << endl;
                            cout << "You have " << characters.getGold() << " Gold." << endl;
                        } 
                    }   
                    else if (choiceCookware < 1 || choiceCookware > 4)
                    {
                        cout << "Invalid choice." << endl;
                    }
            }
        }

        else if(optionMerchantMenu == 3)
        {
            cout << "I have a plentiful collection of weapons to choose from, what would you like?" << endl;
            cout << "Note that some of them provide you a special bonus in combat, marked by a (+X)." << endl;
            cout << endl;

            int choiceWeapons;
            while(choiceWeapons != 6)
            {
                    int stone_club_price = floor(2 * price);
                    int iron_spear_price = floor(2 * price);
                    int mythril_rapier_price = floor(5 * price);
                    int flaming_battle_axe_price = floor(15* price);
                    int vorpal_longsword_price = floor(50 * price);
                    
                    cout << "Choose one of the following:" << endl;
                    cout << "1. Stone Club [" << stone_club_price << " Gold]" << endl;
                    cout << "2. Iron Spear [" << iron_spear_price << " Gold]" << endl;
                    cout << "3. (+1) Mythril Rapier [" << mythril_rapier_price << " Gold]" << endl;
                    cout << "4. (+2) Flaming Battle-Axe [" << flaming_battle_axe_price << " Gold]" << endl;
                    cout << "5. (+3) Vorpal Longsword [" << vorpal_longsword_price << " Gold]" << endl;
                    cout << "6. Cancel" << endl;
                    cin >> choiceWeapons;

                if(choiceWeapons == 1)
                {
                    if (characters.getGold() >= stone_club_price)
                    {
                    characters.setGold(stone_club_price);
                    items.setWeapon('C');
                    cout << "You bought a Stone Club for " << stone_club_price << " Gold!" << endl;
                    cout << "You have " << characters.getGold() << " Gold." << endl;
                    }
                    else
                    {
                    cout << "You don't have enough Gold to buy a Stone Club!" << endl;
                    cout << "You have " << characters.getGold() << " Gold." << endl;
                    }
                
                }
                if (choiceWeapons == 2)
                {
                    if(characters.getGold() >= iron_spear_price)
                    {
                        characters.setGold(iron_spear_price);
                        items.setWeapon('S');
                        cout << "You bought an Iron Spear for " << iron_spear_price << " Gold!" << endl;
                        cout << "You have " << characters.getGold() << " Gold." << endl;
                    }
                    else
                    {
                        cout << "You don't have enough Gold to buy an Iron Spear!" << endl;
                        cout << "You have " << characters.getGold() << " Gold." << endl;
                    }
                }

                if (choiceWeapons == 3)
                {
                    if (characters.getGold() >= mythril_rapier_price)
                    {
                        characters.setGold(mythril_rapier_price);
                        items.setWeapon('R');
                        cout << "You bought an Myrthil Reaper for " << mythril_rapier_price << " Gold!" << endl;
                        cout << "You have " << characters.getGold() << " Gold." << endl;
                    }
                    else
                    {
                        cout << "You don't have enough Gold to buy a Mythril Rapier!" << endl;
                        cout << "You have " << characters.getGold() << " Gold." << endl;
                    }
                }

                if (choiceWeapons == 4)
                {
                    if (characters.getGold() >= flaming_battle_axe_price)
                    {
                        characters.setGold(flaming_battle_axe_price);
                        items.setWeapon('B');
                        cout << "You bought a Flaming Battle-Axe for " << flaming_battle_axe_price << " Gold!" << endl;
                        cout << "You have " << characters.getGold() << " Gold." << endl;
                    }
                    else
                    {
                        cout << "You don't have enough Gold to buy a Flaming Battle-Axe!" << endl;
                        cout << "You have " << characters.getGold() << " Gold." << endl;
                    }
                }

                if (choiceWeapons == 5)
                {
                    if (characters.getGold() >= vorpal_longsword_price)
                    {
                        characters.setGold(vorpal_longsword_price);
                        items.setWeapon('L');
                        cout << "You bought a Vorpal Longsword for " << vorpal_longsword_price << " Gold!" << endl;
                        cout << "You have " << characters.getGold() << " Gold." << endl;
                    }
                    else
                    {
                        cout << "You don't have enough Gold to buy a Vorpal Longsword!" << endl;
                        cout << "You have " << characters.getGold() << " Gold." << endl;
                    }
                }
            }



        }
        else if (optionMerchantMenu == 4)
        {
            int armor_price = floor(5 * price);
            int num_arm;
            while (num_arm != 0)
            {
                cout << "How many suits of armor can I get you for " << armor_price << " Gold? (Enter a positive integer, or 0 to cancel)" << endl;
                cin >> num_arm;

                if (num_arm < 0)
                {
                    cout << "Invalid Input." << endl;
                    break;
                }

                if (characters.getGold() >= (num_arm * armor_price))
                {
                    characters.setGold(num_arm * armor_price);
                    cout << "You bought " << num_arm << " armor for " << (num_arm * armor_price) << " Gold!" << endl;
                    cout << "You have " << characters.getGold() << " Gold." << endl;
                    items.setArmor(num_arm);
                }
                else
                {
                    cout << "You don't have enough Gold to buy " << num_arm << " armor!" << endl;
                    cout << "You have " << characters.getGold() << " Gold." << endl;
                }

            }
        }
        else if (optionMerchantMenu == 5)
        {
            char selling;
            while (selling != 'Q')
            {
                int ring_value = floor(10 * price);
                int necklace_value = floor(20 * price);
                int bracelet_value = floor(30 * price);
                int circlet_value = floor(40 * price);
                int goblet_value = floor(50 * price);
                
                cout << "What would you like to sell to me?" << endl;
                cout << "Silver ring (R) - 10 gold pieces each" << endl;
                cout << "Ruby necklace (N) - 20 gold pieces each" << endl;
                cout << "Emerald bracelet (B) - 30 gold pieces each" << endl;
                cout << "Diamond circlet (C) - 40 gold pieces each" << endl;
                cout << "Gem-encrusted goblet (G) - 50 gold pieces each" << endl;
                cout << endl;
                cout << "Please enter either R, N, B, C, G or Q if you would like to quit:" << endl;
                cin >> selling;

                if (selling == 'R')
                {
                    if(items.checkForRing())
                    {
                        characters.setGold(-ring_value);
                        cout << "You just sold a Silver Ring for " << ring_value << " Gold!" << endl;
                        cout << "You have " << characters.getGold() << " Gold." << endl;
                    }
                    else
                    {
                        cout << "you dont have a Silver Ring!" << endl;
                    }
                        
                }
                else if (selling == 'N')
                {
                    if(items.checkForNecklace())
                    {
                        characters.setGold(-necklace_value);
                        cout << "You just sold a Ruby Necklace for " << necklace_value << " Gold!" << endl;
                        cout << "You have " << characters.getGold() << " Gold." << endl;
                    }
                    else
                    {
                        cout << "you dont have a Ruby Necklace!" << endl;
                    }
                }
                else if (selling == 'B')
                {
                    if(items.checkForBracelet())
                    {
                        characters.setGold(-bracelet_value);
                        cout << "You just sold an Emerald Bracelet for " << bracelet_value << " Gold!" << endl;
                        cout << "You have " << characters.getGold() << " Gold." << endl;
                    }
                    else
                    {
                        cout << "you dont have an Emerald Bracelet!" << endl;
                    }
                }
                else if (selling == 'C')
                {
                    if(items.checkForCirclet())
                    {
                        characters.setGold(-circlet_value);
                        cout << "You just sold a Diamond Circlet for " << circlet_value << " Gold!" << endl;
                        cout << "You have " << characters.getGold() << " Gold." << endl;
                    }
                    else
                    {
                        cout << "you dont have a Diamond Circlet!" << endl;
                    }
                }
                else if (selling == 'G')
                {
                    if(items.checkForGoblet())
                    {
                        characters.setGold(-goblet_value);
                        cout << "You just sold a Gem-encrusted goblet for " << goblet_value << " Gold!" << endl;
                        cout << "You have " << characters.getGold() << " Gold." << endl;
                    }
                    else
                    {
                        cout << "you dont have a Gem-encrusted goblet!" << endl;
                    }
                }
            }            
        }
        else if (optionMerchantMenu == 6)
        {
            char decision;
            cout << "Are you sure you're finished? You won't be able to buy anything else from me! (y/n)" << endl;
            cin >> decision;
            if (decision == 'y')
            {
                optionMerchantMenu = 7;
                cout << "Good luck out there!" << endl;
            }
            else if (decision == 'n')
            {
                break;
            }
            else
            {
                cout << "Invalid Input." << endl;
            }
        }
    }
    // End of Merchant Menu Buy

    cout << endl;
    cout << endl;

    for(int i = 1; i <= 4; i++) {
        for(int j = 1; j <= i; ++j) 
        {
            cout << "* ";
        }
        cout << endl;
    }
    cout << "+--------------+" << endl;
    cout << "STATUS" << endl;
    cout << "+--------------+" << endl;
    cout << "Rooms Cleared: " << status.getNumRoomsCleared() << " | " << " Keys: " << status.getNumKeyFounds() << " | " << " Anger Level: " << status.getSorcerersAnger() << endl;
    cout << "+--------------+" << endl;
    cout << "INVENTORY" << endl;
    cout << "+--------------+" << endl;
    cout << "Gold: " << characters.getGold() << endl;
    cout << "Ingredients: " << items.getIngredientKg() << endl;
    cout << "Cookware: " << " P: " << items.getNumPot() <<  "| " << " F: " << items.getNumPan() << " | " << " C: "<< items.getNumCauldron()<<  endl;
    cout << "Weapons: " << " C: " << items.getNumClubs() <<  " | " << " S: " << items.getNumSpears() << " | " << " R: "<< items.getNumRapier() << " | " <<  " B: " << items.getNumAxe() << " | " <<  " L: " << items.getNumLongsword() << endl;
    cout << "Armor: " << items.numArmor() <<endl;
    cout << "Treasures: " << items.getNumTreasure() << " | " << " R: " << items.getNumRing() <<  " | " << " N: " << items.getNumNecklace() << " | " << " B: "<< items.getNumBracelet() << " | " <<  " C: " << items.getNumCirclet() << " | " << " G: " << items.getNumGoblet() << endl;
    cout << "+--------------+" << endl;
    cout << characters.getPlayerName() << " | " << " Fullness: " << characters.getHealthMain() << endl;
    if (characters.isN1Alive())
    {
        cout << characters.getn1Name() << " | " << " Fullness: " << characters.getHealth1() << endl;
    }
    if (characters.isN2Alive())
    {
        cout << characters.getn2Name() << " | " << " Fullness: " << characters.getHealth2() << endl;
    }
    if(characters.isN3Alive())
    {
        cout << characters.getn3Name() << " | " << " Fullness: " << characters.getHealth3() << endl;
    }
    if(characters.isN4Alive())
    {
        cout << characters.getn4Name() << " | " << " Fullness: " << characters.getHealth4() << endl;
    }
    cout << "+--------------+" << endl;
    if (characters.getTotalCharacters() <= 1)
    {
        endGame(characters,items,status);
    }
    if (status.getSorcerersAnger() >= 100)
    {
        endGame(characters,items,status);
    }

    

    //setting up random map
    int s = 0;
    int rands;
    int random1;
    int random2;

    while(map.getRoomCount() < 5)
    {
        random1 = random(1, 15, s);
        rands = random(1, 15, s);
        random2 = random(1, 15, rands);
        map.addRoom(random1, random2);
        s++;
    }
    while (map.getNPCCount() < 5)
    {
        random1 = random(1, 15, s);
        rands = random(1, 15, s);
        random2 = random(1, 15, rands);
        map.addNPC(random1, random2);
        s++;
    }

    int choiceMove;  // for storing user input

    while( choiceMove != 5)
    {
        if (status.getNumRoomsCleared() >= 5)
        {
            //so that after defeating the sorcerer the player has no choice but to go to the exit
            if (choiceMove == 2 || choiceMove == 3 || choiceMove == 4)
            {
                cout << "Head toward the exit!" << endl;
                continue;
            }
        }
        map.displayMap();
        cout << "Select one: " << endl;
        cout << "1. Move" << endl;
        cout << "2. Investigate" << endl;
        cout << "3. Pick a Fight" << endl;
        cout << "4. Cook and Eat" << endl;
        cout << "5. Give up" << endl;

        cin >> choiceMove;
        //moving
        if(choiceMove == 1)
        {
            char direction1;
            cout << "Which way would you like to move (w, s, a, d)?" << endl;
            cin >> direction1;

            if (direction1 == 'w')
            {
                map.move('w');
            }
            else if (direction1 == 's')
            {
                map.move('s');
            }
            else if (direction1 == 'a')
            {
                map.move('a');
            }
            else if (direction1 == 'd')
            {
                map.move('d');
            }
            else
            {
                cout << "Invalid input." << endl;
                continue;
            }

            //increase sorcerer's anger if spot moved to has not been explored yet
            if(!(map.isExplored(map.getPlayerRow(), map.getPlayerCol())))
            {
                status.setSorcerersAnger(1);
            }
            //do nothing
            if (map.isFreeSpace(map.getPlayerRow(), map.getPlayerCol()))
            {
                
                status.setNumTurns(1);

                cout << "+--------------+" << endl;
                cout << "STATUS" << endl;
                cout << "+--------------+" << endl;
                cout << "Rooms Cleared: " << status.getNumRoomsCleared() << " | " << " Keys: " << status.getNumKeyFounds() << " | " << " Anger Level: " << status.getSorcerersAnger() << endl;
                cout << "+--------------+" << endl;
                cout << "INVENTORY" << endl;
                cout << "+--------------+" << endl;
                cout << "Gold: " << characters.getGold() << endl;
                cout << "Ingredients: " << items.getIngredientKg() << endl;
                cout << "Cookware: " << " P: " << items.getNumPot() <<  "| " << " F: " << items.getNumPan() << " | " << " C: "<< items.getNumCauldron()<<  endl;
                cout << "Weapons: " << " C: " << items.getNumClubs() <<  " | " << " S: " << items.getNumSpears() << " | " << " R: "<< items.getNumRapier() << " | " <<  " B: " << items.getNumAxe() << " | " <<  " L: " << items.getNumLongsword() << endl;
                cout << "Armor: " << items.numArmor() <<endl;
                cout << "Treasures: " << items.getNumTreasure() << " | " << " R: " << items.getNumRing() <<  " | " << " N: " << items.getNumNecklace() << " | " << " B: "<< items.getNumBracelet() << " | " <<  " C: " << items.getNumCirclet() << " | " << " G: " << items.getNumGoblet() << endl;
                cout << "+--------------+" << endl;
                cout << characters.getPlayerName() << " | " << " Fullness: " << characters.getHealthMain() << endl;
                if (characters.isN1Alive())
                {
                    cout << characters.getn1Name() << " | " << " Fullness: " << characters.getHealth1() << endl;
                }
                if (characters.isN2Alive())
                {
                    cout << characters.getn2Name() << " | " << " Fullness: " << characters.getHealth2() << endl;
                }
                if(characters.isN3Alive())
                {
                    cout << characters.getn3Name() << " | " << " Fullness: " << characters.getHealth3() << endl;
                }
                if(characters.isN4Alive())
                {
                    cout << characters.getn4Name() << " | " << " Fullness: " << characters.getHealth4() << endl;
                }
                cout << "+--------------+" << endl;
                if (characters.getTotalCharacters() <= 1)
                {
                    endGame(characters,items,status);
                }
                if (status.getSorcerersAnger() >= 100)
                {
                    endGame(characters,items,status);
                }
                continue;
            }
            //check if npc location
            else if( map.isNPCLocation(map.getPlayerRow(), map.getPlayerCol()) ) 
            {
                string mons;
                int pow = status.getNumRoomsCleared();
                Monsters monster(mons, pow);
                int NPCaction;
                cout << "You just met an NPC! What do you want to do?" << endl;
                cout << "1. Ignore" << endl;
                cout << "2. Speak to NPC (if you solve a riddle, they might sell you new items!)" << endl;
                cout << "3. Give up" << endl;

                cin >> NPCaction;

                    if (NPCaction == 1)
                    {
                        continue;
                    }
                    else if (NPCaction == 2)
                    {
                        // Open the file
                        ifstream file("NPC.txt");

                        // Count the total number of lines
                        int numLines = 0;
                        string line;
                        while (getline(file, line)) 
                        {
                            numLines++;
                        }

                        // Generate a random line number
                        srand(time(0)); // Seed the random number generator
                        int randomLineNum = rand() % numLines + 1;

                        // Reset file position to the beginning
                        file.clear();
                        file.seekg(0);

                        // Get the randomly selected line
                        int currentLineNum = 0;
                        string randomLine;
                        while (getline(file, line)) 
                        {
                            currentLineNum++;
                            if (currentLineNum == randomLineNum) 
                            {
                                randomLine = line;
                                break;
                            }
                        }

                        // Close the file
                        file.close();
                        string answer;
                        cout << randomLine << endl;
                        bool merchant_menu = false;
                        bool fight = false;

                        //check every single riddle and act accoringly
                        if (randomLineNum == 1)
                        {
                            while (answer != "candle")
                            {
                                cin >> answer;
                                if (answer != "candle")
                                {
                                    cout << "Wrong answer, try again (if you would like to quit, enter Q): ";
                                }
                                if (answer == "Q")
                                {
                                    NPCaction = 3;
                                }
                            }
                            cout << "Correct!" << endl;
                            char yesorno;
                            cout << "Do you wish to barter for goods? (y/n)" << endl;
                            cin >> yesorno;

                            map.removeNPC(map.getPlayerRow(), map.getPlayerCol());
                            if (yesorno == 'y')
                            {
                                merchant_menu == true;
                                
                            }
                            else if (yesorno == 'n')
                            {
                                fight = true;
                            }
                        }
                        else if (randomLineNum == 2)
                        {
                            while (answer != "map")
                            {
                                cin >> answer;
                                if (answer != "map")
                                {
                                    cout << "Wrong answer, try again (if you would like to quit, enter Q): ";
                                }
                                if (answer == "Q")
                                {
                                    NPCaction = 3;
                                }
                            }
                            cout << "Correct!" << endl;
                            char yesorno;
                            cout << "Do you wish to barter for goods? (y/n)" << endl;
                            cin >> yesorno;

                            map.removeNPC(map.getPlayerRow(), map.getPlayerCol());
                            if (yesorno == 'y')
                            {
                                merchant_menu = true;
                                
                            }
                            else if (yesorno == 'n')
                            {
                                fight = true;
                            }
                        }
                        else if (randomLineNum == 3)
                        {
                            while (answer != "r")
                            {
                                cin >> answer;
                                if (answer != "r")
                                {
                                    cout << "Wrong answer, try again (if you would like to quit, enter Q): ";
                                }
                                if (answer == "Q")
                                {
                                    NPCaction = 3;
                                }
                            }
                            cout << "Correct!" << endl;
                            char yesorno;
                            cout << "Do you wish to barter for goods? (y/n)" << endl;
                            cin >> yesorno;

                            map.removeNPC(map.getPlayerRow(), map.getPlayerCol());
                            if (yesorno == 'y')
                            {
                                merchant_menu = true;
                                
                            }
                            else if (yesorno == 'n')
                            {
                                fight = true;
                            }
                        }
                        else if (randomLineNum == 4)
                        {
                            while (answer != "heroine")
                            {
                                cin >> answer;
                                if (answer != "heroine")
                                {
                                    cout << "Wrong answer, try again (if you would like to quit, enter Q): ";
                                }
                                if (answer == "Q")
                                {
                                    NPCaction = 3;
                                }
                            }
                            cout << "Correct!" << endl;
                            char yesorno;
                            cout << "Do you wish to barter for goods? (y/n)" << endl;
                            cin >> yesorno;

                            map.removeNPC(map.getPlayerRow(), map.getPlayerCol());
                            if (yesorno == 'y')
                            {
                                merchant_menu = true;
                                
                            }
                            else if (yesorno == 'n')
                            {
                                fight = true;
                            }
                        }
                        else if (randomLineNum == 5)
                        {
                            while (answer != "bookkeeper")
                            {
                                cin >> answer;
                                if (answer != "bookkeeper")
                                {
                                    cout << "Wrong answer, try again (if you would like to quit, enter Q): ";
                                }
                                if (answer == "Q")
                                {
                                    NPCaction = 3;
                                }
                            }
                            cout << "Correct!" << endl;
                            char yesorno;
                            cout << "Do you wish to barter for goods? (y/n)" << endl;
                            cin >> yesorno;

                            map.removeNPC(map.getPlayerRow(), map.getPlayerCol());
                            if (yesorno == 'y')
                            {
                                merchant_menu = true;
                                
                            }
                            else if (yesorno == 'n')
                            {
                                fight = true;
                            }
                        }
                        else if (randomLineNum == 6)
                        {
                            while (answer != "silence")
                            {
                                cin >> answer;
                                if (answer != "silence")
                                {
                                    cout << "Wrong answer, try again (if you would like to quit, enter Q): ";
                                }
                                if (answer == "Q")
                                {
                                    NPCaction = 3;
                                }
                            }
                            cout << "Correct!" << endl;
                            char yesorno;
                            cout << "Do you wish to barter for goods? (y/n)" << endl;
                            cin >> yesorno;

                            map.removeNPC(map.getPlayerRow(), map.getPlayerCol());
                            if (yesorno == 'y')
                            {
                                merchant_menu = true;
                                
                            }
                            else if (yesorno == 'n')
                            {
                                fight = true;
                            }
                        }
                        else if (randomLineNum == 7)
                        {
                            while (answer != "keyboard")
                            {
                                cin >> answer;
                                if (answer != "keyboard")
                                {
                                    cout << "Wrong answer, try again (if you would like to quit, enter Q): ";
                                }
                                if (answer == "Q")
                                {
                                    NPCaction = 3;
                                }
                            }
                            cout << "Correct!" << endl;
                            char yesorno;
                            cout << "Do you wish to barter for goods? (y/n)" << endl;
                            cin >> yesorno;

                            map.removeNPC(map.getPlayerRow(), map.getPlayerCol());
                            if (yesorno == 'y')
                            {
                                merchant_menu = true;
                                
                            }
                            else if (yesorno == 'n')
                            {
                                fight = true;
                            }
                        }
                        else if (randomLineNum == 8)
                        {
                            while (answer != "towel")
                            {
                                cin >> answer;
                                if (answer != "towel")
                                {
                                    cout << "Wrong answer, try again (if you would like to quit, enter Q): ";
                                }
                                if (answer == "Q")
                                {
                                    NPCaction = 3;
                                }
                            }
                            cout << "Correct!" << endl;
                            char yesorno;
                            cout << "Do you wish to barter for goods? (y/n)" << endl;
                            cin >> yesorno;

                            map.removeNPC(map.getPlayerRow(), map.getPlayerCol());
                            if (yesorno == 'y')
                            {
                                merchant_menu = true;
                                
                            }
                            else if (yesorno == 'n')
                            {
                                fight = true;
                            }
                        }
                        else if (randomLineNum == 9)
                        {
                            while (answer != "11")
                            {
                                cin >> answer;
                                if (answer != "11")
                                {
                                    cout << "Wrong answer, try again (if you would like to quit, enter Q): ";
                                }
                                if (answer == "Q")
                                {
                                    NPCaction = 3;
                                }
                            }
                            cout << "Correct!" << endl;
                            char yesorno;
                            cout << "Do you wish to barter for goods? (y/n)" << endl;
                            cin >> yesorno;

                            map.removeNPC(map.getPlayerRow(), map.getPlayerCol());
                            if (yesorno == 'y')
                            {
                                merchant_menu = true;
                                
                            }
                            else if (yesorno == 'n')
                            {
                                fight = true;
                            }
                        }
                        else if (randomLineNum == 10)
                        {
                            while (answer != "ENT")
                            {
                                cin >> answer;
                                if (answer != "ENT")
                                {
                                    cout << "Wrong answer, try again (if you would like to quit, enter Q): ";
                                }
                                if (answer == "Q")
                                {
                                    NPCaction = 3;
                                }
                            }
                            cout << "Correct!" << endl;
                            char yesorno;
                            cout << "Do you wish to barter for goods? (y/n)" << endl;
                            cin >> yesorno;

                            map.removeNPC(map.getPlayerRow(), map.getPlayerCol());
                            if (yesorno == 'y')
                            {
                                merchant_menu = true;
                                
                            }
                            else if (yesorno == 'n')
                            {
                                fight = true;
                            }
                        }
                        else if (randomLineNum == 11)
                        {
                            while (answer != "fishhook")
                            {
                                cin >> answer;
                                if (answer != "fishhook")
                                {
                                    cout << "Wrong answer, try again (if you would like to quit, enter Q): ";
                                }
                                if (answer == "Q")
                                {
                                    NPCaction = 3;
                                }
                            }
                            cout << "Correct!" << endl;
                            char yesorno;
                            cout << "Do you wish to barter for goods? (y/n)" << endl;
                            cin >> yesorno;

                            map.removeNPC(map.getPlayerRow(), map.getPlayerCol());
                            if (yesorno == 'y')
                            {
                                merchant_menu = true;
                                
                            }
                            else if (yesorno == 'n')
                            {
                                fight = true;
                            }
                        }
                        else if (randomLineNum == 12)
                        {
                            while (answer != "m")
                            {
                                cin >> answer;
                                if (answer != "m")
                                {
                                    cout << "Wrong answer, try again (if you would like to quit, enter Q): ";
                                }
                                if (answer == "Q")
                                {
                                    NPCaction = 3;
                                }
                            }
                            cout << "Correct!" << endl;
                            char yesorno;
                            cout << "Do you wish to barter for goods? (y/n)" << endl;
                            cin >> yesorno;

                            map.removeNPC(map.getPlayerRow(), map.getPlayerCol());
                            if (yesorno == 'y')
                            {
                                merchant_menu = true;
                                
                            }
                            else if (yesorno == 'n')
                            {
                                fight = true;
                            }
                        }
                        else if (randomLineNum == 13)
                        {
                            while (answer != "incorrectly")
                            {
                                cin >> answer;
                                if (answer != "incorrectly")
                                {
                                    cout << "Wrong answer, try again (if you would like to quit, enter Q): ";
                                }
                                if (answer == "Q")
                                {
                                    NPCaction = 3;
                                }
                            }
                            cout << "Correct!" << endl;
                            char yesorno;
                            cout << "Do you wish to barter for goods? (y/n)" << endl;
                            cin >> yesorno;

                            map.removeNPC(map.getPlayerRow(), map.getPlayerCol());
                            if (yesorno == 'y')
                            {
                                merchant_menu = true;
                                
                            }
                            else if (yesorno == 'n')
                            {
                                fight = true;
                            }
                        }
                        else if (randomLineNum == 14)
                        {
                            while (answer != "umbrella")
                            {
                                cin >> answer;
                                if (answer != "umbrella")
                                {
                                    cout << "Wrong answer, try again (if you would like to quit, enter Q): ";
                                }
                                if (answer == "Q")
                                {
                                    NPCaction = 3;
                                }
                            }
                            cout << "Correct!" << endl;
                            char yesorno;
                            cout << "Do you wish to barter for goods? (y/n)" << endl;
                            cin >> yesorno;

                            map.removeNPC(map.getPlayerRow(), map.getPlayerCol());
                            if (yesorno == 'y')
                            {
                                merchant_menu = true;
                                
                            }
                            else if (yesorno == 'n')
                            {
                                fight = true;
                            }
                        }
                        else if (randomLineNum == 15)
                        {
                            while (answer != "coin")
                            {
                                cin >> answer;
                                if (answer != "coin")
                                {
                                    cout << "Wrong answer, try again (if you would like to quit, enter Q): ";
                                }
                                if (answer == "Q")
                                {
                                    NPCaction = 3;
                                }
                            }
                            cout << "Correct!" << endl;
                            char yesorno;
                            cout << "Do you wish to barter for goods? (y/n)" << endl;
                            cin >> yesorno;

                            map.removeNPC(map.getPlayerRow(), map.getPlayerCol());
                            if (yesorno == 'y')
                            {
                                merchant_menu = true;
                                
                            }
                            else if (yesorno == 'n')
                            {
                                fight = true;
                            }
                        }
                        else if (randomLineNum == 16)
                        {
                            while (answer != "alone")
                            {
                                cin >> answer;
                                if (answer != "alone")
                                {
                                    cout << "Wrong answer, try again (if you would like to quit, enter Q): ";
                                }
                                if (answer == "Q")
                                {
                                    NPCaction = 3;
                                }
                            }
                            cout << "Correct!" << endl;
                            char yesorno;
                            cout << "Do you wish to barter for goods? (y/n)" << endl;
                            cin >> yesorno;

                            map.removeNPC(map.getPlayerRow(), map.getPlayerCol());
                            if (yesorno == 'y')
                            {
                                merchant_menu = true;
                                
                            }
                            else if (yesorno == 'n')
                            {
                                fight = true;
                            }
                        }
                        else if (randomLineNum == 17)
                        {
                            while (answer != "crows")
                            {
                                cin >> answer;
                                if (answer != "crows")
                                {
                                    cout << "Wrong answer, try again (if you would like to quit, enter Q): ";
                                }
                                if (answer == "Q")
                                {
                                    NPCaction = 3;
                                }
                            }
                            cout << "Correct!" << endl;
                            char yesorno;
                            cout << "Do you wish to barter for goods? (y/n)" << endl;
                            cin >> yesorno;

                            map.removeNPC(map.getPlayerRow(), map.getPlayerCol());
                            if (yesorno == 'y')
                            {
                                merchant_menu = true;
                                
                            }
                            else if (yesorno == 'n')
                            {
                                fight = true;
                            }
                        }
                        else if (randomLineNum == 18)
                        {
                            while (answer != "beauty")
                            {
                                cin >> answer;
                                if (answer != "beauty")
                                {
                                    cout << "Wrong answer, try again (if you would like to quit, enter Q): ";
                                }
                                if (answer == "Q")
                                {
                                    NPCaction = 3;
                                }
                            }
                            cout << "Correct!" << endl;
                            char yesorno;
                            cout << "Do you wish to barter for goods? (y/n)" << endl;
                            cin >> yesorno;

                            map.removeNPC(map.getPlayerRow(), map.getPlayerCol());
                            if (yesorno == 'y')
                            {
                                merchant_menu = true;
                                
                            }
                            else if (yesorno == 'n')
                            {
                                fight = true;
                            }
                        }
                        else if (randomLineNum == 19)
                        {
                            while (answer != "3")
                            {
                                cin >> answer;
                                if (answer != "3")
                                {
                                    cout << "Wrong answer, try again (if you would like to quit, enter Q): ";
                                }
                                if (answer == "Q")
                                {
                                    NPCaction = 3;
                                }
                            }
                            cout << "Correct!" << endl;
                            char yesorno;
                            cout << "Do you wish to barter for goods? (y/n)" << endl;
                            cin >> yesorno;

                            map.removeNPC(map.getPlayerRow(), map.getPlayerCol());
                            if (yesorno == 'y')
                            {
                                merchant_menu = true;
                                
                            }
                            else if (yesorno == 'n')
                            {
                                fight = true;
                            }
                        }
                        else if (randomLineNum == 20)
                        {
                            while (answer != "bubble")
                            {
                                cin >> answer;
                                if (answer != "bubble")
                                {
                                    cout << "Wrong answer, try again (if you would like to quit, enter Q): ";
                                }
                                if (answer == "Q")
                                {
                                    NPCaction = 3;
                                }
                            }
                            cout << "Correct!" << endl;
                            char yesorno;
                            cout << "Do you wish to barter for goods? (y/n)" << endl;
                            cin >> yesorno;
                            map.removeNPC(map.getPlayerRow(), map.getPlayerCol());

                            if (yesorno == 'y')
                            {
                                merchant_menu = true;
                                
                            }
                            else if (yesorno == 'n')
                            {
                                fight = true;
                            }
                        }

                        //if riddle is correct and player decides to look at menu, here it is.
                        if (merchant_menu == true)
                        {
                            double price;
                            if (status.getNumRoomsCleared() == 0)
                            {
                                price = 1.00;
                            }
                            else if (status.getNumRoomsCleared() == 1)
                            {
                                price = 1.25;
                            }
                            else if (status.getNumRoomsCleared() == 2)
                            {
                                price = 1.50;
                            }
                            else if (status.getNumRoomsCleared() == 3)
                            {
                                price = 1.75;
                            }
                            else if (status.getNumRoomsCleared() == 4)
                            {
                                price = 2.00;
                            }
                                cout << "If you're looking to get supplies, you've come to the right place." << endl;
                                cout << "I would be happy to part with some of my wares...for the proper price!" << endl;
                                cout << endl;

                                char weapon;
                                int ingredientkg;
                                char cookWare;
                                char carmor;

                                //start of Merchant Menu
                                int optionMerchantMenu = 0;
                                while(optionMerchantMenu != 7)
                                {
                                    cout << endl;
                                    //store0.getPresentStoreDisplay();
                                    cout << endl;
                                    cout << "Choose one of the following:" << endl;
                                    cout << "1. Ingredients: To make food, you have to cook raw ingredients." << endl;
                                    cout << "2. Cookware: You will need something to cook those ingredients." << endl;
                                    cout << "3. Weapons: It's dangerous to go alone, take this!" << endl;
                                    cout << "4. Armor: If you want to survive monster attacks, you will need some armor." << endl;
                                    cout << "5. Sell treasures: If you find anything shiny, I would be happy to take it off your hands." << endl;
                                    cout << "6. Leave: Make sure you get everything you need, I'm leaving after this sale!" << endl;
                                    cin >> optionMerchantMenu;

                                    if(optionMerchantMenu == 1)
                                    {
                                        int ingreds;
                                        while (ingreds != 1)
                                        {
                                            int ingrPrice = floor(1*price);
                                            cout << "How many kg of ingredients do you need [" << ingrPrice << " Gold/kg]? (Enter a positive mulitple of 5, or 1 to cancel)" << endl;
                                            cin >> ingreds;
                                            if (ingreds == 1)
                                            {
                                                break;
                                            }
                                            else if (!(ingreds % 5 == 0))
                                            {
                                                cout << "Invalid input." << endl;
                                                break;
                                            }
                                            char choice;
                                            cout << "You want to buy " << ingreds << "kg of ingredients for " << ingreds * ingrPrice << " Gold? (y/n)" << endl;
                                            cin >> choice;
                                            if (choice == 'y')
                                            {
                                                if(characters.getGold() >= ingreds * ingrPrice)
                                                {
                                                    characters.setGold(ingreds * ingrPrice);
                                                    cout << "Thank you for your patronage! What else can I get for you?" << endl;
                                                    items.setIngredientKg(ingreds);
                                                    cout << "You have " << characters.getGold() << " Gold." << endl;
                                                    ingreds = 0;
                                                }
                                                else
                                                {
                                                    cout << "You don't have enough Gold!" << endl;
                                                    cout << "You have " << characters.getGold() << " Gold." << endl;
                                                    break;
                                                }
                                            }
                                            else if (choice == 'n')
                                            {
                                                ingreds = 0;
                                            }
                                            else
                                            {
                                                cout << "Invalid input." << endl;
                                            }
                                        }
                                    }
                                    else if(optionMerchantMenu == 2)
                                    {
                                        //item.cookware
                                        cout << "I have a several types of cookware, which one would you like?" <<endl;
                                        cout << "Each type has a different probability of breaking when used, marked with (XX%)." << endl;
                                        cout << endl;
                                        int choiceCookware;
                                        while(choiceCookware != 4)
                                        {
                                            int ceramic_pot_price = floor(2 * price);
                                            int frying_pan_price = floor(10 * price);
                                            int cauldron_price = floor(20 * price);
                                            cout << "Choose one of the following:" << endl;
                                            cout << "1. (25%) Ceramic Pot ["<< ceramic_pot_price << " Gold]" << endl;
                                            cout << "2. (10%) Frying Pan [" << frying_pan_price <<" Gold]" << endl;
                                            cout << "3. ( 2%) Cauldron [" << cauldron_price << " Gold]" << endl;
                                            cout << "4. Cancel" << endl;
                                            cin >> choiceCookware;

                                            if(choiceCookware == 1)
                                            {
                                                if(characters.getGold() >= ceramic_pot_price)
                                                {
                                                    characters.setGold(ceramic_pot_price);
                                                    items.setCookware('P');
                                                    cout << "You bought a Ceramic Pot for " << ceramic_pot_price << " Gold!" << endl;
                                                    cout << "You have " << characters.getGold() << " Gold." << endl;
                                                }
                                                else
                                                {
                                                    cout << "You don't have enough Gold to buy a Ceramic Pot!" << endl;
                                                    cout << "You have " << characters.getGold() << " Gold." << endl;
                                                }
                                            }
                                                else if(choiceCookware == 2)
                                                {
                                                    if(characters.getGold() >= frying_pan_price)
                                                    {
                                                        characters.setGold(frying_pan_price);
                                                        items.setCookware('F');
                                                        cout << "You bought a Frying Pan for " << frying_pan_price << " Gold!" << endl;
                                                        cout << "You have " << characters.getGold() << " Gold." << endl;
                                                    }
                                                    else
                                                    {
                                                        cout << "You don't have enough Gold to buy a Frying Pan!" << endl;
                                                        cout << "You have " << characters.getGold() << " Gold." << endl;
                                                    }
                                                }
                                                else if(choiceCookware == 3)
                                                {
                                                    if(characters.getGold() >= cauldron_price)
                                                    {
                                                        characters.setGold(cauldron_price);
                                                        items.setCookware('C');
                                                        cout << "You bought a Cauldron for " << cauldron_price << " Gold!" << endl;
                                                        cout << "You have " << characters.getGold() << " Gold." << endl;
                                                    }
                                                    else
                                                    {
                                                        cout << "You don't have enough Gold to buy a Cauldron!" << endl;
                                                        cout << "You have " << characters.getGold() << " Gold." << endl;
                                                    } 
                                                }   
                                                else if (choiceCookware < 1 || choiceCookware > 4)
                                                {
                                                    cout << "Invalid choice." << endl;
                                                }
                                        }
                                    }

                                    else if(optionMerchantMenu == 3)
                                    {
                                        cout << "I have a plentiful collection of weapons to choose from, what would you like?" << endl;
                                        cout << "Note that some of them provide you a special bonus in combat, marked by a (+X)." << endl;
                                        cout << endl;

                                        int choiceWeapons;
                                        while(choiceWeapons != 6)
                                        {
                                                int stone_club_price = floor(2 * price);
                                                int iron_spear_price = floor(2 * price);
                                                int mythril_rapier_price = floor(5 * price);
                                                int flaming_battle_axe_price = floor(15* price);
                                                int vorpal_longsword_price = floor(50 * price);
                                                
                                                cout << "Choose one of the following:" << endl;
                                                cout << "1. Stone Club [" << stone_club_price << " Gold]" << endl;
                                                cout << "2. Iron Spear [" << iron_spear_price << " Gold]" << endl;
                                                cout << "3. (+1) Mythril Rapier [" << mythril_rapier_price << " Gold]" << endl;
                                                cout << "4. (+2) Flaming Battle-Axe [" << flaming_battle_axe_price << " Gold]" << endl;
                                                cout << "5. (+3) Vorpal Longsword [" << vorpal_longsword_price << " Gold]" << endl;
                                                cout << "6. Cancel" << endl;
                                                cin >> choiceWeapons;

                                            if(choiceWeapons == 1)
                                            {
                                                if (characters.getGold() >= stone_club_price)
                                                {
                                                characters.setGold(stone_club_price);
                                                items.setWeapon('C');
                                                cout << "You bought a Stone Club for " << stone_club_price << " Gold!" << endl;
                                                cout << "You have " << characters.getGold() << " Gold." << endl;
                                                }
                                                else
                                                {
                                                cout << "You don't have enough Gold to buy a Stone Club!" << endl;
                                                cout << "You have " << characters.getGold() << " Gold." << endl;
                                                }
                                            
                                            }
                                            if (choiceWeapons == 2)
                                            {
                                                if(characters.getGold() >= iron_spear_price)
                                                {
                                                    characters.setGold(iron_spear_price);
                                                    items.setWeapon('S');
                                                    cout << "You bought an Iron Spear for " << iron_spear_price << " Gold!" << endl;
                                                    cout << "You have " << characters.getGold() << " Gold." << endl;
                                                }
                                                else
                                                {
                                                    cout << "You don't have enough Gold to buy an Iron Spear!" << endl;
                                                    cout << "You have " << characters.getGold() << " Gold." << endl;
                                                }
                                            }

                                            if (choiceWeapons == 3)
                                            {
                                                if (characters.getGold() >= mythril_rapier_price)
                                                {
                                                    characters.setGold(mythril_rapier_price);
                                                    items.setWeapon('R');
                                                    cout << "You bought an Myrthil Reaper for " << mythril_rapier_price << " Gold!" << endl;
                                                    cout << "You have " << characters.getGold() << " Gold." << endl;
                                                }
                                                else
                                                {
                                                    cout << "You don't have enough Gold to buy a Mythril Rapier!" << endl;
                                                    cout << "You have " << characters.getGold() << " Gold." << endl;
                                                }
                                            }

                                            if (choiceWeapons == 4)
                                            {
                                                if (characters.getGold() >= flaming_battle_axe_price)
                                                {
                                                    characters.setGold(flaming_battle_axe_price);
                                                    items.setWeapon('B');
                                                    cout << "You bought a Flaming Battle-Axe for " << flaming_battle_axe_price << " Gold!" << endl;
                                                    cout << "You have " << characters.getGold() << " Gold." << endl;
                                                }
                                                else
                                                {
                                                    cout << "You don't have enough Gold to buy a Flaming Battle-Axe!" << endl;
                                                    cout << "You have " << characters.getGold() << " Gold." << endl;
                                                }
                                            }

                                            if (choiceWeapons == 5)
                                            {
                                                if (characters.getGold() >= vorpal_longsword_price)
                                                {
                                                    characters.setGold(vorpal_longsword_price);
                                                    items.setWeapon('L');
                                                    cout << "You bought a Vorpal Longsword for " << vorpal_longsword_price << " Gold!" << endl;
                                                    cout << "You have " << characters.getGold() << " Gold." << endl;
                                                }
                                                else
                                                {
                                                    cout << "You don't have enough Gold to buy a Vorpal Longsword!" << endl;
                                                    cout << "You have " << characters.getGold() << " Gold." << endl;
                                                }
                                            }
                                        }



                                    }
                                    else if (optionMerchantMenu == 4)
                                    {
                                        int armor_price = floor(5 * price);
                                        int num_arm;
                                        while (num_arm != 0)
                                        {
                                            cout << "How many suits of armor can I get you for " << armor_price << " Gold? (Enter a positive integer, or 0 to cancel)" << endl;
                                            cin >> num_arm;

                                            if (num_arm < 0)
                                            {
                                                cout << "Invalid Input." << endl;
                                                break;
                                            }

                                            if (characters.getGold() >= (num_arm * armor_price))
                                            {
                                                characters.setGold(num_arm * armor_price);
                                                cout << "You bought " << num_arm << " armor for " << (num_arm * armor_price) << " Gold!" << endl;
                                                cout << "You have " << characters.getGold() << " Gold." << endl;
                                                items.setArmor(num_arm);
                                            }
                                            else
                                            {
                                                cout << "You don't have enough Gold to buy " << num_arm << " armor!" << endl;
                                                cout << "You have " << characters.getGold() << " Gold." << endl;
                                            }

                                        }
                                    }
                                    else if (optionMerchantMenu == 5)
                                    {
                                        char selling;
                                        while (selling != 'Q')
                                        {
                                            int ring_value = floor(10 * price);
                                            int necklace_value = floor(20 * price);
                                            int bracelet_value = floor(30 * price);
                                            int circlet_value = floor(40 * price);
                                            int goblet_value = floor(50 * price);
                                            
                                            cout << "What would you like to sell to me?" << endl;
                                            cout << "Silver ring (R) - 10 gold pieces each" << endl;
                                            cout << "Ruby necklace (N) - 20 gold pieces each" << endl;
                                            cout << "Emerald bracelet (B) - 30 gold pieces each" << endl;
                                            cout << "Diamond circlet (C) - 40 gold pieces each" << endl;
                                            cout << "Gem-encrusted goblet (G) - 50 gold pieces each" << endl;
                                            cout << endl;
                                            cout << "Please enter either R, N, B, C, G or Q if you would like to quit:" << endl;
                                            cin >> selling;

                                            if (selling == 'R')
                                            {
                                                if(items.checkForRing())
                                                {
                                                    characters.setGold(-ring_value);
                                                    cout << "You just sold a Silver Ring for " << ring_value << " Gold!" << endl;
                                                    cout << "You have " << characters.getGold() << " Gold." << endl;
                                                }
                                                else
                                                {
                                                    cout << "you dont have a Silver Ring!" << endl;
                                                }
                                                    
                                            }
                                            else if (selling == 'N')
                                            {
                                                if(items.checkForNecklace())
                                                {
                                                    characters.setGold(-necklace_value);
                                                    cout << "You just sold a Ruby Necklace for " << necklace_value << " Gold!" << endl;
                                                    cout << "You have " << characters.getGold() << " Gold." << endl;
                                                }
                                                else
                                                {
                                                    cout << "you dont have a Ruby Necklace!" << endl;
                                                }
                                            }
                                            else if (selling == 'B')
                                            {
                                                if(items.checkForBracelet())
                                                {
                                                    characters.setGold(-bracelet_value);
                                                    cout << "You just sold an Emerald Bracelet for " << bracelet_value << " Gold!" << endl;
                                                    cout << "You have " << characters.getGold() << " Gold." << endl;
                                                }
                                                else
                                                {
                                                    cout << "you dont have an Emerald Bracelet!" << endl;
                                                }
                                            }
                                            else if (selling == 'C')
                                            {
                                                if(items.checkForCirclet())
                                                {
                                                    characters.setGold(-circlet_value);
                                                    cout << "You just sold a Diamond Circlet for " << circlet_value << " Gold!" << endl;
                                                    cout << "You have " << characters.getGold() << " Gold." << endl;
                                                }
                                                else
                                                {
                                                    cout << "you dont have a Diamond Circlet!" << endl;
                                                }
                                            }
                                            else if (selling == 'G')
                                            {
                                                if(items.checkForGoblet())
                                                {
                                                    characters.setGold(-goblet_value);
                                                    cout << "You just sold a Gem-encrusted goblet for " << goblet_value << " Gold!" << endl;
                                                    cout << "You have " << characters.getGold() << " Gold." << endl;
                                                }
                                                else
                                                {
                                                    cout << "you dont have a Gem-encrusted goblet!" << endl;
                                                }
                                            }
                                        }            
                                    }
                                    else if (optionMerchantMenu == 6)
                                    {
                                        char decision;
                                        cout << "Are you sure you're finished? You won't be able to buy anything else from me! (y/n)" << endl;
                                        cin >> decision;
                                        if (decision == 'y')
                                        {
                                            optionMerchantMenu = 7;
                                            cout << "Good luck out there!" << endl;
                                        }
                                        else if (decision == 'n')
                                        {
                                            break;
                                        }
                                        else
                                        {
                                            cout << "Invalid Input." << endl;
                                        }
                                    }

                                    cout << "+--------------+" << endl;
                                    cout << "STATUS" << endl;
                                    cout << "+--------------+" << endl;
                                    cout << "Rooms Cleared: " << status.getNumRoomsCleared() << " | " << " Keys: " << status.getNumKeyFounds() << " | " << " Anger Level: " << status.getSorcerersAnger() << endl;
                                    cout << "+--------------+" << endl;
                                    cout << "INVENTORY" << endl;
                                    cout << "+--------------+" << endl;
                                    cout << "Gold: " << characters.getGold() << endl;
                                    cout << "Ingredients: " << items.getIngredientKg() << endl;
                                    cout << "Cookware: " << " P: " << items.getNumPot() <<  "| " << " F: " << items.getNumPan() << " | " << " C: "<< items.getNumCauldron()<<  endl;
                                    cout << "Weapons: " << " C: " << items.getNumClubs() <<  " | " << " S: " << items.getNumSpears() << " | " << " R: "<< items.getNumRapier() << " | " <<  " B: " << items.getNumAxe() << " | " <<  " L: " << items.getNumLongsword() << endl;
                                    cout << "Armor: " << items.numArmor() <<endl;
                                    cout << "Treasures: " << items.getNumTreasure() << " | " << " R: " << items.getNumRing() <<  " | " << " N: " << items.getNumNecklace() << " | " << " B: "<< items.getNumBracelet() << " | " <<  " C: " << items.getNumCirclet() << " | " << " G: " << items.getNumGoblet() << endl;
                                    cout << "+--------------+" << endl;
                                    cout << characters.getPlayerName() << " | " << " Fullness: " << characters.getHealthMain() << endl;
                                    if (characters.isN1Alive())
                                    {
                                        cout << characters.getn1Name() << " | " << " Fullness: " << characters.getHealth1() << endl;
                                    }
                                    if (characters.isN2Alive())
                                    {
                                        cout << characters.getn2Name() << " | " << " Fullness: " << characters.getHealth2() << endl;
                                    }
                                    if(characters.isN3Alive())
                                    {
                                        cout << characters.getn3Name() << " | " << " Fullness: " << characters.getHealth3() << endl;
                                    }
                                    if(characters.isN4Alive())
                                    {
                                        cout << characters.getn4Name() << " | " << " Fullness: " << characters.getHealth4() << endl;
                                    }
                                    cout << "+--------------+" << endl;
                                    if (characters.getTotalCharacters() <= 1)
                                    {
                                        endGame(characters,items,status);
                                    }
                                    if (status.getSorcerersAnger() >= 100)
                                    {
                                        endGame(characters,items,status);
                                    }
                                }
                        }
                        //if riddle is correct and player chose not to look at menu, get a monster to fight
                        if (fight == true)
                        {
                            cout << "Looks like I'm going to have to summon a friend" << endl;
                            
                            monsterFight(status.getNumRoomsCleared(), status, characters, items, monster);

                            if ((items.getNumWeapons() < 1)) 
                                {
                                    int randTrapped = (rand() % 4) + 1;
                                    if (randTrapped == 1)
                                    {
                                        cout << characters.getn1Name() << "  was unable to escape the wrath of the monster and is held captive!" << endl;
                                        cout << "Say your goodbyes..." << endl;
                                        characters.removeCharacters(characters.getn1Name());
                                        characters.killN1();
                                        characters.setHealth1(characters.getHealth1());
                                        continue;
                                    }

                                    if (randTrapped == 2)
                                    {
                                        cout << characters.getn2Name() << "  was unable to escape the wrath of the monster and is held captive!" << endl;
                                        cout << "Say your goodbyes..." << endl;
                                        characters.removeCharacters(characters.getn2Name());
                                        characters.killN2();
                                        characters.setHealth2(characters.getHealth2());
                                        continue;
                                    }

                                    if (randTrapped == 3)
                                    {
                                        cout << characters.getn3Name() << "  was unable to escape the wrath of the monster and is held captive!" << endl;
                                        cout << "Say your goodbyes..." << endl;
                                        characters.removeCharacters(characters.getn3Name());
                                        characters.killN3();
                                        characters.setHealth3(characters.getHealth3());
                                        continue;
                                    }

                                    if (randTrapped == 4)
                                    {
                                        cout << characters.getn4Name() << "  was unable to escape the wrath of the monster and is held captive!" << endl;
                                        cout << "Say your goodbyes..." << endl;
                                        characters.removeCharacters(characters.getn4Name());
                                        characters.killN4();
                                        characters.setHealth4(characters.getHealth4());
                                        continue;
                                    }
                                    continue;
                                }

                            int num_arm = items.numArmor();
                            int num_wep = items.getNumWeapons();
                            int extra_p = items.extraWeaponPoints();
                            int d;
                            if (items.differentWeapons() == true)
                            {
                                d = 4;
                            }
                            else
                            {
                                d = 0;
                            }

                            if (monster.getFightResult(extra_p, num_wep, d, num_arm) == true)
                            {
                                cout << "Congratulations! You defeated the monster!" << endl;
                                if(monster.dropKey() != "")
                                {
                                    cout << "The monster dropped a key!" << endl;
                                    items.setKeys(1);
                                    status.setNumKeyFounds(1);
                                }          
                                cout << "You won " << (monster.getPower()) * 10 << " Gold!" << endl;
                                characters.setGold(-((monster.getPower()) * 10));
                                cout << "You also get " << (monster.getPower()) * 5 << "kg of ingredients!" << endl;
                                items.setIngredientKg( (monster.getPower() * 5) );
                                status.setNumMonstersDefeated(1);


                                int randHealthMain = rand() % 2 + 1;
                                if (randHealthMain == 1)
                                {
                                    cout << "Oh no! " << characters.getPlayerName() << " has lost a point of health!" << endl;
                                    characters.setHealthMain(1);
                                }
                                int randHealth1 = rand() % 2 + 1;
                                if (randHealth1 == 1)
                                {
                                    if (characters.isN1Alive())
                                    {
                                    cout << "Oh no! " << characters.getn1Name() << " has lost a point of health!" << endl;
                                    characters.setHealth1(1);
                                    }
                                }
                                int randHealth2 = rand() % 2 + 1;
                                if (randHealth2 == 1)
                                {
                                    if(characters.isN2Alive())
                                    {
                                    cout << "Oh no! " << characters.getn2Name() << " has lost a point of health!" << endl;
                                    characters.setHealth2(1);
                                    }
                                }
                                int randHealth3 = rand() % 2 + 1;
                                if (randHealth3 == 1)
                                {
                                    if (characters.isN3Alive())
                                    {
                                    cout << "Oh no! " << characters.getn3Name() << " has lost a point of health!" << endl;
                                    characters.setHealth3(1);
                                    }
                                }
                                int randHealth4 = rand() % 2 + 1;
                                if (randHealth4 == 1)
                                {
                                    if (characters.isN4Alive())
                                    {
                                    cout << "Oh no! " << characters.getn4Name() << " has lost a point of health!" << endl;
                                    characters.setHealth4(1);
                                    }
                                }

                                cout << "+--------------+" << endl;
                                cout << "STATUS" << endl;
                                cout << "+--------------+" << endl;
                                cout << "Rooms Cleared: " << status.getNumRoomsCleared() << " | " << " Keys: " << status.getNumKeyFounds() << " | " << " Anger Level: " << status.getSorcerersAnger() << endl;
                                cout << "+--------------+" << endl;
                                cout << "INVENTORY" << endl;
                                cout << "+--------------+" << endl;
                                cout << "Gold: " << characters.getGold() << endl;
                                cout << "Ingredients: " << items.getIngredientKg() << endl;
                                cout << "Cookware: " << " P: " << items.getNumPot() <<  "| " << " F: " << items.getNumPan() << " | " << " C: "<< items.getNumCauldron()<<  endl;
                                cout << "Weapons: " << " C: " << items.getNumClubs() <<  " | " << " S: " << items.getNumSpears() << " | " << " R: "<< items.getNumRapier() << " | " <<  " B: " << items.getNumAxe() << " | " <<  " L: " << items.getNumLongsword() << endl;
                                cout << "Armor: " << items.numArmor() <<endl;
                                cout << "Treasures: " << items.getNumTreasure() << " | " << " R: " << items.getNumRing() <<  " | " << " N: " << items.getNumNecklace() << " | " << " B: "<< items.getNumBracelet() << " | " <<  " C: " << items.getNumCirclet() << " | " << " G: " << items.getNumGoblet() << endl;
                                cout << "+--------------+" << endl;
                                cout << characters.getPlayerName() << " | " << " Fullness: " << characters.getHealthMain() << endl;
                                if (characters.isN1Alive())
                                {
                                    cout << characters.getn1Name() << " | " << " Fullness: " << characters.getHealth1() << endl;
                                }
                                if (characters.isN2Alive())
                                {
                                    cout << characters.getn2Name() << " | " << " Fullness: " << characters.getHealth2() << endl;
                                }
                                if(characters.isN3Alive())
                                {
                                    cout << characters.getn3Name() << " | " << " Fullness: " << characters.getHealth3() << endl;
                                }
                                if(characters.isN4Alive())
                                {
                                    cout << characters.getn4Name() << " | " << " Fullness: " << characters.getHealth4() << endl;
                                }
                                cout << "+--------------+" << endl;
                                if (characters.getTotalCharacters() <= 1)
                                {
                                    endGame(characters,items,status);
                                }
                                if (status.getSorcerersAnger() >= 100)
                                {
                                    endGame(characters,items,status);
                                }

                                continue;
                            }
                            else
                            {
                                cout << "You were defeated by the monster!" << endl;
                                int goldLost = floor(characters.getGold() * 0.25);
                                cout << "You lost " << goldLost <<" Gold!" << endl;
                                characters.setGold(goldLost);
                                cout << "You now have " << characters.getGold() << " Gold!" << endl;
                                                                
                                int foodLost = floor(items.getIngredientKg() * 0.15);
                                if (foodLost > 30)
                                {
                                foodLost = 30;
                                }
                                cout << "You also lost " << foodLost << "Kg of ingredients!" << endl;
                                items.EatIngredient(foodLost);
                                cout << "You now have " << items.getIngredientKg() << "Kg of ingredients." << endl;

                                if (monster.wasN1Slain(items.doesN1HaveArmor()) == true)
                                {
                                    string name = characters.getn1Name();
                                    cout << name << " was slain!!" << endl;
                                    cout <<  name << " is out of the game!" << endl;
                                    characters.removeCharacters(characters.getn1Name());
                                    characters.killN1();
                                    characters.setHealth1(characters.getHealth1());
                                }
                                if (monster.wasN2Slain(items.doesN2HaveArmor()) == true)
                                {
                                    string name = characters.getn2Name();
                                    cout << name << " was slain!!" << endl;
                                    cout <<  name << " is out of the game!" << endl;
                                    characters.removeCharacters(characters.getn2Name());
                                    characters.killN2();
                                    characters.setHealth2(characters.getHealth2());
                                }
                                if (monster.wasN3Slain(items.doesN3HaveArmor()) == true)
                                {
                                    string name = characters.getn3Name();
                                    cout << name << " was slain!!" << endl;
                                    cout <<  name << " is out of the game!" << endl;
                                    characters.removeCharacters(characters.getn3Name());
                                    characters.killN3();
                                    characters.setHealth3(characters.getHealth3());
                                }
                                if (monster.wasN4Slain(items.doesN4HaveArmor()) == true)
                                {
                                    string name = characters.getn4Name();
                                    cout << name << " was slain!!" << endl;
                                    cout <<  name << " is out of the game!" << endl;
                                    characters.removeCharacters(characters.getn4Name());
                                    characters.killN4();
                                    characters.setHealth4(characters.getHealth4());
                                }

                                int randHealthMain = rand() % 2 + 1;
                                if (randHealthMain == 1)
                                {
                                    cout << "Oh no! " << characters.getPlayerName() << " has lost a point of health!" << endl;
                                    characters.setHealthMain(1);
                                }
                                int randHealth1 = rand() % 2 + 1;
                                if (randHealth1 == 1)
                                {
                                    if (characters.isN1Alive())
                                    {
                                    cout << "Oh no! " << characters.getn1Name() << " has lost a point of health!" << endl;
                                    characters.setHealth1(1);
                                    }
                                }
                                int randHealth2 = rand() % 2 + 1;
                                if (randHealth2 == 1)
                                {
                                    if(characters.isN2Alive())
                                    {
                                    cout << "Oh no! " << characters.getn2Name() << " has lost a point of health!" << endl;
                                    characters.setHealth2(1);
                                    }
                                }
                                int randHealth3 = rand() % 2 + 1;
                                if (randHealth3 == 1)
                                {
                                    if (characters.isN3Alive())
                                    {
                                    cout << "Oh no! " << characters.getn3Name() << " has lost a point of health!" << endl;
                                    characters.setHealth3(1);
                                    }
                                }
                                int randHealth4 = rand() % 2 + 1;
                                if (randHealth4 == 1)
                                {
                                    if (characters.isN4Alive())
                                    {
                                    cout << "Oh no! " << characters.getn4Name() << " has lost a point of health!" << endl;
                                    characters.setHealth4(1);
                                    }
                                }

                                cout << "+--------------+" << endl;
                                cout << "STATUS" << endl;
                                cout << "+--------------+" << endl;
                                cout << "Rooms Cleared: " << status.getNumRoomsCleared() << " | " << " Keys: " << status.getNumKeyFounds() << " | " << " Anger Level: " << status.getSorcerersAnger() << endl;
                                cout << "+--------------+" << endl;
                                cout << "INVENTORY" << endl;
                                cout << "+--------------+" << endl;
                                cout << "Gold: " << characters.getGold() << endl;
                                cout << "Ingredients: " << items.getIngredientKg() << endl;
                                cout << "Cookware: " << " P: " << items.getNumPot() <<  "| " << " F: " << items.getNumPan() << " | " << " C: "<< items.getNumCauldron()<<  endl;
                                cout << "Weapons: " << " C: " << items.getNumClubs() <<  " | " << " S: " << items.getNumSpears() << " | " << " R: "<< items.getNumRapier() << " | " <<  " B: " << items.getNumAxe() << " | " <<  " L: " << items.getNumLongsword() << endl;
                                cout << "Armor: " << items.numArmor() <<endl;
                                cout << "Treasures: " << items.getNumTreasure() << " | " << " R: " << items.getNumRing() <<  " | " << " N: " << items.getNumNecklace() << " | " << " B: "<< items.getNumBracelet() << " | " <<  " C: " << items.getNumCirclet() << " | " << " G: " << items.getNumGoblet() << endl;
                                cout << "+--------------+" << endl;
                                cout << characters.getPlayerName() << " | " << " Fullness: " << characters.getHealthMain() << endl;
                                if (characters.isN1Alive())
                                {
                                    cout << characters.getn1Name() << " | " << " Fullness: " << characters.getHealth1() << endl;
                                }
                                if (characters.isN2Alive())
                                {
                                    cout << characters.getn2Name() << " | " << " Fullness: " << characters.getHealth2() << endl;
                                }
                                if(characters.isN3Alive())
                                {
                                    cout << characters.getn3Name() << " | " << " Fullness: " << characters.getHealth3() << endl;
                                }
                                if(characters.isN4Alive())
                                {
                                    cout << characters.getn4Name() << " | " << " Fullness: " << characters.getHealth4() << endl;
                                }
                                cout << "+--------------+" << endl;
                                if (characters.getTotalCharacters() <= 1)
                                {
                                    endGame(characters,items,status);
                                }
                                if (status.getSorcerersAnger() >= 100)
                                {
                                    endGame(characters,items,status);
                                }

                                continue;
                            }
                        }
                    }
                    else if (NPCaction == 3)
                    {
                        endGame(characters, items, status);
                    }
                    else
                    {
                        cout << "Invalid input." << endl;
                    }
            }
            //check if it is a room location
            else if (map.isRoomLocation(map.getPlayerRow(), map.getPlayerCol()))
            {
                //let the player know when it is the last room
                if(status.getNumRoomsCleared() >= 4)
                {
                    cout << "This is the last one!" << endl;
                }
                int room_action = 0;
                cout << "You have encountered a room! What do you wish to do?" << endl;
                cout << "Choose form the following actions:" << endl;
                cout << "1. Move (past the room)" << endl;
                cout << "2. Open the door" << endl;
                cout << "3. Give up" << endl;
                cin >> room_action;

                string y;
                int e = status.getNumRoomsCleared();
                Monsters monst(y, e);

                if (room_action == 2)
                    {
                        int numKeys = status.getNumKeyFounds();
                        //check if player has keys to open door and open it if they have 1 or more
                        if (numKeys > 0)
                        {
                            //remove the key if used
                            status.setNumKeyFounds(-1);

                            monsterFight(status.getNumRoomsCleared(), status, characters, items, monst);

                            //if the player has no weapons, they cannot fight and one of the part members will be trapped
                            if ((items.getNumWeapons() < 1)) 
                            {
                                int randTrapped = (rand() % 4) + 1;
                                if (randTrapped == 1)
                                {
                                    cout << characters.getn1Name() << "  was unable to escape the wrath of the monster and is held captive!" << endl;
                                    cout << "Say your goodbyes..." << endl;
                                    characters.removeCharacters(characters.getn1Name());
                                    characters.killN1();
                                    characters.setHealth1(characters.getHealth1());
                                    continue;
                                }

                                if (randTrapped == 2)
                                {
                                    cout << characters.getn2Name() << "  was unable to escape the wrath of the monster and is held captive!" << endl;
                                    cout << "Say your goodbyes..." << endl;
                                    characters.removeCharacters(characters.getn2Name());
                                    characters.killN2();
                                    characters.setHealth2(characters.getHealth2());
                                    continue;
                                }

                                if (randTrapped == 3)
                                {
                                    cout << characters.getn3Name() << "  was unable to escape the wrath of the monster and is held captive!" << endl;
                                    cout << "Say your goodbyes..." << endl;
                                    characters.removeCharacters(characters.getn3Name());
                                    characters.killN3();
                                    characters.setHealth3(characters.getHealth3());
                                    continue;
                                }

                                if (randTrapped == 4)
                                {
                                    cout << characters.getn4Name() << "  was unable to escape the wrath of the monster and is held captive!" << endl;
                                    cout << "Say your goodbyes..." << endl;
                                    characters.removeCharacters(characters.getn4Name());
                                    characters.killN4();
                                    characters.setHealth4(characters.getHealth4());
                                    continue;
                                }
                                continue;
                            }

                            //if party does have weapons, fight
                            int num_arm = items.numArmor();
                            int num_wep = items.getNumWeapons();
                            int extra_p = items.extraWeaponPoints();
                            int d;
                            if (items.differentWeapons() == true)
                            {
                                int d = 4;
                            }
                            else
                            {
                                d = 0;
                            }

                            if (monst.getFightResult(extra_p, num_wep, d, num_arm) == true)
                            {
                                cout << "Congratulations! You defeated the monster!" << endl;
                                monst.dropKey();
                                if(monst.dropKey() != "")
                                {
                                    cout << "The monster dropped a key!" << endl;
                                    items.setKeys(1);
                                    status.setNumKeyFounds(1);
                                }          
                                cout << "You won " << (monst.getPower()) * 10 << " Gold!" << endl;
                                characters.setGold(-((monst.getPower()) * 10));
                                cout << "You also get " << (monst.getPower()) * 5 << "kg of ingredients!" << endl;
                                items.setIngredientKg( (monst.getPower() * 5) );
                                status.setNumMonstersDefeated(1);

                                //misfortunes
                                srand(time(0));
                                int random_m = rand() % 100 + 1;
                                if (random_m > 0 && random_m <= 60)
                                {
                                    srand(time(0));

                                    int ra = rand() % 4 + 1;

                                    if (ra = 1)
                                    {
                                        int ran = rand() % 100 + 1;
                                        if (ran > 0 && ran <= 30)
                                        {
                                            cout << "OH NO! Your team was robbed by dungeon bandits!" << endl;
                                            int randi = rand() % 3 + 1;
                                            if (randi == 1)
                                            {
                                                cout << "You lost 10kg of ingredients!" << endl;
                                                items.EatIngredient(10);
                                            }
                                            if (randi == 2)
                                            {
                                                string randomcook = items.getRandomCookware();
                                                cout << "You lost 1 " << randomcook << "!" << endl;

                                                char removec;
                                                if (randomcook == "Ceramic pot")
                                                {
                                                    removec = 'P';
                                                }
                                                else if (randomcook == "Frying pan")
                                                {
                                                    removec = 'F';
                                                }
                                                else if (randomcook == "Cauldron")
                                                {
                                                    removec = 'C';
                                                }

                                                items.removeCookware(removec);
                                            }
                                            if (randi == 3)
                                            {
                                                cout << "You lost 1 armor!" << endl;
                                                items.setArmor(-1);
                                            }
                                        }
                                    }
                                    else if (ra == 2)
                                    {
                                        srand(time(0));
                                        int rando = rand() % 2 + 1;
                                        if (rando == 1)
                                        {
                                            string randwep = items.getRandomWeapon();
                                                    cout << "Your " << randwep << " broke!" << endl;

                                                    char remove;
                                                    if(randwep == "Club")
                                                    {
                                                        remove = 'C';
                                                    }
                                                    else if(randwep == "Spear")
                                                    {
                                                        remove = 'S';
                                                    }
                                                    else if (randwep == "+1 Rapier")
                                                    {
                                                        remove = 'R';
                                                    }
                                                    else if (randwep == "+2 Battle-Axe")
                                                    {
                                                        remove = 'B';
                                                    }
                                                    else if (randwep == "+3 Longsword")
                                                    {
                                                        remove = 'L';
                                                    }
                                                    items.removeWeapons(remove);
                                        }
                                        else if (rando == 2)
                                        {
                                            cout << "You lost 1 armor!" << endl;
                                            items.setArmor(-1);
                                        }
                                    }
                                    else if (ra == 3)
                                    {
                                        srand(time(0));
                                        int randPerson = rand() % 4 + 1;
                                        int randPoss = rand() % 100 + 1;
                                        if (randPoss > 0 && randPoss <= 30)
                                        {
                                        if (randPerson == 1)
                                        {
                                            cout << "Oh no! " << characters.getn1Name() << " got food poisoning! They will loose 10 health points." << endl;
                                            characters.setHealth1(10);
                                            if (!(characters.stillFulln1()))
                                            {
                                                cout << characters.getn1Name() << " has no more health! They have died." << endl;
                                                characters.setn1Name("");
                                                characters.killN1();
                                                characters.removeCharacters(characters.getn1Name());
                                                characters.setHealth1(characters.getHealth1());
                                            }
                                        }
                                        else if (randPerson == 2)
                                        {
                                            cout << "Oh no! " << characters.getn2Name() << " got food poisoning! They will loose 10 health points." << endl;
                                            characters.setHealth2(10);
                                            if (!(characters.stillFulln2()))
                                            {
                                                cout << characters.getn2Name() << " has no more health! They have died." << endl;
                                                characters.setn2Name("");
                                                characters.killN2();
                                                characters.removeCharacters(characters.getn2Name());
                                                characters.setHealth2(characters.getHealth2());
                                            }
                                        }
                                        else if (randPerson == 3)
                                        {
                                            cout << "Oh no! " << characters.getn3Name() << " got food poisoning! They will loose 10 health points." << endl;
                                            characters.setHealth3(10);
                                            if (!(characters.stillFulln3()))
                                            {
                                                cout << characters.getn3Name() << " has no more health! They have died." << endl;
                                                characters.setn3Name("");
                                                characters.killN3();
                                                characters.removeCharacters(characters.getn3Name());
                                                characters.setHealth3(characters.getHealth3());
                                            }
                                        }
                                        else if (randPerson == 4)
                                        {
                                            cout << "Oh no! " << characters.getn4Name() << " got food poisoning! They will loose 10 health points." << endl;
                                            characters.setHealth4(10);
                                            if (!(characters.stillFulln4()))
                                            {
                                                cout << characters.getn4Name() << " has no more health! They have died." << endl;
                                                characters.setn4Name("");
                                                characters.killN4();
                                                characters.removeCharacters(characters.getn4Name());
                                                characters.setHealth4(characters.getHealth4());
                                            }
                                        }
                                        }
                                    }
                                }
                                //remove room if cleared
                                status.setNumRoomsCleared(1);
                                map.removeRoom(map.getPlayerRow(), map.getPlayerCol());

                                int randHealthMain = rand() % 2 + 1;
                                if (randHealthMain == 1)
                                {
                                    cout << "Oh no! " << characters.getPlayerName() << " has lost a point of health!" << endl;
                                    characters.setHealthMain(1);
                                }
                                int randHealth1 = rand() % 2 + 1;
                                if (randHealth1 == 1)
                                {
                                    if (characters.isN1Alive())
                                    {
                                    cout << "Oh no! " << characters.getn1Name() << " has lost a point of health!" << endl;
                                    characters.setHealth1(1);
                                    }
                                }
                                int randHealth2 = rand() % 2 + 1;
                                if (randHealth2 == 1)
                                {
                                    if(characters.isN2Alive())
                                    {
                                    cout << "Oh no! " << characters.getn2Name() << " has lost a point of health!" << endl;
                                    characters.setHealth2(1);
                                    }
                                }
                                int randHealth3 = rand() % 2 + 1;
                                if (randHealth3 == 1)
                                {
                                    if (characters.isN3Alive())
                                    {
                                    cout << "Oh no! " << characters.getn3Name() << " has lost a point of health!" << endl;
                                    characters.setHealth3(1);
                                    }
                                }
                                int randHealth4 = rand() % 2 + 1;
                                if (randHealth4 == 1)
                                {
                                    if (characters.isN4Alive())
                                    {
                                    cout << "Oh no! " << characters.getn4Name() << " has lost a point of health!" << endl;
                                    characters.setHealth4(1);
                                    }
                                }

                                cout << "+--------------+" << endl;
                                cout << "STATUS" << endl;
                                cout << "+--------------+" << endl;
                                cout << "Rooms Cleared: " << status.getNumRoomsCleared() << " | " << " Keys: " << status.getNumKeyFounds() << " | " << " Anger Level: " << status.getSorcerersAnger() << endl;
                                cout << "+--------------+" << endl;
                                cout << "INVENTORY" << endl;
                                cout << "+--------------+" << endl;
                                cout << "Gold: " << characters.getGold() << endl;
                                cout << "Ingredients: " << items.getIngredientKg() << endl;
                                cout << "Cookware: " << " P: " << items.getNumPot() <<  "| " << " F: " << items.getNumPan() << " | " << " C: "<< items.getNumCauldron()<<  endl;
                                cout << "Weapons: " << " C: " << items.getNumClubs() <<  " | " << " S: " << items.getNumSpears() << " | " << " R: "<< items.getNumRapier() << " | " <<  " B: " << items.getNumAxe() << " | " <<  " L: " << items.getNumLongsword() << endl;
                                cout << "Armor: " << items.numArmor() <<endl;
                                cout << "Treasures: " << items.getNumTreasure() << " | " << " R: " << items.getNumRing() <<  " | " << " N: " << items.getNumNecklace() << " | " << " B: "<< items.getNumBracelet() << " | " <<  " C: " << items.getNumCirclet() << " | " << " G: " << items.getNumGoblet() << endl;
                                cout << "+--------------+" << endl;
                                cout << characters.getPlayerName() << " | " << " Fullness: " << characters.getHealthMain() << endl;
                                if (characters.isN1Alive())
                                {
                                    cout << characters.getn1Name() << " | " << " Fullness: " << characters.getHealth1() << endl;
                                }
                                if (characters.isN2Alive())
                                {
                                    cout << characters.getn2Name() << " | " << " Fullness: " << characters.getHealth2() << endl;
                                }
                                if(characters.isN3Alive())
                                {
                                    cout << characters.getn3Name() << " | " << " Fullness: " << characters.getHealth3() << endl;
                                }
                                if(characters.isN4Alive())
                                {
                                    cout << characters.getn4Name() << " | " << " Fullness: " << characters.getHealth4() << endl;
                                }
                                cout << "+--------------+" << endl;
                                if (characters.getTotalCharacters() <= 1)
                                {
                                    endGame(characters,items,status);
                                }
                                if (status.getSorcerersAnger() >= 100)
                                {
                                    endGame(characters,items,status);
                                }
                                continue;
                            }
                            else
                            {
                                cout << "You were defeated by the monster!" << endl;
                                int goldLost = floor(characters.getGold() * 0.25);
                                cout << "You lost " << goldLost <<" Gold!" << endl;
                                characters.setGold(goldLost);
                                cout << "You now have " << characters.getGold() << " Gold!" << endl;
                                
                                int foodLost = floor(items.getIngredientKg() * 0.15);
                                if (foodLost > 30)
                                {
                                    foodLost = 30;
                                }
                                cout << "You also lost " << foodLost << "Kg of ingredients!" << endl;
                                items.EatIngredient(foodLost);
                                cout << "You now have " << items.getIngredientKg() << "Kg of ingredients." << endl;

                                //misfortunes
                                srand(time(0));
                                int random_m = rand() % 100 + 1;
                                if (random_m > 0 && random_m <= 40)
                                {
                                    srand(time(0));

                                    int ra = rand() % 4 + 1;

                                    if (ra = 1)
                                    {
                                        int ran = rand() % 100 + 1;
                                        if (ran > 0 && ran <= 30)
                                        {
                                            cout << "OH NO! Your team was robbed by dungeon bandits!" << endl;
                                            int randi = rand() % 3 + 1;
                                            if (randi == 1)
                                            {
                                                cout << "You lost 10kg of ingredients!" << endl;
                                                items.EatIngredient(10);
                                            }
                                            if (randi == 2)
                                            {
                                                string randomcook = items.getRandomCookware();
                                                cout << "You lost 1 " << randomcook << "!" << endl;

                                                char removec;
                                                if (randomcook == "Ceramic pot")
                                                {
                                                    removec = 'P';
                                                }
                                                else if (randomcook == "Frying pan")
                                                {
                                                    removec = 'F';
                                                }
                                                else if (randomcook == "Cauldron")
                                                {
                                                    removec = 'C';
                                                }

                                                items.removeCookware(removec);
                                            }
                                            if (randi == 3)
                                            {
                                                cout << "You lost 1 armor!" << endl;
                                                items.setArmor(-1);
                                            }
                                        }
                                    }
                                    else if (ra == 2)
                                    {
                                        srand(time(0));
                                        int rando = rand() % 2 + 1;
                                        if (rando == 1)
                                        {
                                            string randwep = items.getRandomWeapon();
                                                    cout << "Your " << randwep << " broke!" << endl;

                                                    char remove;
                                                    if(randwep == "Club")
                                                    {
                                                        remove = 'C';
                                                    }
                                                    else if(randwep == "Spear")
                                                    {
                                                        remove = 'S';
                                                    }
                                                    else if (randwep == "+1 Rapier")
                                                    {
                                                        remove = 'R';
                                                    }
                                                    else if (randwep == "+2 Battle-Axe")
                                                    {
                                                        remove = 'B';
                                                    }
                                                    else if (randwep == "+3 Longsword")
                                                    {
                                                        remove = 'L';
                                                    }
                                                    items.removeWeapons(remove);
                                        }
                                        else if (rando == 2)
                                        {
                                            cout << "You lost 1 armor!" << endl;
                                            items.setArmor(-1);
                                        }
                                    }
                                    else if (ra == 3)
                                    {
                                        srand(time(0));
                                        int randPerson = rand() % 4 + 1;
                                        int randPoss = rand() % 100 + 1;
                                        if (randPoss > 0 && randPoss <= 30)
                                        {
                                        if (randPerson == 1)
                                        {
                                            cout << "Oh no! " << characters.getn1Name() << " got food poisoning! They will loose 10 health points." << endl;
                                            characters.setHealth1(10);
                                            if (!(characters.stillFulln1()))
                                            {
                                                cout << characters.getn1Name() << " has no more health! They have died." << endl;
                                                characters.setn1Name("");
                                                characters.killN1();
                                                characters.removeCharacters(characters.getn1Name());
                                                characters.setHealth1(characters.getHealth1());
                                            }
                                        }
                                        else if (randPerson == 2)
                                        {
                                            cout << "Oh no! " << characters.getn2Name() << " got food poisoning! They will loose 10 health points." << endl;
                                            characters.setHealth2(10);
                                            if (!(characters.stillFulln2()))
                                            {
                                                cout << characters.getn2Name() << " has no more health! They have died." << endl;
                                                characters.setn2Name("");
                                                characters.killN2();
                                                characters.removeCharacters(characters.getn2Name());
                                                characters.setHealth2(characters.getHealth2());
                                            }
                                        }
                                        else if (randPerson == 3)
                                        {
                                            cout << "Oh no! " << characters.getn3Name() << " got food poisoning! They will loose 10 health points." << endl;
                                            characters.setHealth3(10);
                                            if (!(characters.stillFulln3()))
                                            {
                                                cout << characters.getn3Name() << " has no more health! They have died." << endl;
                                                characters.setn3Name("");
                                                characters.killN3();
                                                characters.removeCharacters(characters.getn3Name());
                                                characters.setHealth3(characters.getHealth3());
                                            }
                                        }
                                        else if (randPerson == 4)
                                        {
                                            cout << "Oh no! " << characters.getn4Name() << " got food poisoning! They will loose 10 health points." << endl;
                                            characters.setHealth4(10);
                                            if (!(characters.stillFulln4()))
                                            {
                                                cout << characters.getn4Name() << " has no more health! They have died." << endl;
                                                characters.setn4Name("");
                                                characters.killN4();
                                                characters.removeCharacters(characters.getn4Name());
                                                characters.setHealth4(characters.getHealth4());
                                            }
                                        }
                                        }
                                    }
                                }

                                //check if someone was slayed during the fight
                                if (monst.wasN1Slain(items.doesN1HaveArmor()) == true)
                                {
                                    string name = characters.getn1Name();
                                    cout << name << " was slain!!" << endl;
                                    cout <<  name << " is out of the game!" << endl;
                                    characters.removeCharacters(characters.getn1Name());
                                    characters.killN1();
                                    characters.setHealth1(characters.getHealth1());
                                }
                                if (monst.wasN2Slain(items.doesN2HaveArmor()) == true)
                                {
                                    string name = characters.getn2Name();
                                    cout << name << " was slain!!" << endl;
                                    cout <<  name << " is out of the game!" << endl;
                                    characters.removeCharacters(characters.getn2Name());
                                    characters.killN2();
                                    characters.setHealth2(characters.getHealth2());
                                }
                                if (monst.wasN3Slain(items.doesN3HaveArmor()) == true)
                                {
                                    string name = characters.getn3Name();
                                    cout << name << " was slain!!" << endl;
                                    cout <<  name << " is out of the game!" << endl;
                                    characters.removeCharacters(characters.getn3Name());
                                    characters.killN3();
                                    characters.setHealth3(characters.getHealth3());
                                }
                                if (monst.wasN4Slain(items.doesN4HaveArmor()) == true)
                                {
                                    string name = characters.getn4Name();
                                    cout << name << " was slain!!" << endl;
                                    cout <<  name << " is out of the game!" << endl;
                                    characters.removeCharacters(characters.getn4Name());
                                    characters.killN4();
                                    characters.setHealth4(characters.getHealth4());
                                }

                                int randHealthMain = rand() % 2 + 1;
                                if (randHealthMain == 1)
                                {
                                    cout << "Oh no! " << characters.getPlayerName() << " has lost a point of health!" << endl;
                                    characters.setHealthMain(1);
                                }
                                int randHealth1 = rand() % 2 + 1;
                                if (randHealth1 == 1)
                                {
                                    if (characters.isN1Alive())
                                    {
                                    cout << "Oh no! " << characters.getn1Name() << " has lost a point of health!" << endl;
                                    characters.setHealth1(1);
                                    }
                                }
                                int randHealth2 = rand() % 2 + 1;
                                if (randHealth2 == 1)
                                {
                                    if(characters.isN2Alive())
                                    {
                                    cout << "Oh no! " << characters.getn2Name() << " has lost a point of health!" << endl;
                                    characters.setHealth2(1);
                                    }
                                }
                                int randHealth3 = rand() % 2 + 1;
                                if (randHealth3 == 1)
                                {
                                    if (characters.isN3Alive())
                                    {
                                    cout << "Oh no! " << characters.getn3Name() << " has lost a point of health!" << endl;
                                    characters.setHealth3(1);
                                    }
                                }
                                int randHealth4 = rand() % 2 + 1;
                                if (randHealth4 == 1)
                                {
                                    if (characters.isN4Alive())
                                    {
                                    cout << "Oh no! " << characters.getn4Name() << " has lost a point of health!" << endl;
                                    characters.setHealth4(1);
                                    }
                                }

                                cout << "+--------------+" << endl;
                                cout << "STATUS" << endl;
                                cout << "+--------------+" << endl;
                                cout << "Rooms Cleared: " << status.getNumRoomsCleared() << " | " << " Keys: " << status.getNumKeyFounds() << " | " << " Anger Level: " << status.getSorcerersAnger() << endl;
                                cout << "+--------------+" << endl;
                                cout << "INVENTORY" << endl;
                                cout << "+--------------+" << endl;
                                cout << "Gold: " << characters.getGold() << endl;
                                cout << "Ingredients: " << items.getIngredientKg() << endl;
                                cout << "Cookware: " << " P: " << items.getNumPot() <<  "| " << " F: " << items.getNumPan() << " | " << " C: "<< items.getNumCauldron()<<  endl;
                                cout << "Weapons: " << " C: " << items.getNumClubs() <<  " | " << " S: " << items.getNumSpears() << " | " << " R: "<< items.getNumRapier() << " | " <<  " B: " << items.getNumAxe() << " | " <<  " L: " << items.getNumLongsword() << endl;
                                cout << "Armor: " << items.numArmor() <<endl;
                                cout << "Treasures: " << items.getNumTreasure() << " | " << " R: " << items.getNumRing() <<  " | " << " N: " << items.getNumNecklace() << " | " << " B: "<< items.getNumBracelet() << " | " <<  " C: " << items.getNumCirclet() << " | " << " G: " << items.getNumGoblet() << endl;
                                cout << "+--------------+" << endl;
                                cout << characters.getPlayerName() << " | " << " Fullness: " << characters.getHealthMain() << endl;
                                if (characters.isN1Alive())
                                {
                                    cout << characters.getn1Name() << " | " << " Fullness: " << characters.getHealth1() << endl;
                                }
                                if (characters.isN2Alive())
                                {
                                    cout << characters.getn2Name() << " | " << " Fullness: " << characters.getHealth2() << endl;
                                }
                                if(characters.isN3Alive())
                                {
                                    cout << characters.getn3Name() << " | " << " Fullness: " << characters.getHealth3() << endl;
                                }
                                if(characters.isN4Alive())
                                {
                                    cout << characters.getn4Name() << " | " << " Fullness: " << characters.getHealth4() << endl;
                                }
                                cout << "+--------------+" << endl;
                                if (characters.getTotalCharacters() <= 1)
                                {
                                    endGame(characters,items,status);
                                }
                                if (status.getSorcerersAnger() >= 100)
                                {
                                    endGame(characters,items,status);
                                }

                                continue;
                            }

                            if (monsterFight(status.getNumRoomsCleared(), status, characters, items, monst) == 3)
                            {
                                cout << "You lost the key!" << endl;
                                status.setNumKeyFounds(-1);
                                int newKeys = status.getNumKeyFounds();
                                if (newKeys < 0)
                                {
                                    newKeys = 0;
                                }
                                cout << "You now have " << newKeys << " keys." << endl;
                                
                                int random_m = rand() % 100 + 1;
                                if (random_m > 0 && random_m <= 40)
                                {
                                    srand(time(0));

                                    int ra = rand() % 4 + 1;

                                    if (ra = 1)
                                    {
                                        int ran = rand() % 100 + 1;
                                        if (ran > 0 && ran <= 30)
                                        {
                                            cout << "OH NO! Your team was robbed by dungeon bandits!" << endl;
                                            int randi = rand() % 3 + 1;
                                            if (randi == 1)
                                            {
                                                cout << "You lost 10kg of ingredients!" << endl;
                                                items.EatIngredient(10);
                                            }
                                            if (randi == 2)
                                            {
                                                string randomcook = items.getRandomCookware();
                                                cout << "You lost 1 " << randomcook << "!" << endl;

                                                char removec;
                                                if (randomcook == "Ceramic pot")
                                                {
                                                    removec = 'P';
                                                }
                                                else if (randomcook == "Frying pan")
                                                {
                                                    removec = 'F';
                                                }
                                                else if (randomcook == "Cauldron")
                                                {
                                                    removec = 'C';
                                                }

                                                items.removeCookware(removec);
                                            }
                                            if (randi == 3)
                                            {
                                                cout << "You lost 1 armor!" << endl;
                                                items.setArmor(-1);
                                            }
                                        }
                                    }
                                    else if (ra == 2)
                                    {
                                        srand(time(0));
                                        int rando = rand() % 2 + 1;
                                        if (rando == 1)
                                        {
                                            string randwep = items.getRandomWeapon();
                                                    cout << "Your " << randwep << " broke!" << endl;

                                                    char remove;
                                                    if(randwep == "Club")
                                                    {
                                                        remove = 'C';
                                                    }
                                                    else if(randwep == "Spear")
                                                    {
                                                        remove = 'S';
                                                    }
                                                    else if (randwep == "+1 Rapier")
                                                    {
                                                        remove = 'R';
                                                    }
                                                    else if (randwep == "+2 Battle-Axe")
                                                    {
                                                        remove = 'B';
                                                    }
                                                    else if (randwep == "+3 Longsword")
                                                    {
                                                        remove = 'L';
                                                    }
                                                    items.removeWeapons(remove);
                                        }
                                        else if (rando == 2)
                                        {
                                            cout << "You lost 1 armor!" << endl;
                                            items.setArmor(-1);
                                        }
                                    }
                                    else if (ra == 3)
                                    {
                                        srand(time(0));
                                        int randPerson = rand() % 4 + 1;
                                        int randPoss = rand() % 100 + 1;
                                        if (randPoss > 0 && randPoss <= 30)
                                        {
                                        if (randPerson == 1)
                                        {
                                            cout << "Oh no! " << characters.getn1Name() << " got food poisoning! They will loose 10 health points." << endl;
                                            characters.setHealth1(10);
                                            if (!(characters.stillFulln1()))
                                            {
                                                cout << characters.getn1Name() << " has no more health! They have died." << endl;
                                                characters.removeCharacters(characters.getn1Name());
                                                characters.killN1();
                                                characters.removeCharacters(characters.getn1Name());
                                                characters.setHealth1(characters.getHealth1());
                                            }
                                        }
                                        else if (randPerson == 2)
                                        {
                                            cout << "Oh no! " << characters.getn2Name() << " got food poisoning! They will loose 10 health points." << endl;
                                            characters.setHealth2(10);
                                            if (!(characters.stillFulln2()))
                                            {
                                                cout << characters.getn2Name() << " has no more health! They have died." << endl;
                                                characters.removeCharacters(characters.getn2Name());
                                                characters.killN2();
                                                characters.removeCharacters(characters.getn2Name());
                                                characters.setHealth2(characters.getHealth2());
                                            }
                                        }
                                        else if (randPerson == 3)
                                        {
                                            cout << "Oh no! " << characters.getn3Name() << " got food poisoning! They will loose 10 health points." << endl;
                                            characters.setHealth3(10);
                                            if (!(characters.stillFulln3()))
                                            {
                                                cout << characters.getn3Name() << " has no more health! They have died." << endl;
                                                characters.removeCharacters(characters.getn3Name());
                                                characters.killN3();
                                                characters.removeCharacters(characters.getn3Name());
                                                characters.setHealth3(characters.getHealth3());
                                            }
                                        }
                                        else if (randPerson == 4)
                                        {
                                            cout << "Oh no! " << characters.getn4Name() << " got food poisoning! They will loose 10 health points." << endl;
                                            characters.setHealth4(10);
                                            if (!(characters.stillFulln4()))
                                            {
                                                cout << characters.getn4Name() << " has no more health! They have died." << endl;
                                                characters.removeCharacters(characters.getn4Name());
                                                characters.killN4();
                                                characters.removeCharacters(characters.getn4Name());
                                                characters.setHealth4(characters.getHealth4());
                                            }
                                        }
                                        }
                                    }
                                }
                            }
                        }
                        else if (numKeys == 0)
                        {
                            bool win = false;
                            cout << "You don't have any keys!" << endl;
                            //puzzle for when the player does not have any keys
                            for(int j = 0; j < 3; j++)
                            {
                                char player_choice;
                                cout << "You have 3 tries to beat me at a game of rock, paper, sissors or else one of you will perish" << endl;
                                cout << "enter either r, p, or s: ";
                                cin >> player_choice;
                                cout << endl;

                                int door_choice = rand() % 3 + 1;
                                char choice_door;
                                if (door_choice == 1)
                                {
                                    choice_door = 'r';
                                }
                                else if(door_choice == 2)
                                {
                                    choice_door = 'p';
                                }
                                else if(door_choice == 3)
                                {
                                    choice_door = 's';
                                }

                                if (player_choice == choice_door)
                                {
                                    cout << "it's a tie" << endl;
                                    continue;
                                }

                                if (player_choice == 'r' && choice_door == 's')
                                {
                                    win = true;
                                    break;
                                }
                                if (player_choice == 'p' && choice_door == 'r')
                                {
                                    win = true;
                                    break;
                                }
                                if (player_choice == 's' && choice_door == 'p')
                                {
                                    win = true;
                                    break;
                                }

                                if (choice_door == 'r' && player_choice == 's')
                                {
                                    win = true;
                                    break;
                                }
                                if (choice_door == 'p' && player_choice == 'r')
                                {
                                    win = true;
                                    break;
                                }
                                if (choice_door == 's' && player_choice == 'p')
                                {
                                    win = true;
                                    break;
                                }
                            }
                            //if the player wins, let them though the door
                            if (win == true)
                            {
                                cout << "Congrats! You beat me, I will let you through the door without a key!" << endl;

                                monsterFight(e, status, characters, items, monst);

                                if ((items.getNumWeapons() < 1)) 
                                {
                                    int randTrapped = (rand() % 4) + 1;
                                    if (randTrapped == 1)
                                    {
                                        cout << characters.getn1Name() << "  was unable to escape the wrath of the monster and is held captive!" << endl;
                                        cout << "Say your goodbyes..." << endl;
                                        characters.removeCharacters(characters.getn1Name());
                                        characters.killN1();
                                        characters.setHealth1(characters.getHealth1());
                                        continue;
                                    }

                                    if (randTrapped == 2)
                                    {
                                        cout << characters.getn2Name() << "  was unable to escape the wrath of the monster and is held captive!" << endl;
                                        cout << "Say your goodbyes..." << endl;
                                        characters.removeCharacters(characters.getn2Name());
                                        characters.killN2();
                                        characters.setHealth2(characters.getHealth2());
                                        continue;
                                    }

                                    if (randTrapped == 3)
                                    {
                                        cout << characters.getn3Name() << "  was unable to escape the wrath of the monster and is held captive!" << endl;
                                        cout << "Say your goodbyes..." << endl;
                                        characters.removeCharacters(characters.getn3Name());
                                        characters.killN3();
                                        characters.setHealth3(characters.getHealth3());
                                        continue;
                                    }

                                    if (randTrapped == 4)
                                    {
                                        cout << characters.getn4Name() << "  was unable to escape the wrath of the monster and is held captive!" << endl;
                                        cout << "Say your goodbyes..." << endl;
                                        characters.removeCharacters(characters.getn4Name());
                                        characters.killN4();
                                        characters.setHealth4(characters.getHealth4());
                                        continue;
                                    }
                                    continue;
                                }
                                int na = items.numArmor();
                                int nw = items.getNumWeapons();
                                int ep = items.extraWeaponPoints();
                                
                                int dw;
                                if(items.differentWeapons() == true)
                                {
                                    dw = 4;
                                }
                                else 
                                {
                                    dw = 0;
                                }

                                if (monst.getFightResult(ep, nw, dw, na) == true)
                                {
                                    cout << "Congratulations! You defeated the monster!" << endl;
                                    monst.dropKey();
                                    if(monst.dropKey() != "")
                                    {
                                        cout << "The monster dropped a key!" << endl;
                                        items.setKeys(1);
                                        status.setNumKeyFounds(1);
                                    } 
                            
                                    cout << "You won " << (monst.getPower()) * 10 << " Gold!" << endl;
                                    characters.setGold(-((monst.getPower()) * 10));
                                    cout << "You also get " << (monst.getPower()) * 5 << "kg of ingredients!" << endl;
                                    items.setIngredientKg( (monst.getPower() * 5) );
                                    status.setNumMonstersDefeated(1);
                                
                                    srand(time(0));
                                        
                                    int random_m = rand() % 100 + 1;
                                    if (random_m > 0 && random_m <= 60)
                                    {
                                        srand(time(0));

                                        int ra = rand() % 4 + 1;

                                        if (ra = 1)
                                        {
                                            int ran = rand() % 100 + 1;
                                            if (ran > 0 && ran <= 30)
                                            {
                                                cout << "OH NO! Your team was robbed by dungeon bandits!" << endl;
                                                int randi = rand() % 3 + 1;
                                                if (randi == 1)
                                                {
                                                    cout << "You lost 10kg of ingredients!" << endl;
                                                    items.EatIngredient(10);
                                                }
                                                if (randi == 2)
                                                {
                                                    string randomcook = items.getRandomCookware();
                                                cout << "You lost 1 " << randomcook << "!" << endl;

                                                char removec;
                                                if (randomcook == "Ceramic pot")
                                                {
                                                    removec = 'P';
                                                }
                                                else if (randomcook == "Frying pan")
                                                {
                                                    removec = 'F';
                                                }
                                                else if (randomcook == "Cauldron")
                                                {
                                                    removec = 'C';
                                                }

                                                items.removeCookware(removec);
                                                }
                                                if (randi == 3)
                                                {
                                                    cout << "You lost 1 armor!" << endl;
                                                    items.setArmor(-1);
                                                }
                                            }
                                        }
                                        else if (ra == 2)
                                        {
                                            srand(time(0));
                                            int rando = rand() % 2 + 1;
                                            if (rando == 1)
                                            {
                                                string randwep = items.getRandomWeapon();
                                                    cout << "Your " << randwep << " broke!" << endl;

                                                    char remove;
                                                    if(randwep == "Club")
                                                    {
                                                        remove = 'C';
                                                    }
                                                    else if(randwep == "Spear")
                                                    {
                                                        remove = 'S';
                                                    }
                                                    else if (randwep == "+1 Rapier")
                                                    {
                                                        remove = 'R';
                                                    }
                                                    else if (randwep == "+2 Battle-Axe")
                                                    {
                                                        remove = 'B';
                                                    }
                                                    else if (randwep == "+3 Longsword")
                                                    {
                                                        remove = 'L';
                                                    }
                                                    items.removeWeapons(remove);
                                            }
                                            else if (rando == 2)
                                            {
                                                cout << "You lost 1 armor!" << endl;
                                                items.setArmor(-1);
                                            }
                                        }
                                        else if (ra == 3)
                                        {
                                            srand(time(0));
                                            int randPerson = rand() % 4 + 1;
                                            int randPoss = rand() % 100 + 1;
                                            if (randPoss > 0 && randPoss <= 30)
                                            {
                                            if (randPerson == 1)
                                            {
                                                cout << "Oh no! " << characters.getn1Name() << " got food poisoning! They will loose 10 health points." << endl;
                                                characters.setHealth1(10);
                                                if (!(characters.stillFulln1()))
                                                {
                                                    cout << characters.getn1Name() << " has no more health! They have died." << endl;
                                                    characters.removeCharacters(characters.getn1Name());
                                                    characters.killN1();
                                                }
                                            }
                                            else if (randPerson == 2)
                                            {
                                                cout << "Oh no! " << characters.getn2Name() << " got food poisoning! They will loose 10 health points." << endl;
                                                characters.setHealth2(10);
                                                if (!(characters.stillFulln2()))
                                                {
                                                    cout << characters.getn2Name() << " has no more health! They have died." << endl;
                                                    characters.removeCharacters(characters.getn2Name());
                                                    characters.killN2();
                                                }
                                            }
                                            else if (randPerson == 3)
                                            {
                                                cout << "Oh no! " << characters.getn3Name() << " got food poisoning! They will loose 10 health points." << endl;
                                                characters.setHealth3(10);
                                                if (!(characters.stillFulln3()))
                                                {
                                                    cout << characters.getn3Name() << " has no more health! They have died." << endl;
                                                    characters.removeCharacters(characters.getn3Name());
                                                    characters.killN3();
                                                }
                                            }
                                            else if (randPerson == 4)
                                            {
                                                cout << "Oh no! " << characters.getn4Name() << " got food poisoning! They will loose 10 health points." << endl;
                                                characters.setHealth4(10);
                                                if (!(characters.stillFulln4()))
                                                {
                                                    cout << characters.getn4Name() << " has no more health! They have died." << endl;
                                                    characters.removeCharacters(characters.getn4Name());
                                                    characters.killN4();
                                                }
                                            }
                                            }
                                        }
                                    }
                                    status.setNumRoomsCleared(1);
                                    map.removeRoom(map.getPlayerRow(), map.getPlayerCol());

                                    int randHealthMain = rand() % 2 + 1;
                                    if (randHealthMain == 1)
                                    {
                                        cout << "Oh no! " << characters.getPlayerName() << " has lost a point of health!" << endl;
                                        characters.setHealthMain(1);
                                    }
                                    int randHealth1 = rand() % 2 + 1;
                                    if (randHealth1 == 1)
                                    {
                                        if (characters.isN1Alive())
                                        {
                                        cout << "Oh no! " << characters.getn1Name() << " has lost a point of health!" << endl;
                                        characters.setHealth1(1);
                                        }
                                    }
                                    int randHealth2 = rand() % 2 + 1;
                                    if (randHealth2 == 1)
                                    {
                                        if(characters.isN2Alive())
                                        {
                                        cout << "Oh no! " << characters.getn2Name() << " has lost a point of health!" << endl;
                                        characters.setHealth2(1);
                                        }
                                    }
                                    int randHealth3 = rand() % 2 + 1;
                                    if (randHealth3 == 1)
                                    {
                                        if (characters.isN3Alive())
                                        {
                                        cout << "Oh no! " << characters.getn3Name() << " has lost a point of health!" << endl;
                                        characters.setHealth3(1);
                                        }
                                    }
                                    int randHealth4 = rand() % 2 + 1;
                                    if (randHealth4 == 1)
                                    {
                                        if (characters.isN4Alive())
                                        {
                                        cout << "Oh no! " << characters.getn4Name() << " has lost a point of health!" << endl;
                                        characters.setHealth4(1);
                                        }
                                    }

                                    cout << "+--------------+" << endl;
                                    cout << "STATUS" << endl;
                                    cout << "+--------------+" << endl;
                                    cout << "Rooms Cleared: " << status.getNumRoomsCleared() << " | " << " Keys: " << status.getNumKeyFounds() << " | " << " Anger Level: " << status.getSorcerersAnger() << endl;
                                    cout << "+--------------+" << endl;
                                    cout << "INVENTORY" << endl;
                                    cout << "+--------------+" << endl;
                                    cout << "Gold: " << characters.getGold() << endl;
                                    cout << "Ingredients: " << items.getIngredientKg() << endl;
                                    cout << "Cookware: " << " P: " << items.getNumPot() <<  "| " << " F: " << items.getNumPan() << " | " << " C: "<< items.getNumCauldron()<<  endl;
                                    cout << "Weapons: " << " C: " << items.getNumClubs() <<  " | " << " S: " << items.getNumSpears() << " | " << " R: "<< items.getNumRapier() << " | " <<  " B: " << items.getNumAxe() << " | " <<  " L: " << items.getNumLongsword() << endl;
                                    cout << "Armor: " << items.numArmor() <<endl;
                                    cout << "Treasures: " << items.getNumTreasure() << " | " << " R: " << items.getNumRing() <<  " | " << " N: " << items.getNumNecklace() << " | " << " B: "<< items.getNumBracelet() << " | " <<  " C: " << items.getNumCirclet() << " | " << " G: " << items.getNumGoblet() << endl;
                                    cout << "+--------------+" << endl;
                                    cout << characters.getPlayerName() << " | " << " Fullness: " << characters.getHealthMain() << endl;
                                    if (characters.isN1Alive())
                                    {
                                        cout << characters.getn1Name() << " | " << " Fullness: " << characters.getHealth1() << endl;
                                    }
                                    if (characters.isN2Alive())
                                    {
                                        cout << characters.getn2Name() << " | " << " Fullness: " << characters.getHealth2() << endl;
                                    }
                                    if(characters.isN3Alive())
                                    {
                                        cout << characters.getn3Name() << " | " << " Fullness: " << characters.getHealth3() << endl;
                                    }
                                    if(characters.isN4Alive())
                                    {
                                        cout << characters.getn4Name() << " | " << " Fullness: " << characters.getHealth4() << endl;
                                    }
                                    cout << "+--------------+" << endl;
                                    if (characters.getTotalCharacters() <= 1)
                                    {
                                        endGame(characters,items,status);
                                    }
                                    if (status.getSorcerersAnger() >= 100)
                                    {
                                        endGame(characters,items,status);
                                    }

                                    continue;
                                }
                                else
                                {
                                    cout << "You were defeated by the monster!" << endl;
                                    int goldLost = floor(characters.getGold() * 0.25);
                                    cout << "You lost " << goldLost <<" Gold!" << endl;
                                    characters.setGold(goldLost);
                                    cout << "You now have " << characters.getGold() << " Gold!" << endl;
                                    
                                    int foodLost = floor(items.getIngredientKg() * 0.15);
                                    if (foodLost > 30)
                                    {
                                        foodLost = 30;
                                    }
                                    cout << "You also lost " << foodLost << "Kg of ingredients!" << endl;
                                    items.EatIngredient(foodLost);
                                    cout << "You now have " << items.getIngredientKg() << "Kg of ingredients." << endl;


                                    int randHealthMain = rand() % 2 + 1;
                                    if (randHealthMain == 1)
                                    {
                                        cout << "Oh no! " << characters.getPlayerName() << " has lost a point of health!" << endl;
                                        characters.setHealthMain(1);
                                    }
                                    int randHealth1 = rand() % 2 + 1;
                                    if (randHealth1 == 1)
                                    {
                                        if (characters.isN1Alive())
                                        {
                                        cout << "Oh no! " << characters.getn1Name() << " has lost a point of health!" << endl;
                                        characters.setHealth1(1);
                                        }
                                    }
                                    int randHealth2 = rand() % 2 + 1;
                                    if (randHealth2 == 1)
                                    {
                                        if(characters.isN2Alive())
                                        {
                                        cout << "Oh no! " << characters.getn2Name() << " has lost a point of health!" << endl;
                                        characters.setHealth2(1);
                                        }
                                    }
                                    int randHealth3 = rand() % 2 + 1;
                                    if (randHealth3 == 1)
                                    {
                                        if (characters.isN3Alive())
                                        {
                                        cout << "Oh no! " << characters.getn3Name() << " has lost a point of health!" << endl;
                                        characters.setHealth3(1);
                                        }
                                    }
                                    int randHealth4 = rand() % 2 + 1;
                                    if (randHealth4 == 1)
                                    {
                                        if (characters.isN4Alive())
                                        {
                                        cout << "Oh no! " << characters.getn4Name() << " has lost a point of health!" << endl;
                                        characters.setHealth4(1);
                                        }
                                    }

                                    cout << "+--------------+" << endl;
                                    cout << "STATUS" << endl;
                                    cout << "+--------------+" << endl;
                                    cout << "Rooms Cleared: " << status.getNumRoomsCleared() << " | " << " Keys: " << status.getNumKeyFounds() << " | " << " Anger Level: " << status.getSorcerersAnger() << endl;
                                    cout << "+--------------+" << endl;
                                    cout << "INVENTORY" << endl;
                                    cout << "+--------------+" << endl;
                                    cout << "Gold: " << characters.getGold() << endl;
                                    cout << "Ingredients: " << items.getIngredientKg() << endl;
                                    cout << "Cookware: " << " P: " << items.getNumPot() <<  "| " << " F: " << items.getNumPan() << " | " << " C: "<< items.getNumCauldron()<<  endl;
                                    cout << "Weapons: " << " C: " << items.getNumClubs() <<  " | " << " S: " << items.getNumSpears() << " | " << " R: "<< items.getNumRapier() << " | " <<  " B: " << items.getNumAxe() << " | " <<  " L: " << items.getNumLongsword() << endl;
                                    cout << "Armor: " << items.numArmor() <<endl;
                                    cout << "Treasures: " << items.getNumTreasure() << " | " << " R: " << items.getNumRing() <<  " | " << " N: " << items.getNumNecklace() << " | " << " B: "<< items.getNumBracelet() << " | " <<  " C: " << items.getNumCirclet() << " | " << " G: " << items.getNumGoblet() << endl;
                                    cout << "+--------------+" << endl;
                                    cout << characters.getPlayerName() << " | " << " Fullness: " << characters.getHealthMain() << endl;
                                    if (characters.isN1Alive())
                                    {
                                        cout << characters.getn1Name() << " | " << " Fullness: " << characters.getHealth1() << endl;
                                    }
                                    if (characters.isN2Alive())
                                    {
                                        cout << characters.getn2Name() << " | " << " Fullness: " << characters.getHealth2() << endl;
                                    }
                                    if(characters.isN3Alive())
                                    {
                                        cout << characters.getn3Name() << " | " << " Fullness: " << characters.getHealth3() << endl;
                                    }
                                    if(characters.isN4Alive())
                                    {
                                        cout << characters.getn4Name() << " | " << " Fullness: " << characters.getHealth4() << endl;
                                    }
                                    cout << "+--------------+" << endl;
                                    if (characters.getTotalCharacters() <= 1)
                                    {
                                        endGame(characters,items,status);
                                    }
                                    if (status.getSorcerersAnger() >= 100)
                                    {
                                        endGame(characters,items,status);
                                    }
                                    
                                    continue;
                                }
                                continue;
                            }  
                            //if the player looses, one of the party members will perish
                            else
                            {
                                cout << "You were unable to beat me in three tries... one of you must perish" << endl;
                                int random_perish = rand() % 4 + 1;
                                if (random_perish == 1)
                                {
                                    cout << characters.getn1Name() << " has perished!" << endl;
                                    cout << characters.getn1Name() << " is out of the game!" << endl;
                                    characters.removeCharacters(characters.getn1Name());
                                    characters.killN1();
                                    characters.setHealth1(characters.getHealth1());
                                }
                                if (random_perish == 2)
                                {
                                    cout << characters.getn2Name() << " has perished!" << endl;
                                    cout << characters.getn2Name() << " is out of the game!" << endl;
                                    characters.removeCharacters(characters.getn2Name());
                                    characters.killN2();
                                    characters.setHealth2(characters.getHealth2());
                                }
                                if (random_perish == 3)
                                {
                                    cout << characters.getn3Name() << " has perished!" << endl;
                                    cout << characters.getn3Name() << " is out of the game!" << endl;
                                    characters.removeCharacters(characters.getn3Name());
                                    characters.killN3();
                                    characters.setHealth3(characters.getHealth3());
                                }
                                if (random_perish == 4)
                                {
                                    cout << characters.getn4Name() << " has perished!" << endl;
                                    cout << characters.getn4Name() << " is out of the game!" << endl;
                                    characters.removeCharacters(characters.getn4Name());
                                    characters.killN4();
                                    characters.setHealth4(characters.getHealth4());
                                }

                                cout << "+--------------+" << endl;
                                cout << "STATUS" << endl;
                                cout << "+--------------+" << endl;
                                cout << "Rooms Cleared: " << status.getNumRoomsCleared() << " | " << " Keys: " << status.getNumKeyFounds() << " | " << " Anger Level: " << status.getSorcerersAnger() << endl;
                                cout << "+--------------+" << endl;
                                cout << "INVENTORY" << endl;
                                cout << "+--------------+" << endl;
                                cout << "Gold: " << characters.getGold() << endl;
                                cout << "Ingredients: " << items.getIngredientKg() << endl;
                                cout << "Cookware: " << " P: " << items.getNumPot() <<  "| " << " F: " << items.getNumPan() << " | " << " C: "<< items.getNumCauldron()<<  endl;
                                cout << "Weapons: " << " C: " << items.getNumClubs() <<  " | " << " S: " << items.getNumSpears() << " | " << " R: "<< items.getNumRapier() << " | " <<  " B: " << items.getNumAxe() << " | " <<  " L: " << items.getNumLongsword() << endl;
                                cout << "Armor: " << items.numArmor() <<endl;
                                cout << "Treasures: " << items.getNumTreasure() << " | " << " R: " << items.getNumRing() <<  " | " << " N: " << items.getNumNecklace() << " | " << " B: "<< items.getNumBracelet() << " | " <<  " C: " << items.getNumCirclet() << " | " << " G: " << items.getNumGoblet() << endl;
                                cout << "+--------------+" << endl;
                                cout << characters.getPlayerName() << " | " << " Fullness: " << characters.getHealthMain() << endl;
                                if (characters.isN1Alive())
                                {
                                    cout << characters.getn1Name() << " | " << " Fullness: " << characters.getHealth1() << endl;
                                }
                                if (characters.isN2Alive())
                                {
                                    cout << characters.getn2Name() << " | " << " Fullness: " << characters.getHealth2() << endl;
                                }
                                if(characters.isN3Alive())
                                {
                                    cout << characters.getn3Name() << " | " << " Fullness: " << characters.getHealth3() << endl;
                                }
                                if(characters.isN4Alive())
                                {
                                    cout << characters.getn4Name() << " | " << " Fullness: " << characters.getHealth4() << endl;
                                }
                                cout << "+--------------+" << endl;
                                if (characters.getTotalCharacters() <= 1)
                                {
                                    endGame(characters,items,status);
                                }
                                if (status.getSorcerersAnger() >= 100)
                                {
                                    endGame(characters,items,status);
                                }

                                continue;
                            }  
                        }
                        }
                        else if (room_action == 1)
                        {
                            choiceMove = 1;;
                        }
                        else if (room_action == 3)
                        {
                            continue;
                        }   
            }

            else if (map.isDungeonExit(map.getPlayerRow(), map.getPlayerCol()))
            {
                //if the player has cleared all rooms, they can leave the dungeon and the final status will be printed
                if (status.getNumRoomsCleared() == 5)
                {
                    endGameHappy(characters, items, status);
                    return 0;
                }
                else
                {
                    cout << "You have not cleared all 5 rooms!" << endl;
                    continue;
                }
            } 
        

            cout << "+--------------+" << endl;
            cout << "STATUS" << endl;
            cout << "+--------------+" << endl;
            cout << "Rooms Cleared: " << status.getNumRoomsCleared() << " | " << " Keys: " << status.getNumKeyFounds() << " | " << " Anger Level: " << status.getSorcerersAnger() << endl;
            cout << "+--------------+" << endl;
            cout << "INVENTORY" << endl;
            cout << "+--------------+" << endl;
            cout << "Gold: " << characters.getGold() << endl;
            cout << "Ingredients: " << items.getIngredientKg() << endl;
            cout << "Cookware: " << " P: " << items.getNumPot() <<  "| " << " F: " << items.getNumPan() << " | " << " C: "<< items.getNumCauldron()<<  endl;
            cout << "Weapons: " << " C: " << items.getNumClubs() <<  " | " << " S: " << items.getNumSpears() << " | " << " R: "<< items.getNumRapier() << " | " <<  " B: " << items.getNumAxe() << " | " <<  " L: " << items.getNumLongsword() << endl;
            cout << "Armor: " << items.numArmor() <<endl;
            cout << "Treasures: " << items.getNumTreasure() << " | " << " R: " << items.getNumRing() <<  " | " << " N: " << items.getNumNecklace() << " | " << " B: "<< items.getNumBracelet() << " | " <<  " C: " << items.getNumCirclet() << " | " << " G: " << items.getNumGoblet() << endl;
            cout << "+--------------+" << endl;
            cout << characters.getPlayerName() << " | " << " Fullness: " << characters.getHealthMain() << endl;
            if (characters.isN1Alive())
            {
                cout << characters.getn1Name() << " | " << " Fullness: " << characters.getHealth1() << endl;
            }
            if (characters.isN2Alive())
            {
                cout << characters.getn2Name() << " | " << " Fullness: " << characters.getHealth2() << endl;
            }
            if(characters.isN3Alive())
            {
                cout << characters.getn3Name() << " | " << " Fullness: " << characters.getHealth3() << endl;
            }
            if(characters.isN4Alive())
            {
                cout << characters.getn4Name() << " | " << " Fullness: " << characters.getHealth4() << endl;
            }
            
            cout << "+--------------+" << endl;
            if (characters.getTotalCharacters() <= 1)
            {
                endGame(characters,items,status);
            }
            if (status.getSorcerersAnger() >= 100)
            {
                endGame(characters,items,status);
            }
            cout << "+--------------+" << endl;

            continue;
        }
        else if(choiceMove == 2)
        {
            //if the map is explored, it cannot be explored again
            if (map.isExplored(map.getPlayerRow(), map.getPlayerCol())) {
                cout << "Exlored. Choose a different option." << endl;
            }
            map.exploreSpace(map.getPlayerRow(), map.getPlayerCol());
            int outcome1 = rand() % 10;
            //only a 10% chance of finding a key
            if(outcome1 < 1)
            {
                cout << "You found a key!" << endl;
                status.setNumKeyFounds(1);
                items.setKeys(1);
            }
            //60% chance of finding a treasure
            else if(outcome1 < 3){
                //choose treasure depending on number of rooms cleared
                int sellingTreasures = status.getNumRoomsCleared();
                if(sellingTreasures == 0)
                {
                    cout << "You found a Silver Ring!" << endl;
                    items.setTreasure('R');
                }
                else if(sellingTreasures == 1)
                {
                    cout << "You found a Ruby Necklace!" << endl;
                    items.setTreasure('N');
                }
                else if(sellingTreasures == 2)
                {
                    cout << "You found an Emerald Bracelet!" << endl;
                    items.setTreasure('B');
                }
                else if(sellingTreasures == 3)
                {
                    cout << "You found a Diamond Circlet!" << endl;
                    items.setTreasure('C');
                }
                else if(sellingTreasures == 2)
                {
                    cout << "You found a Gem-encrusted goblet!" << endl;
                    items.setTreasure('G');
                }
            }
            else if(outcome1 < 5){
                //fight (like all of the rest)
                string mosInvestigate;
                int pMosInvestigate = status.getNumRoomsCleared();
                Monsters mons(mosInvestigate, pMosInvestigate);
                monsterFight(status.getNumRoomsCleared(), status, characters, items, mons);

                if ((items.getNumWeapons() < 1)) 
                {
                    int randTrapped = (rand() % 4) + 1;
                    if (randTrapped == 1)
                    {
                        cout << characters.getn1Name() << "  was unable to escape the wrath of the monster and is held captive!" << endl;
                        cout << "Say your goodbyes..." << endl;
                        characters.removeCharacters(characters.getn1Name());
                        characters.killN1();
                        characters.setHealth1(characters.getHealth1());
                        continue;
                    }

                    if (randTrapped == 2)
                    {
                        cout << characters.getn2Name() << "  was unable to escape the wrath of the monster and is held captive!" << endl;
                        cout << "Say your goodbyes..." << endl;
                        characters.removeCharacters(characters.getn2Name());
                        characters.killN2();
                        characters.setHealth2(characters.getHealth2());
                        continue;
                    }

                    if (randTrapped == 3)
                    {
                        cout << characters.getn3Name() << "  was unable to escape the wrath of the monster and is held captive!" << endl;
                        cout << "Say your goodbyes..." << endl;
                        characters.removeCharacters(characters.getn3Name());
                        characters.killN3();
                        characters.setHealth3(characters.getHealth3());
                        continue;
                    }

                    if (randTrapped == 4)
                    {
                        cout << characters.getn4Name() << "  was unable to escape the wrath of the monster and is held captive!" << endl;
                        cout << "Say your goodbyes..." << endl;
                        characters.removeCharacters(characters.getn4Name());
                        characters.killN4();
                        characters.setHealth4(characters.getHealth4());
                        continue;
                    }
                    continue;
                }

                int num_arm = items.numArmor();
                int num_wep = items.getNumWeapons();
                int extra_p = items.extraWeaponPoints();
                int d;
                if (items.differentWeapons() == true)
                {
                    int d = 4;
                }
                else
                {
                    d = 0;
                }

                if (mons.getFightResult(extra_p, num_wep, d, num_arm) == true)
                {
                    cout << "Congratulations! You defeated the monster!" << endl;
                    mons.dropKey();
                    if(mons.dropKey() != "")
                    {
                        cout << "The monster dropped a key!" << endl;
                        items.setKeys(1);
                        status.setNumKeyFounds(1);
                    }          
                    cout << "You won " << (mons.getPower()) * 10 << " Gold!" << endl;
                    characters.setGold(-((mons.getPower()) * 10));
                    cout << "You also get " << (mons.getPower()) * 5 << "kg of ingredients!" << endl;
                    items.setIngredientKg( (mons.getPower() * 5) );
                    status.setNumMonstersDefeated(1);

                    int randHealthMain = rand() % 2 + 1;
                    if (randHealthMain == 1)
                    {
                        cout << "Oh no! " << characters.getPlayerName() << " has lost a point of health!" << endl;
                        characters.setHealthMain(1);
                    }
                    int randHealth1 = rand() % 2 + 1;
                    if (randHealth1 == 1)
                    {
                        if (characters.isN1Alive())
                        {
                        cout << "Oh no! " << characters.getn1Name() << " has lost a point of health!" << endl;
                        characters.setHealth1(1);
                        }
                    }
                    int randHealth2 = rand() % 2 + 1;
                    if (randHealth2 == 1)
                    {
                        if(characters.isN2Alive())
                        {
                        cout << "Oh no! " << characters.getn2Name() << " has lost a point of health!" << endl;
                        characters.setHealth2(1);
                        }
                    }
                    int randHealth3 = rand() % 2 + 1;
                    if (randHealth3 == 1)
                    {
                        if (characters.isN3Alive())
                        {
                        cout << "Oh no! " << characters.getn3Name() << " has lost a point of health!" << endl;
                        characters.setHealth3(1);
                        }
                    }
                    int randHealth4 = rand() % 2 + 1;
                    if (randHealth4 == 1)
                    {
                        if (characters.isN4Alive())
                        {
                        cout << "Oh no! " << characters.getn4Name() << " has lost a point of health!" << endl;
                        characters.setHealth4(1);
                        }
                    }

                    continue;
                }
                else
                {
                    cout << "You were defeated by the monster!" << endl;
                    int goldLost = floor(characters.getGold() * 0.25);
                    cout << "You lost " << goldLost <<" Gold!" << endl;
                    characters.setGold(goldLost);
                    cout << "You now have " << characters.getGold() << " Gold!" << endl;
                    
                    int foodLost = floor(items.getIngredientKg() * 0.15);
                    if (foodLost > 30)
                    {
                        foodLost = 30;
                    }
                    cout << "You also lost " << foodLost << "Kg of ingredients!" << endl;
                    items.EatIngredient(foodLost);
                    cout << "You now have " << items.getIngredientKg() << "Kg of ingredients." << endl;

                    if (mons.wasN1Slain(items.doesN1HaveArmor()) == true)
                    {
                        string name = characters.getn1Name();
                        cout << name << " was slain!!" << endl;
                        cout <<  name << " is out of the game!" << endl;
                        characters.removeCharacters(characters.getn1Name());
                        characters.killN1();
                        characters.setHealth1(characters.getHealth1());
                    }
                    if (mons.wasN2Slain(items.doesN2HaveArmor()) == true)
                    {
                        string name = characters.getn2Name();
                        cout << name << " was slain!!" << endl;
                        cout <<  name << " is out of the game!" << endl;
                        characters.removeCharacters(characters.getn2Name());
                        characters.killN2();
                        characters.setHealth2(characters.getHealth2());
                    }
                    if (mons.wasN3Slain(items.doesN3HaveArmor()) == true)
                    {
                        string name = characters.getn3Name();
                        cout << name << " was slain!!" << endl;
                        cout <<  name << " is out of the game!" << endl;
                        characters.removeCharacters(characters.getn3Name());
                        characters.killN3();
                        characters.setHealth3(characters.getHealth3());
                    }
                    if (mons.wasN4Slain(items.doesN4HaveArmor()) == true)
                    {
                        string name = characters.getn4Name();
                        cout << name << " was slain!!" << endl;
                        cout <<  name << " is out of the game!" << endl;
                        characters.removeCharacters(characters.getn4Name());
                        characters.killN4();
                        characters.setHealth4(characters.getHealth4());
                    }


                    int randHealthMain = rand() % 2 + 1;
                    if (randHealthMain == 1)
                    {
                        cout << "Oh no! " << characters.getPlayerName() << " has lost a point of health!" << endl;
                        characters.setHealthMain(1);
                    }
                    int randHealth1 = rand() % 2 + 1;
                    if (randHealth1 == 1)
                    {
                        if (characters.isN1Alive())
                        {
                        cout << "Oh no! " << characters.getn1Name() << " has lost a point of health!" << endl;
                        characters.setHealth1(1);
                        }
                    }
                    int randHealth2 = rand() % 2 + 1;
                    if (randHealth2 == 1)
                    {
                        if(characters.isN2Alive())
                        {
                        cout << "Oh no! " << characters.getn2Name() << " has lost a point of health!" << endl;
                        characters.setHealth2(1);
                        }
                    }
                    int randHealth3 = rand() % 2 + 1;
                    if (randHealth3 == 1)
                    {
                        if (characters.isN3Alive())
                        {
                        cout << "Oh no! " << characters.getn3Name() << " has lost a point of health!" << endl;
                        characters.setHealth3(1);
                        }
                    }
                    int randHealth4 = rand() % 2 + 1;
                    if (randHealth4 == 1)
                    {
                        if (characters.isN4Alive())
                        {
                        cout << "Oh no! " << characters.getn4Name() << " has lost a point of health!" << endl;
                        characters.setHealth4(1);
                        }
                    }

                    continue;
                }
            }
            else{
                cout << "You didn't find anything" << endl;
            }
            if(outcome1 >= 2){
                int randHealthMainP = rand() % 2 + 1;
                if(randHealthMainP == 1){
                    cout << "Oh no! " << characters.getPlayerName() << " has lost a point of health!" << endl;
                    characters.setHealthMain(1);
                }
                int randHealthP1 = rand() % 2 + 1;
                if(randHealthP1 == 1){
                    cout << "Oh no! " << characters.getn1Name() << " has lost a point of health!" <<endl;
                    characters.setHealth1(1);
                }
                int randHealthP2 = rand() % 2 + 1;
                if(randHealthP2 == 1){
                    cout << "Oh no! " << characters.getn2Name() << " has lost a point of health!" <<endl;
                    characters.setHealth2(1);
                }
                int randHealthP3 = rand() % 2 + 1;
                if(randHealthP3 == 1){
                    cout << "Oh no! " << characters.getn3Name() << " has lost a point of health!" <<endl;
                    characters.setHealth3(1);
                }
                int randHealthP4 = rand() % 2 + 1;
                if(randHealthP4 == 1){
                    cout << "Oh no! " << characters.getn4Name() << " has lost a point of health!" <<endl;
                    characters.setHealth4(1);
                }
            }

            status.setNumSpacesExplored(1);

            cout << "+--------------+" << endl;
            cout << "STATUS" << endl;
            cout << "+--------------+" << endl;
            cout << "Rooms Cleared: " << status.getNumRoomsCleared() << " | " << " Keys: " << status.getNumKeyFounds() << " | " << " Anger Level: " << status.getSorcerersAnger() << endl;
            cout << "+--------------+" << endl;
            cout << "INVENTORY" << endl;
            cout << "+--------------+" << endl;
            cout << "Gold: " << characters.getGold() << endl;
            cout << "Ingredients: " << items.getIngredientKg() << endl;
            cout << "Cookware: " << " P: " << items.getNumPot() <<  "| " << " F: " << items.getNumPan() << " | " << " C: "<< items.getNumCauldron()<<  endl;
            cout << "Weapons: " << " C: " << items.getNumClubs() <<  " | " << " S: " << items.getNumSpears() << " | " << " R: "<< items.getNumRapier() << " | " <<  " B: " << items.getNumAxe() << " | " <<  " L: " << items.getNumLongsword() << endl;
            cout << "Armor: " << items.numArmor() <<endl;
            cout << "Treasures: " << items.getNumTreasure() << " | " << " R: " << items.getNumRing() <<  " | " << " N: " << items.getNumNecklace() << " | " << " B: "<< items.getNumBracelet() << " | " <<  " C: " << items.getNumCirclet() << " | " << " G: " << items.getNumGoblet() << endl;
            cout << "+--------------+" << endl;
            cout << characters.getPlayerName() << " | " << " Fullness: " << characters.getHealthMain() << endl;
            if (characters.isN1Alive())
            {
                cout << characters.getn1Name() << " | " << " Fullness: " << characters.getHealth1() << endl;
            }
            if (characters.isN2Alive())
            {
                cout << characters.getn2Name() << " | " << " Fullness: " << characters.getHealth2() << endl;
            }
            if(characters.isN3Alive())
            {
                cout << characters.getn3Name() << " | " << " Fullness: " << characters.getHealth3() << endl;
            }
            if(characters.isN4Alive())
            {
                cout << characters.getn4Name() << " | " << " Fullness: " << characters.getHealth4() << endl;
            }
            cout << "+--------------+" << endl;
            if (characters.getTotalCharacters() <= 1)
            {
                endGame(characters,items,status);
            }
            if (status.getSorcerersAnger() >= 100)
            {
                endGame(characters,items,status);
            }
        }
        else if(choiceMove == 3)
        {
            //pick a fight (like all of the other fights)
            string mo;
            int p = status.getNumRoomsCleared();
            Monsters mons(mo, p);
            monsterFight(status.getNumRoomsCleared(), status, characters, items, mons);

            if ((items.getNumWeapons() < 1)) 
            {
                int randTrapped = (rand() % 4) + 1;
                if (randTrapped == 1)
                {
                    cout << characters.getn1Name() << "  was unable to escape the wrath of the monster and is held captive!" << endl;
                    cout << "Say your goodbyes..." << endl;
                    characters.removeCharacters(characters.getn1Name());
                    characters.killN1();
                    characters.setHealth1(characters.getHealth1());
                    continue;
                }

                if (randTrapped == 2)
                {
                    cout << characters.getn2Name() << "  was unable to escape the wrath of the monster and is held captive!" << endl;
                    cout << "Say your goodbyes..." << endl;
                    characters.removeCharacters(characters.getn2Name());
                    characters.killN2();
                    characters.setHealth2(characters.getHealth2());
                    continue;
                }

                if (randTrapped == 3)
                {
                    cout << characters.getn3Name() << "  was unable to escape the wrath of the monster and is held captive!" << endl;
                    cout << "Say your goodbyes..." << endl;
                    characters.removeCharacters(characters.getn3Name());
                    characters.killN3();
                    characters.setHealth3(characters.getHealth3());
                    continue;
                }

                if (randTrapped == 4)
                {
                    cout << characters.getn4Name() << "  was unable to escape the wrath of the monster and is held captive!" << endl;
                    cout << "Say your goodbyes..." << endl;
                    characters.removeCharacters(characters.getn4Name());
                    characters.killN4();
                    characters.setHealth4(characters.getHealth4());
                    continue;
                }
                continue;
            }

            int num_arm = items.numArmor();
            int num_wep = items.getNumWeapons();
            int extra_p = items.extraWeaponPoints();
            int d;
            if (items.differentWeapons() == true)
            {
                int d = 4;
            }
            else
            {
                d = 0;
            }

            if (mons.getFightResult(extra_p, num_wep, d, num_arm) == true)
            {
                cout << "Congratulations! You defeated the monster!" << endl;
                mons.dropKey();
                if(mons.dropKey() != "")
                {
                    cout << "The monster dropped a key!" << endl;
                    items.setKeys(1);
                    status.setNumKeyFounds(1);
                }          
                cout << "You won " << (mons.getPower()) * 10 << " Gold!" << endl;
                characters.setGold(-((mons.getPower()) * 10));
                cout << "You also get " << (mons.getPower()) * 5 << "kg of ingredients!" << endl;
                items.setIngredientKg( (mons.getPower() * 5) );
                status.setNumMonstersDefeated(1);

                int randHealthMain = rand() % 2 + 1;
                if (randHealthMain == 1)
                {
                    cout << "Oh no! " << characters.getPlayerName() << " has lost a point of health!" << endl;
                    characters.setHealthMain(1);
                }
                int randHealth1 = rand() % 2 + 1;
                if (randHealth1 == 1)
                {
                    if (characters.isN1Alive())
                    {
                    cout << "Oh no! " << characters.getn1Name() << " has lost a point of health!" << endl;
                    characters.setHealth1(1);
                    }
                }
                int randHealth2 = rand() % 2 + 1;
                if (randHealth2 == 1)
                {
                    if(characters.isN2Alive())
                    {
                    cout << "Oh no! " << characters.getn2Name() << " has lost a point of health!" << endl;
                    characters.setHealth2(1);
                    }
                }
                int randHealth3 = rand() % 2 + 1;
                if (randHealth3 == 1)
                {
                    if (characters.isN3Alive())
                    {
                    cout << "Oh no! " << characters.getn3Name() << " has lost a point of health!" << endl;
                    characters.setHealth3(1);
                    }
                }
                int randHealth4 = rand() % 2 + 1;
                if (randHealth4 == 1)
                {
                    if (characters.isN4Alive())
                    {
                    cout << "Oh no! " << characters.getn4Name() << " has lost a point of health!" << endl;
                    characters.setHealth4(1);
                    }
                }

                cout << "+--------------+" << endl;
                cout << "STATUS" << endl;
                cout << "+--------------+" << endl;
                cout << "Rooms Cleared: " << status.getNumRoomsCleared() << " | " << " Keys: " << status.getNumKeyFounds() << " | " << " Anger Level: " << status.getSorcerersAnger() << endl;
                cout << "+--------------+" << endl;
                cout << "INVENTORY" << endl;
                cout << "+--------------+" << endl;
                cout << "Gold: " << characters.getGold() << endl;
                cout << "Ingredients: " << items.getIngredientKg() << endl;
                cout << "Cookware: " << " P: " << items.getNumPot() <<  "| " << " F: " << items.getNumPan() << " | " << " C: "<< items.getNumCauldron()<<  endl;
                cout << "Weapons: " << " C: " << items.getNumClubs() <<  " | " << " S: " << items.getNumSpears() << " | " << " R: "<< items.getNumRapier() << " | " <<  " B: " << items.getNumAxe() << " | " <<  " L: " << items.getNumLongsword() << endl;
                cout << "Armor: " << items.numArmor() <<endl;
                cout << "Treasures: " << items.getNumTreasure() << " | " << " R: " << items.getNumRing() <<  " | " << " N: " << items.getNumNecklace() << " | " << " B: "<< items.getNumBracelet() << " | " <<  " C: " << items.getNumCirclet() << " | " << " G: " << items.getNumGoblet() << endl;
                cout << "+--------------+" << endl;
                cout << characters.getPlayerName() << " | " << " Fullness: " << characters.getHealthMain() << endl;
                if (characters.isN1Alive())
                {
                    cout << characters.getn1Name() << " | " << " Fullness: " << characters.getHealth1() << endl;
                }
                if (characters.isN2Alive())
                {
                    cout << characters.getn2Name() << " | " << " Fullness: " << characters.getHealth2() << endl;
                }
                if(characters.isN3Alive())
                {
                    cout << characters.getn3Name() << " | " << " Fullness: " << characters.getHealth3() << endl;
                }
                if(characters.isN4Alive())
                {
                    cout << characters.getn4Name() << " | " << " Fullness: " << characters.getHealth4() << endl;
                }
                cout << "+--------------+" << endl;
                if (characters.getTotalCharacters() <= 1)
                {
                    endGame(characters,items,status);
                }
                if (status.getSorcerersAnger() >= 100)
                {
                    endGame(characters,items,status);
                }

                continue;
            }
            else
            {
                cout << "You were defeated by the monster!" << endl;
                int goldLost = floor(characters.getGold() * 0.25);
                cout << "You lost " << goldLost <<" Gold!" << endl;
                characters.setGold(goldLost);
                cout << "You now have " << characters.getGold() << " Gold!" << endl;
                
                int foodLost = floor(items.getIngredientKg() * 0.15);
                if (foodLost > 30)
                {
                    foodLost = 30;
                }
                cout << "You also lost " << foodLost << "Kg of ingredients!" << endl;
                items.EatIngredient(foodLost);
                cout << "You now have " << items.getIngredientKg() << "Kg of ingredients." << endl;

                if (mons.wasN1Slain(items.doesN1HaveArmor()) == true)
                {
                    string name = characters.getn1Name();
                    cout << name << " was slain!!" << endl;
                    cout <<  name << " is out of the game!" << endl;
                    characters.removeCharacters(characters.getn1Name());
                    characters.killN1();
                    characters.setHealth1(characters.getHealth1());
                }
                if (mons.wasN2Slain(items.doesN2HaveArmor()) == true)
                {
                    string name = characters.getn2Name();
                    cout << name << " was slain!!" << endl;
                    cout <<  name << " is out of the game!" << endl;
                    characters.removeCharacters(characters.getn2Name());
                    characters.killN2();
                    characters.setHealth2(characters.getHealth2());
                }
                if (mons.wasN3Slain(items.doesN3HaveArmor()) == true)
                {
                    string name = characters.getn3Name();
                    cout << name << " was slain!!" << endl;
                    cout <<  name << " is out of the game!" << endl;
                    characters.removeCharacters(characters.getn3Name());
                    characters.killN3();
                    characters.setHealth3(characters.getHealth3());
                }
                if (mons.wasN4Slain(items.doesN4HaveArmor()) == true)
                {
                    string name = characters.getn4Name();
                    cout << name << " was slain!!" << endl;
                    cout <<  name << " is out of the game!" << endl;
                    characters.removeCharacters(characters.getn4Name());
                    characters.killN4();
                    characters.setHealth4(characters.getHealth4());
                }


                int randHealthMain = rand() % 2 + 1;
                if (randHealthMain == 1)
                {
                    cout << "Oh no! " << characters.getPlayerName() << " has lost a point of health!" << endl;
                    characters.setHealthMain(1);
                }
                int randHealth1 = rand() % 2 + 1;
                if (randHealth1 == 1)
                {
                    if (characters.isN1Alive())
                    {
                    cout << "Oh no! " << characters.getn1Name() << " has lost a point of health!" << endl;
                    characters.setHealth1(1);
                    }
                }
                int randHealth2 = rand() % 2 + 1;
                if (randHealth2 == 1)
                {
                    if(characters.isN2Alive())
                    {
                    cout << "Oh no! " << characters.getn2Name() << " has lost a point of health!" << endl;
                    characters.setHealth2(1);
                    }
                }
                int randHealth3 = rand() % 2 + 1;
                if (randHealth3 == 1)
                {
                    if (characters.isN3Alive())
                    {
                    cout << "Oh no! " << characters.getn3Name() << " has lost a point of health!" << endl;
                    characters.setHealth3(1);
                    }
                }
                int randHealth4 = rand() % 2 + 1;
                if (randHealth4 == 1)
                {
                    if (characters.isN4Alive())
                    {
                    cout << "Oh no! " << characters.getn4Name() << " has lost a point of health!" << endl;
                    characters.setHealth4(1);
                    }
                }


                cout << "+--------------+" << endl;
                cout << "STATUS" << endl;
                cout << "+--------------+" << endl;
                cout << "Rooms Cleared: " << status.getNumRoomsCleared() << " | " << " Keys: " << status.getNumKeyFounds() << " | " << " Anger Level: " << status.getSorcerersAnger() << endl;
                cout << "+--------------+" << endl;
                cout << "INVENTORY" << endl;
                cout << "+--------------+" << endl;
                cout << "Gold: " << characters.getGold() << endl;
                cout << "Ingredients: " << items.getIngredientKg() << endl;
                cout << "Cookware: " << " P: " << items.getNumPot() <<  "| " << " F: " << items.getNumPan() << " | " << " C: "<< items.getNumCauldron()<<  endl;
                cout << "Weapons: " << " C: " << items.getNumClubs() <<  " | " << " S: " << items.getNumSpears() << " | " << " R: "<< items.getNumRapier() << " | " <<  " B: " << items.getNumAxe() << " | " <<  " L: " << items.getNumLongsword() << endl;
                cout << "Armor: " << items.numArmor() <<endl;
                cout << "Treasures: " << items.getNumTreasure() << " | " << " R: " << items.getNumRing() <<  " | " << " N: " << items.getNumNecklace() << " | " << " B: "<< items.getNumBracelet() << " | " <<  " C: " << items.getNumCirclet() << " | " << " G: " << items.getNumGoblet() << endl;
                cout << "+--------------+" << endl;
                cout << characters.getPlayerName() << " | " << " Fullness: " << characters.getHealthMain() << endl;
                if (characters.isN1Alive())
                {
                    cout << characters.getn1Name() << " | " << " Fullness: " << characters.getHealth1() << endl;
                }
                if (characters.isN2Alive())
                {
                    cout << characters.getn2Name() << " | " << " Fullness: " << characters.getHealth2() << endl;
                }
                if(characters.isN3Alive())
                {
                    cout << characters.getn3Name() << " | " << " Fullness: " << characters.getHealth3() << endl;
                }
                if(characters.isN4Alive())
                {
                    cout << characters.getn4Name() << " | " << " Fullness: " << characters.getHealth4() << endl;
                }
                cout << "+--------------+" << endl;
                if (characters.getTotalCharacters() <= 1)
                {
                    endGame(characters,items,status);
                }
                if (status.getSorcerersAnger() >= 100)
                {
                    endGame(characters,items,status);
                }

                continue;

            }

            continue;
        }
        else if(choiceMove == 4)
        {
            char cookware;
            while (true)
            {
                cout << "Which cookware would you like to use? (C)auldron, (P)ot, or (F)rying pan? " << endl;
                cin >> cookware;
                
                //check if the player actually has the item they entered
                if (cookware == 'C')
                {
                    if (items.getNumCauldron() >= 0)
                    {
                        break;
                    }
                    else
                    {
                        cout << "You dont have a Cauldron!" << endl;
                    }
                }
                if (cookware == 'P')
                {
                    if (items.getNumPot() >= 0)
                    {
                        break;
                    }
                    else
                    {
                        cout << "You dont have a Ceramic Pot!" << endl;
                    }
                }
                if (cookware == 'F')
                {
                    if (items.getNumPan() >= 0)
                    {
                        break;
                    }
                    else
                    {
                        cout << "You dont have a Frying Pan!" << endl;
                    }
                }
                else
                {
                    cout << "Invalid input. Please enter one of the following 'C', 'P', or 'F'." << endl;
                }
            }
            int successRate;
            //set success rate for each item
            if(cookware == 'C') 
            {
                successRate = 98;
            } 
            else if(cookware == 'P')
            {
                successRate = 75;
            } 
            else if(cookware == 'F')
            {
                successRate = 90;
            }

            int kg;
            while (true){
                cout << "What weight of ingredients (in increments of 5 kg) would you want to cook? " << endl;
                cin >> kg;
                if(kg % 5 == 0)
                {
                    break;
                }
                else if (kg > items.getIngredientKg())
                {
                    cout << "You don't have " << kg << " ingredients!" << endl;
                }
                else{
                    cout << "Invalid input. Please enter a number that is divisible by 5." << endl;
                }
    
            }

            int randomNumber = rand() % 100;
            if(randomNumber >= successRate){
                cout << "The cookware broke! Your meal was not able to be created, and your ingredients were lost!" << endl;
                items.removeCookware(cookware);
            } 
            else{
                cout << "The meal was created successfully!" << endl;
                characters.setHealthMain(-kg/5);
                if (characters.isN1Alive()== true)
                {
                    characters.setHealth1(-kg/5);
                }
                if (characters.isN2Alive()== true)
                {
                    characters.setHealth2(-kg/5);
                }
                if (characters.isN3Alive()== true)
                {
                    characters.setHealth3(-kg/5);
                }
                if (characters.isN4Alive()== true)
                {
                    characters.setHealth4(-kg/5);
                }
                items.EatIngredient(kg);
            }

            cout << "+--------------+" << endl;
            cout << "STATUS" << endl;
            cout << "+--------------+" << endl;
            cout << "Rooms Cleared: " << status.getNumRoomsCleared() << " | " << " Keys: " << status.getNumKeyFounds() << " | " << " Anger Level: " << status.getSorcerersAnger() << endl;
            cout << "+--------------+" << endl;
            cout << "INVENTORY" << endl;
            cout << "+--------------+" << endl;
            cout << "Gold: " << characters.getGold() << endl;
            cout << "Ingredients: " << items.getIngredientKg() << endl;
            cout << "Cookware: " << " P: " << items.getNumPot() <<  "| " << " F: " << items.getNumPan() << " | " << " C: "<< items.getNumCauldron()<<  endl;
            cout << "Weapons: " << " C: " << items.getNumClubs() <<  " | " << " S: " << items.getNumSpears() << " | " << " R: "<< items.getNumRapier() << " | " <<  " B: " << items.getNumAxe() << " | " <<  " L: " << items.getNumLongsword() << endl;
            cout << "Armor: " << items.numArmor() <<endl;
            cout << "Treasures: " << items.getNumTreasure() << " | " << " R: " << items.getNumRing() <<  " | " << " N: " << items.getNumNecklace() << " | " << " B: "<< items.getNumBracelet() << " | " <<  " C: " << items.getNumCirclet() << " | " << " G: " << items.getNumGoblet() << endl;
            cout << "+--------------+" << endl;
            cout << characters.getPlayerName() << " | " << " Fullness: " << characters.getHealthMain() << endl;
            if (characters.isN1Alive())
            {
                cout << characters.getn1Name() << " | " << " Fullness: " << characters.getHealth1() << endl;
            }
            if (characters.isN2Alive())
            {
                cout << characters.getn2Name() << " | " << " Fullness: " << characters.getHealth2() << endl;
            }
            if(characters.isN3Alive())
            {
                cout << characters.getn3Name() << " | " << " Fullness: " << characters.getHealth3() << endl;
            }
            if(characters.isN4Alive())
            {
                cout << characters.getn4Name() << " | " << " Fullness: " << characters.getHealth4() << endl;
            }
            cout << "+--------------+" << endl;
            if (characters.getTotalCharacters() <= 1)
            {
                endGame(characters,items,status);
            }
            if (status.getSorcerersAnger() >= 100)
            {
                endGame(characters,items,status);
            }
        }
        status.setNumTurns(1);
    }
    endGame(characters, items, status);
    return 0;
}
