// CSCI 1300 Spring 2023
// Author: Valeria Saldana & Emiliano Medina
// Project 3

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <ctime>
#include "monsters.h"
#include "items.h"

using namespace std;

Monsters :: Monsters()
{
    monsterName = "";
    powerLevel = 0;
    sorcerersAnger = 0;
}

Monsters::Monsters(string monsterNameUser, int powerSet)
{
    srand(time(0));
    if (powerSet == 0)
    {
        int randomnum = rand() % 5;
        vector <string> lvl0 = {"Animated Armor", "Bugbear", "Grossbug", "Harpy", "Scarecrow"};

        monsterName = lvl0[randomnum];
        powerLevel = 1;

        if (randomnum == 0)
        {
            lvl0.erase(lvl0.begin());
        }
        else if (randomnum == 1)
        {
            lvl0.erase(lvl0.begin()+1);
        }
        else if (randomnum == 2)
        {
            lvl0.erase(lvl0.begin()+2);
        }
        else if (randomnum == 3)
        {
            lvl0.erase(lvl0.begin()+3);
        }
        else if (randomnum == 4)
        {
            lvl0.erase(lvl0.begin()+4);
        }
    }
    else if (powerSet == 1)
    {
        int randomnum = rand() % 5;
        vector <string> lvl1 = {"Giant Crocodile", "Troll", "Brinecat", "Hobgoblin Warlord", "Mammoth"};

        monsterName = lvl1[randomnum];
        powerLevel = 3;

        if (randomnum == 0)
        {
            lvl1.erase(lvl1.begin());
        }
        else if (randomnum == 1)
        {
            lvl1.erase(lvl1.begin()+1);
        }
        else if (randomnum == 2)
        {
            lvl1.erase(lvl1.begin()+2);
        }
        else if (randomnum == 3)
        {
            lvl1.erase(lvl1.begin()+3);
        }
        else if (randomnum == 4)
        {
            lvl1.erase(lvl1.begin()+4);
        }
    }
    else if (powerSet == 2)
    {
        int randomnum = rand() % 5;
        vector <string> lvl2 = {"Stone Giant", "Night Hag", "Assassin", "Hydra", "Vapormutant"};

        monsterName = lvl2[randomnum];
        powerLevel = 4;

        if (randomnum == 0)
        {
            lvl2.erase(lvl2.begin());
        }
        else if (randomnum == 1)
        {
            lvl2.erase(lvl2.begin()+1);
        }
        else if (randomnum == 2)
        {
            lvl2.erase(lvl2.begin()+2);
        }
        else if (randomnum == 3)
        {
            lvl2.erase(lvl2.begin()+3);
        }
        else if (randomnum == 4)
        {
            lvl2.erase(lvl2.begin()+4);
        }
    }
    else if (powerSet == 3)
    {
        int randomnum = rand() % 5;
        vector <string> lvl3 = {"Cloud Giant", "Silver Dragon", "Vampire", "Lich", "Germeyes"};

        monsterName = lvl3[randomnum];
        powerLevel = 5;

        if (randomnum == 0)
        {
            lvl3.erase(lvl3.begin());
        }
        else if (randomnum == 1)
        {
            lvl3.erase(lvl3.begin()+1);
        }
        else if (randomnum == 2)
        {
            lvl3.erase(lvl3.begin()+2);
        }
        else if (randomnum == 3)
        {
            lvl3.erase(lvl3.begin()+3);
        }
        else if (randomnum == 4)
        {
            lvl3.erase(lvl3.begin()+4);
        }
    }
    else if (powerSet == 4)
    {
        monsterName = "Sorcerer";
        powerLevel = 6;
    }
}


bool Monsters :: getFightResult(int extraPoints, int numWeapons, int differentWeapons, int numArmor)
{
    bool end = false;
    int r1 = 1 + (rand() % 6);
    int r2 = 1 + (rand() % 6);
    int w = numWeapons + extraPoints; 
    int d;
    if (differentWeapons == 1)//either 4 or 0, depending on whether each member has a different type of weapon (will get fron items class)
    {
        d = 4;
    }
    else
    {
        d = 0;
    }
    int a = numArmor; 
    int c = powerLevel;

    if (a == 0)
    {
        return false;
    }

    float result = float(((r1 * w + d) - (r2 * c)) / a);

    if (result > 0)
    {
        end = true;
    }
    else
    {
        end = false;
    }
    return end;
}

int Monsters :: getPower()
{
    return powerLevel;
}

string Monsters :: getMonsterName(){
    return monsterName;
}

string Monsters :: dropKey()
{
    srand(time(0));
    int dropKey = rand() % 100 + 1;
    if (dropKey > 0 && dropKey <= 10)
    {
        string s = "The monster dropped a key!";
        return s;
    }
    else
    {
        return "";
    }
}

bool Monsters :: wasN1Slain(bool has_armor)
{
    if (has_armor == true)
    {
        int n1Slay = (rand() % 100) + 1;
        if (n1Slay <= 5 && n1Slay > 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        int n1Slay = (rand() % 100) + 1;
        if (n1Slay <= 10 && n1Slay > 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

bool Monsters :: wasN2Slain(bool has_armor)
{
    if ( has_armor == true)
    {
        int n2Slay = (rand() % 100) + 1;
        if (n2Slay <= 5 && n2Slay > 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        int n2Slay = (rand() % 100) + 1;
        if (n2Slay <= 10 && n2Slay > 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

bool Monsters :: wasN3Slain(bool has_armor)
{
    if ( has_armor == true)
    {
        int n3Slay = (rand() % 100) + 1;
        if (n3Slay <= 5 && n3Slay > 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        int n3Slay = (rand() % 100) + 1;
        if (n3Slay <= 10 && n3Slay > 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

bool Monsters :: wasN4Slain(bool has_armor)
{
    if ( has_armor == true)
    {
        int n4Slay = (rand() % 100) + 1;
        if (n4Slay <= 5 && n4Slay > 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        int n4Slay = (rand() % 100) + 1;
        if (n4Slay <= 10 && n4Slay > 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
