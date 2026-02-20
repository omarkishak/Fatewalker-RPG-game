#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <random>


using namespace std;

#include <string>
using namespace std;

class player {
public:
    string playerName;
    double health;
    static double luck;
    double attack;
    int coins;

    player(string name) {
        playerName = name;
        health = 100;
        luck = 100;
        attack = 20;
        coins = 0;
    }

    //Getters
    string getPlayerName()  { return playerName; }
    double getHealth()      { return health; }
    static double getLuck() { return luck; }
    double getAttack()      { return attack; }
    int getCoins()          { return coins; }

    //Setters
    void setPlayerName(string name) { playerName = name; }
    void setHealth(double h)        { health = h; }
    static void setLuck(double l)   { luck = l; }
    void setAttack(double a)        { attack = a; }
    void setCoins(int c)            { coins = c; }
};

class warrior_race : public player {
    public:
};

class intelligent_race : public player {
    public:
};

class talented_race : public player {
    public:
};


class lvl1 {
    public:

    
};

class lvl2 : public lvl1{

};

class lvl3 : public lvl1{

};

void shop(){

}

//Random Number Generator To Control Luck %
int genRandom(){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 100); 

    int randomNumber = dist(gen);
    return randomNumber;
}

int chkUserInput(string a) {
    
}

void showInstructionsOnce(){
    cout << R"(

███████╗ █████╗ ████████╗███████╗██╗    ██╗ █████╗ ██╗     ██╗  ██╗███████╗██████╗
██╔════╝██╔══██╗╚══██╔══╝██╔════╝██║    ██║██╔══██╗██║     ██║ ██╔╝██╔════╝██╔══██╗
█████╗  ███████║   ██║   █████╗  ██║ █╗ ██║███████║██║     █████╔╝ █████╗  ██████╔╝
██╔══╝  ██╔══██║   ██║   ██╔══╝  ██║███╗██║██╔══██║██║     ██╔═██╗ ██╔══╝  ██╔══██╗
██║     ██║  ██║   ██║   ███████╗╚███╔███╔╝██║  ██║███████╗██║  ██╗███████╗██║  ██║
╚═╝     ╚═╝  ╚═╝   ╚═╝   ╚══════╝ ╚══╝╚══╝ ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝

                     A GAME OF LUCK, STEPS, AND CONSEQUENCES

───────────────────────────────────────────────────────────────────────────────

You are a wanderer on an unstable path.
Each step reveals a surprise.
A blessing… or a monster.
A weapon… or your end.

Luck decides.
Courage sustains.
Fate watches.

───────────────────────────────────────────────────────────────────────────────

Press: 
[1] Start New Journey
[2] How to Play
[3] Exit Game

Choose wisely.
Every step matters.

)";

cout << "Enter your choice: ";
string answer;

while (true) {
    getline(cin, answer);
        // Check length first
        if (answer.length() != 1) {
            cout << "Invalid input. Please enter a number from 1 to 3.\n";
            continue;
        }

        // Check if it's a digit
        if (!isdigit(answer[0])) {
            cout << "Invalid input. Please enter a number from 1 to 3.\n";
            continue;
        }

        int choice = answer[0] - '0';

        // Check range
        if (choice < 1 || choice > 3) {
            cout << "Invalid input. Please enter a number from 1 to 3.\n";
            continue;
        }
    }

}

int main() {
    //Intializing playing ground without loops so we can save excution time.
    int rowsNum = 5; int columnNum = 5;
    string lvl1Ground[rowsNum][columnNum] = {
        {" ", " ", " ", " ", " "},
        {" ", " ", " ", " ", " "},
        {" ", " ", " ", " ", " "},
        {" ", " ", " ", " ", " "},
        {" ", " ", " ", " ", " "},
    };


    return 0;
}