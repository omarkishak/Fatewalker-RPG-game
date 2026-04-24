#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <random>
#include <limits>
#include <map>

using namespace std;

class

class player {
public:
    string player_name;
    string soul_type;
    double health;
    double resistance;
    double attack_value;
    static double luck;
    map<string, int> inventory;


    player(string name) {
        player_name = name;
        soul_type =
        health = 100;
        luck = 100;
        attack_value = 20;
        inventory = {
            {"Coins", 0},
            {"Blood Sword", 0},
            {"Magic Sword", 0},
            {"Twisted Sword", 0},
            {"Health Potion", 0},
            {"Stringth Potion", 0},
            {"Resistance Potion", 0}
        };
    }

    //Getters
    string getPlayerName()          { return player_name; }
    double getHealth()              { return health; }
    static double getLuck()         { return luck; }
    double getAttack()              { return attack_value; }
    map<string, int> getInventory() {return inventory;}

    //Setters
    void setPlayerName(string name) { player_name = name; }
    void setHealth(double h)        { health = h; }
    static void setLuck(double l)   { luck = l; }
    void setAttack(double a)        { attack_value = a; }
    void setItem(const string& name, int value) {
        if (inventory.find(name) != inventory.end()) {
            inventory[name] = value;
        } else {
            cout << "Item does not exist!\n";
        }
    }
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

int getIntInput() {
    int value;

    while (true) {
        cin >> value;

        if (cin.fail()) {
            cin.clear(); // fix broken state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // remove bad input
            cout << "Invalid input. Please enter a number: ";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clean leftover
            return value;
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