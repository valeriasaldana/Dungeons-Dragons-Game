// CSCI 1300 Spring 2023
// Author: Valeria Saldana & Emiliano Medina
// Project 3

#include <iostream>
#include "characters.h"

using namespace std;

Characters :: Characters()
{
    nplayer = "";
    n1 = "";
    n2 = "";
    n3 = "";
    n4 = "";
    gold = 100;
    healthMain = 50;
    health1 = 50;
    health2 = 50;
    health3 = 50;
    health4 = 50;
    allCharacters = {nplayer, n1, n2, n3, n4};
    n1alive = true;
    n2alive = true;
    n3alive = true;
    n4alive = true;
}

Characters :: Characters(string input_nplayer, string input_n1, string input_n2, string input_n3, string input_n4, int gold_, int healthMain_, int health1_, int health2_, int health3_, int health4_)
{
    nplayer = input_nplayer;
    n1 = input_n1;
    n2 = input_n2;
    n3 = input_n3;
    n4 = input_n4;
    gold = gold_;
    healthMain = healthMain_;
    health1 = health1_;
    health2 = health2_;
    health3 = health3_;
    health4 = health4_;
    allCharacters = {input_nplayer, input_n1, input_n2, input_n3, input_n4};
}

string Characters :: getPlayerName()
{
    return nplayer;
}

string Characters :: getn1Name()
{
    return n1;
}

string Characters :: getn2Name()
{
    return n2;
}

string Characters :: getn3Name()
{
    return n3;
}

string Characters :: getn4Name()
{
    return n4;
}

void Characters :: setPlayerName(string playerName)
{
    nplayer += playerName;
}

void Characters :: setn1Name(string n1Name)
{
    n1 += n1Name;
}

void Characters :: setn2Name(string n2Name)
{
    n2 += n2Name;
}

void Characters :: setn3Name(string n3Name)
{
    n3 += n3Name;
}

void Characters :: setn4Name(string n4Name)
{
    n4 += n4Name;
}

void Characters :: setGold( int input_gold )
{
    gold -= input_gold;
}

int Characters :: getGold()
{
    return gold;
}

void Characters :: setHealthMain( int input_health )
{
    healthMain -= input_health;
}

void Characters :: setHealth1( int input_healt )
{
    health1 -= input_healt;
}

void Characters :: setHealth2( int input_heal )
{
    health2 -= input_heal;
}

void Characters :: setHealth3( int input_hea )
{
    health3 -= input_hea;
}

void Characters :: setHealth4( int input_he )
{
    health4 -= input_he;
}

int Characters :: getHealthMain()
{
    if (healthMain <= 0)
    {
        return 0;
    }
    return healthMain;
}

int Characters :: getHealth1()
{
    if (health1 <= 0)
    {
        return 0;
    }
    return health1;
}

int Characters :: getHealth2()
{
    if (health2 <= 0)
    {
        return 0;
    }
    return health2;
}

int Characters :: getHealth3()
{
    if (health3 <= 0)
    {
        return 0;
    }
    return health3;
}

int Characters :: getHealth4()
{
    if (health4 <= 0)
    {
        return 0;
    }
    return health4;
}

bool Characters :: stillFullMain()
{
    if (healthMain > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Characters :: stillFulln1()
{
    if(health1 > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Characters :: stillFulln2()
{
    if(health2 > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Characters :: stillFulln3()
{
    if(health3 > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Characters :: stillFulln4()
{
    if(health4 > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Characters :: addCharacters(string name)
{
    allCharacters.push_back(name);
}

void Characters :: removeCharacters(string name)
{
    int count = 0;
    for (int i = 0; i < allCharacters.size(); i++)
    {
        if (allCharacters[i] != name)
        {
            count++;
        }
    }
    allCharacters.erase(allCharacters.begin() + count);
}

void Characters :: killN1()
{
    n1alive = false;
}

bool Characters :: isN1Alive()
{
    if (health1 > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Characters :: killN2()
{
    n2alive = false;
}

bool Characters :: isN2Alive()
{
    if (health2 > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Characters :: killN3()
{
    n3alive = false;
}

bool Characters :: isN3Alive()
{
    if (health3 > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Characters :: killN4()
{
    n4alive = false;
}

bool Characters :: isN4Alive()
{
    if (health4 > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int Characters :: getTotalCharacters()
{
    int size = allCharacters.size();
    return size;
}
