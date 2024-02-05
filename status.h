// CSCI 1300 Spring 2023
// Author: Valeria Saldana & Emiliano Medina
// Project 3

#ifndef STATUS_H
#define STATUS_H
#include <string>
#include <iostream>
using namespace std;

class Status
{
    public:
    // Default Constructor

    Status();
    Status(int numRoomsCleared_, int numKeyFounds_, int fullnessLevel_, int ingredientsAvail_, int cookwareAvail_, int weaponsAvail_, int armorAvail_, int goldPiecesAvail_, int treasureItemAvail_, int sorcerersAnger_);

    //setters
    void setNumRoomsCleared(int);
    void setNumKeyFounds(int);
    void setFullnessLevel(int);
    void setIngredientsAvail(int);
    void setCookwareAvail(int);
    void setWeaponsAvail(int);
    void setArmorAvail(int);
    void setGoldPiecesAvail(int);
    void setTreasureItemAvail(int);
    void setSorcerersAnger(int);
    void setNumSpacesExplored(int);
    void setNumMonstersDefeated(int);
    void setNumTurns(int);

    //getters
    int getNumRoomsCleared();
    int getNumKeyFounds();
    int getFullnessLevel();
    int getIngredientsAvail();
    int getCookwareAvail();
    int getWeaponsAvail();
    int getArmorAvail();
    int getGoldPiecesAvail();
    int getTreasureItemAvail();
    int getSorcerersAnger();
    int getNumSpacesExplored();
    int getNumMonstersDefeated();
    int getNumTurns();

    private:
    int numRoomsCleared;
    int numKeyFound;
    int fullnessLevel;
    int ingredientsAvail;
    int cookwareAvail;
    int weaponsAvail;
    int armorAvail;
    int goldPiecesAvail;
    int treasureItemAvail;
    int sorcerersAnger;
    int numSpacesExplored;
    int numMonstersDefeated;
    int numTurns;
};
#endif
