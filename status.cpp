// CSCI 1300 Spring 2023
// Author: Valeria Saldana & Emiliano Medina
// Project 3

#include "status.h"
#include "items.h"
#include "monsters.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <ctype.h>
#include <cassert>


using namespace std;

Status::Status()
{
    numRoomsCleared = 0;
    numKeyFound = 0;
    fullnessLevel = 0;
    ingredientsAvail = 0;
    cookwareAvail = 0;
    weaponsAvail = 0;
    armorAvail = 0;
    goldPiecesAvail = 100;
    treasureItemAvail = 0;
    sorcerersAnger = 0;
    numSpacesExplored = 0;
    numMonstersDefeated = 0;
    numTurns = 0;
}
Status::Status(int numRoomsCleared_, int numKeyFounds_, int fullnessLevel_, int ingredientsAvail_, int cookwareAvail_, int weaponsAvail_, int armorAvail_, int goldPiecesAvail_, int treasureItemAvail_, int sorcerersAnger_)
{
    numRoomsCleared = numRoomsCleared_;
    numKeyFound = numKeyFounds_;
    fullnessLevel = fullnessLevel_;
    ingredientsAvail = ingredientsAvail_;
    cookwareAvail = cookwareAvail_;
    weaponsAvail = weaponsAvail_;
    armorAvail = armorAvail_;
    goldPiecesAvail = goldPiecesAvail_;
    treasureItemAvail = treasureItemAvail_;
    sorcerersAnger = sorcerersAnger_;
}
//setters
void Status::setNumRoomsCleared(int roomsCleared){
    numRoomsCleared += roomsCleared;
}

void Status::setNumKeyFounds(int keyFound){
    numKeyFound += keyFound;
}

void Status::setFullnessLevel(int fullnessL){
    fullnessLevel += fullnessL;
}

void Status::setIngredientsAvail(int ingredientsA){
    ingredientsAvail += ingredientsA;
}

void Status::setCookwareAvail(int cookwareA){
    cookwareAvail += cookwareA;
}

void Status::setWeaponsAvail(int weaponsA){
    weaponsAvail += weaponsA;
}

void Status::setArmorAvail(int armorA){
    armorAvail += armorA;
}

void Status::setGoldPiecesAvail(int goldPiecesA){
    goldPiecesAvail += goldPiecesA;
}

void Status::setTreasureItemAvail(int treasureA){
    treasureItemAvail += treasureA;
}

void Status::setSorcerersAnger(int sorcerersA){
    sorcerersAnger += sorcerersA;
}

void Status :: setNumSpacesExplored(int explored)
{
    numSpacesExplored += explored;
}

void Status :: setNumMonstersDefeated(int mons)
{
    numMonstersDefeated += mons;
    //vector of monster objects to add to when monster is defeated
    vector <Monsters> monsterVector;
}

void Status :: setNumTurns(int turns)
{
    numTurns += turns;
}

//getters
int Status::getNumRoomsCleared(){
    return numRoomsCleared;
}
int Status::getNumKeyFounds(){
    int keys = numKeyFound;
    if (keys < 0)
    {
        keys = 0;
    }
    return keys;
}
int Status::getFullnessLevel(){
    return fullnessLevel;
}

int Status::getIngredientsAvail(){
    return ingredientsAvail;
}

int Status::getCookwareAvail(){
    return cookwareAvail;
}

int Status::getWeaponsAvail(){
    return weaponsAvail;
}

int Status::getArmorAvail(){
    return armorAvail;
}

int Status::getGoldPiecesAvail(){
    return goldPiecesAvail;
}

int Status::getTreasureItemAvail(){
    return treasureItemAvail;
}

int Status::getSorcerersAnger(){
    return sorcerersAnger;
}

int Status::getNumSpacesExplored()
{
    return numSpacesExplored;
}

int Status :: getNumMonstersDefeated()
{
    return numMonstersDefeated;
}

int Status :: getNumTurns()
{
    return numTurns;
}
