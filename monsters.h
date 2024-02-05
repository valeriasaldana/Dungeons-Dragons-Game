// CSCI 1300 Spring 2023
// Author: Valeria Saldana & Emiliano Medina
// Project 3

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Monsters
{
    public:
    Monsters();
    Monsters(string monsterName, int powerSet);
    //getters
    bool getFightResult(int extraPoints, int numWeapons, int differentWeapons, int numArmor);
    string getMonster();
    int getPower();
    string getMonsterName();
    string dropKey();
    bool wasN1Slain(bool has_armor);
    bool wasN2Slain(bool has_armor);
    bool wasN3Slain(bool has_armor);
    bool wasN4Slain(bool has_armor);


    private:
    int powerLevel = 0;
    int sorcerersAnger = 0;
    string monsterName;


    
};
