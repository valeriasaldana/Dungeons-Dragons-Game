// CSCI 1300 Spring 2023
// Author: Valeria Saldana & Emiliano Medina
// Project 3

#include <iostream>
#include "items.h"
#include "characters.h"

using namespace std;

Items :: Items()
{
    numWeapons = 0;
    ingredients = 0;
    Keys = 0;
    Armor = 0;
}

Items :: Items(char weapon, int ingredientkg, char cookWare, char carmor, int newKeys)
{
    weapons += weapon;
    weaponsTotal.push_back(weapon);
    ingredients += ingredientkg;
    cookware += cookWare;
    cookwareTotal.push_back(cookWare);
    armor += carmor;
    Keys += newKeys;
}

void Items :: setIngredientKg(int kg)
{
    ingredients += kg;
}

void Items :: EatIngredient(int kgUsed)
{
    ingredients -= kgUsed;
    if (ingredients < 0)
    {
        ingredients = 0;
    }
}

int Items :: getIngredientPrice()
{
    return ingredients;
}

int Items :: getIngredientKg()
{
    return ingredients;
}

void Items :: setWeapon(char boughtWeapon)
{
    if(numWeapons < 5){
        weaponsTotal.push_back(boughtWeapon);
        weapons = boughtWeapon;
        numWeapons++;
    }
}

int Items :: getWeaponPrice()
{
   int weaponsPrice = 0;
   switch(weapons){
    case 'C':
    weaponsPrice = 2;
    break;
    case 'S':
    weaponsPrice = 2;
    break;
    case 'R':
    weaponsPrice = 5;
    break;
    case 'B':
    weaponsPrice = 15;
    break;
    case 'L':
    weaponsPrice = 50;
    break;
default:
    break;
    }
    return weaponsPrice;
}
string Items :: getWeapon()
{
    string weaponName;
    switch(weapons){
        case 'C':
        weaponName = "Club";
        break;
        case 'S':
        weaponName = "Spear";
        break;
        case 'R':
        weaponName = "+1 rapier";
        break;
        case 'B':
        weaponName = "+2 Battle-Axe";
        break;
        case 'L':
        weaponName = "+3 Longsword";
        break;
        default:
        weaponName = "none";
        break;
    }
    return weaponName;
}
void Items :: setArmor(int NumBoughtArmor)
{
    Armor += NumBoughtArmor;
}

int Items :: getArmorPrice()
{
    return 5;
}
string Items :: getArmor()
{
    string armorName;
    switch(armor){
        case 'A':
        armorName = "Armor";
        break;
    default: 
        armorName = "None";
        break;
    }
    return armorName;
}

void Items :: setCookware(char boughtCookware)
{
    cookwareTotal.push_back(boughtCookware);
    cookware = boughtCookware;
}

int Items :: getCookwarePrice()
{
    int price = 0;
    switch (cookware){
        case 'P':
        price = 2;
        break;
        case 'F':
        price = 10;
        break;
        case 'C':
        price = 20;
        break;
    default:
        break;
    }
    return price;
}
string Items :: getCookware()
{
    string cookwareName;
    switch (cookware){
        case 'P':
        cookwareName = "Ceramic pot";
        break;
        case 'F':
        cookwareName = "Frying Pan";
        break;
        case 'C':
        cookwareName = "Cauldron";
        break;
    default:
        cookwareName = "None";
        break;
    }
    return cookwareName;
}

void Items :: setTreasure(char newTreasure)
{
    allTreasure.push_back(newTreasure);
    treasure = newTreasure;
}

void Items :: setKeys(int numKeys)
{
    Keys += numKeys;
}

int Items :: getKeys()
{
    return Keys;
}

bool Items :: checkForRing()
{
    bool tf = false;
    for (int i = 0; i < allTreasure.size(); i++)
    {
        if(allTreasure[i] == 'R')
        {
            tf = true;
        }
                        
    }
    return tf;
}

int Items :: getNumRing()
{
    int numR = 0;
    for (int i = 0; i < allTreasure.size(); i++)
    {
        if(allTreasure[i] == 'R')
        {
            numR++;
        }
                        
    }
    return numR;
}

bool Items :: checkForNecklace()
{
    bool t = false;
    for (int j = 0; j < allTreasure.size(); j++)
    {
        if(allTreasure[j] == 'N')
        {
            t = true;
        }
                        
    }
    return t;
}

int Items :: getNumNecklace()
{
    int numN = 0;
    for (int j = 0; j < allTreasure.size(); j++)
    {
        if(allTreasure[j] == 'N')
        {
            numN++;
        }
                        
    }
    return numN;
}

bool Items :: checkForBracelet()
{
    bool f = false;
    for (int k = 0; k < allTreasure.size(); k++)
    {
        if(allTreasure[k] == 'B')
        {
            f = true;
        }
                        
    }
    return f;
}

int Items :: getNumBracelet()
{
    int numB = 0;
    for (int k = 0; k < allTreasure.size(); k++)
    {
        if(allTreasure[k] == 'B')
        {
            numB++;
        }
                        
    }
    return numB;
}

bool Items :: checkForCirclet()
{
    bool ft = false;
    for (int l = 0; l < allTreasure.size(); l++)
    {
        if(allTreasure[l] == 'C')
        {
            ft = true;
        }
                        
    }
    return ft;
}

int Items :: getNumCirclet()
{
    int numC = 0;
    for (int l = 0; l < allTreasure.size(); l++)
    {
        if(allTreasure[l] == 'C')
        {
            numC++;
        }
                        
    }
    return numC;
}

bool Items :: checkForGoblet()
{
    bool ftt = false;
    for (int v = 0; v < allTreasure.size(); v++)
    {
        if(allTreasure[v] == 'G')
        {
            ftt = true;
        }
                        
    }
    return ftt;
}

int Items :: getNumGoblet()
{
    int numG = 0;
    for (int v = 0; v < allTreasure.size(); v++)
    {
        if(allTreasure[v] == 'G')
        {
            numG++;
        }
                        
    }
    return numG;
}

int Items :: sellingTreasures(char item)
{
    int treasurePrice;
    switch (item){
        case 'R':
        treasurePrice = 10;
        break;
        case 'N':
        treasurePrice = 20;
        break;
        case 'B':
        treasurePrice = 30;
        break;
        case 'C':
        treasurePrice = 40;
        break;
        case 'G':
        treasurePrice = 50;
        break;
    }
    return treasurePrice;
}
bool Items ::  useCookware()
{   
    int cookwareChance;
    switch (cookware){
    
    case 'P':
    cookwareChance = rand() % 99 + 0;
    return (cookwareChance >= 1 && cookwareChance <= 25);
    break;

    case 'F':
    cookwareChance = rand() % 99 + 0;
    return (cookwareChance >= 1 && cookwareChance <= 10);
    break;
    
    case 'C':
    cookwareChance = rand() % 99 + 0;
    return (cookwareChance >= 1 && cookwareChance <= 2);
    break;

    default: 
    return false;
    }
}

bool Items :: differentWeapons()
{
   int numWeapons = weaponsTotal.size();
   int count = 0;
   for (int i = 0; i < numWeapons; i++)
   {
        if (weaponsTotal[i] == 'C')
        {
            count++;
        }
   }
    int coun =0;
   for (int j = 0; j < numWeapons; j++)
   {
        if (weaponsTotal[j] == 'S')
        {
            coun++;
        }
   }

    int cou =0;
   for (int k = 0; k < numWeapons; k++)
   {
        if (weaponsTotal[k] == 'R')
        {
            cou++;
        }
   }
    int co =0;
   for (int r = 0; r < numWeapons; r++)
   {
        if (weaponsTotal[r] == 'B')
        {
            co++;
        }
   }

    int c =0;
   for (int l = 0; l < numWeapons; l++)
   {
        if (weaponsTotal[l] == 'L')
        {
            c++;
        }
   }

   if ((count + coun + cou + co + c) > 4)
   {
        return true;
   }
   else
   {
    return false;
   }
}

int Items :: getNumWeapons()
{
    return weaponsTotal.size();
}

int Items :: numArmor()
{
    return Armor;
}

int Items :: getNumTreasure()
{
    return allTreasure.size();
}

int Items :: extraWeaponPoints()
{
    int mythrilpoints = 0;
    int flamingpoints = 0;
    int vorpalpoints = 0;

    for (int b = 0; b < weaponsTotal.size(); b++)
    {
        if (weaponsTotal[b] == 'R')
        {
            mythrilpoints++;
        }
        if (weaponsTotal[b] == 'B')
        {
            flamingpoints += 2;
        }
        if (weaponsTotal[b] == 'L')
        {
            vorpalpoints += 3;
        }
    }
    return (mythrilpoints + flamingpoints + vorpalpoints);
}

bool Items:: doesN1HaveArmor()
{
    if (Armor > 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Items:: doesN2HaveArmor()
{
    if (Armor > 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Items:: doesN3HaveArmor()
{
    if (Armor > 3)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Items:: doesN4HaveArmor()
{
    if (Armor > 4)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int Items:: getNumPot()
{
    int count = 0;
    for (int i = 0; i < cookwareTotal.size(); i++)
    {
        if(cookwareTotal[i] == 'P')
        {
            count++;
        }
    }
    return count;
}

int Items:: getNumPan()
{
    int count = 0;
    for (int i = 0; i < cookwareTotal.size(); i++)
    {
        if(cookwareTotal[i] == 'F')
        {
            count++;
        }
    }
    return count;
}

int Items:: getNumCauldron()
{
    int count = 0;
    for (int i = 0; i < cookwareTotal.size(); i++)
    {
        if(cookwareTotal[i] == 'C')
        {
            count++;
        }
    }
    return count;
}

int Items:: getNumClubs()
{
    int count = 0;
    for (int i = 0; i < weaponsTotal.size(); i++)
    {
        if(weaponsTotal[i] == 'C')
        {
            count++;
        }
    }
    return count;
}

int Items:: getNumSpears()
{
    int count = 0;
    for (int i = 0; i < weaponsTotal.size(); i++)
    {
        if(weaponsTotal[i] == 'S')
        {
            count++;
        }
    }
    return count;
}

int Items:: getNumRapier()
{
    int count = 0;
    for (int i = 0; i < weaponsTotal.size(); i++)
    {
        if(weaponsTotal[i] == 'R')
        {
            count++;
        }
    }
    return count;
}

int Items:: getNumAxe()
{
    int count = 0;
    for (int i = 0; i < weaponsTotal.size(); i++)
    {
        if(weaponsTotal[i] == 'B')
        {
            count++;
        }
    }
    return count;
}

int Items:: getNumLongsword()
{
    int count = 0;
    for (int i = 0; i < weaponsTotal.size(); i++)
    {
        if(weaponsTotal[i] == 'L')
        {
            count++;
        }
    }
    return count;
}

int Items:: getNumCookware()
{
    int total = cookwareTotal.size();
    if (cookwareTotal.size() == 0)
    {
        return 0;
    }
    return total;
}

string Items :: getRandomCookware()
{
    srand(time(0));
    int size = cookwareTotal.size();
    int r = rand() % (size - 1);

    if (cookwareTotal[r] == 'P')
    {
        return "Ceramic pot";
    }
    else if (cookwareTotal[r] == 'F')
    {
        return "Frying pan";
    }
    else if (cookwareTotal[r] == 'C')
    {
        return "Cauldron";
    }
    else
    {
        return "";
    }
}

string Items :: getRandomWeapon()
{
    srand(time(0));
    int size = weaponsTotal.size();
    int r = rand() % (size - 1);

    if(weaponsTotal[r] == 'C')
    {
        return "Club";
    }
    else if (weaponsTotal[r] == 'S')
    {
        return "Spear";
    }
    else if (weaponsTotal[r] == 'R')
    {
        return "+1 Rapier";
    }
    else if (weaponsTotal[r] == 'B')
    {
        return "+2 Battle-Axe";
    }
    else if (weaponsTotal[r] == 'L')
    {
        return "+3 Longsword";
    }
    else
    {
        return "";
    }
}

void Items :: removeCookware(char remove)
{
    int count = 0;
    for (int i = 0; i < cookwareTotal.size(); i++)
    {
        if (cookwareTotal[i] != remove)
        {
            count++;
        }
    }
    cookwareTotal.erase(cookwareTotal.begin() + count);
}

void Items :: removeWeapons(char remove)
{
    int count = 0;
    for (int i = 0; i < weaponsTotal.size(); i++)
    {
        if (weaponsTotal[i] != remove)
        {
            count++;
        }
    }
    weaponsTotal.erase(weaponsTotal.begin() + count);
}
