// CSCI 1300 Spring 2023
// Author: Valeria Saldana & Emiliano Medina
// Project 3

#include <iostream>
#include <vector>

using namespace std;

class Characters
{
    private:
    string nplayer;
    string n1;
    string n2;
    string n3;
    string n4;
    vector<string> allCharacters;
    int gold;
    int healthMain;
    int health1;
    int health2;
    int health3;
    int health4;

    bool n1alive;
    bool n2alive;
    bool n3alive;
    bool n4alive;


    public:
    Characters();
    Characters(string input_nplayer, string input_n1, string input_n2, string input_n3, string input_n4, int gold_, int healthMain_, int health1_, int health2_, int health3_, int health4_);
    string getPlayerName();
    string getn1Name();
    string getn2Name();
    string getn3Name();
    string getn4Name();
    void setPlayerName(string playerName);
    void setn1Name(string n1Name);
    void setn2Name(string n2Name);
    void setn3Name(string n3Name);
    void setn4Name(string n4Name);
    int getGold();
    void setGold( int input_gold );
    int getHealthMain();
    int getHealth1();
    int getHealth2();
    int getHealth3();
    int getHealth4();
    void setHealthMain( int input_health );
    void setHealth1( int input_healt );
    void setHealth2( int input_heal );
    void setHealth3( int input_hea );
    void setHealth4( int input_he );

    bool stillFullMain();
    bool stillFulln1();
    bool stillFulln2();
    bool stillFulln3();
    bool stillFulln4();

    void addCharacters(string name);
    void removeCharacters(string name);

    void killN1();
    void killN2();
    void killN3();
    void killN4();

    bool isN1Alive();
    bool isN2Alive();
    bool isN3Alive();
    bool isN4Alive();

    int getTotalCharacters();

};
