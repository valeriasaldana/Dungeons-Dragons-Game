// CSCI 1300 Spring 2023
// Author: Valeria Saldana & Emiliano Medina
// Project 3

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Items 
{
    private:
    
    int numWeapons; 
    char weapons;
    vector<char> weaponsTotal;
    int ingredients;
    char cookware;
    vector<char> cookwareTotal;
    char armor;
    char treasure;
    vector <char> allTreasure;
    int Armor;
    int Keys;


    public:
    Items();
    Items(char weapon, int ingredientkg, char cookWare, char carmor, int newKeys);

    int getIngredientPrice();
    int getIngredientKg();
    void setIngredientKg(int kg);
    void EatIngredient(int kgUsed);
    int getWeaponPrice();
    string getWeapon();
    void setWeapon( char boughtWeapon);
    int getArmorPrice();
    string getArmor();
    void setArmor( int NumBoughtArmor );
    int getCookwarePrice();
    string getCookware();
    void setCookware( char boughtCookware );
    void setTreasure(char newTreasure);
    void setKeys(int numKeys);
    int getKeys();
    bool checkForRing();
    int getNumRing();
    bool checkForNecklace();
    int getNumNecklace();
    bool checkForBracelet();
    int getNumBracelet();
    bool checkForCirclet();
    int getNumCirclet();
    bool checkForGoblet();
    int getNumGoblet();
    int sellingTreasures(char item);
    bool useCookware();
    bool differentWeapons();
    int numArmor();
    int getNumWeapons();
    int getNumTreasure();
    int extraWeaponPoints();

    bool doesN1HaveArmor();
    bool doesN2HaveArmor();
    bool doesN3HaveArmor();
    bool doesN4HaveArmor();

    int getNumPot();
    int getNumPan();
    int getNumCauldron();

    int getNumClubs();
    int getNumSpears();
    int getNumRapier();
    int getNumAxe();
    int getNumLongsword();

    int getNumCookware();

    string getRandomCookware();
    string getRandomWeapon();

    void removeCookware(char remove);
    void removeWeapons(char remove);

};
