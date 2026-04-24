#include <iostream>
#include <memory>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

/*This is made just to see how the design should look like & play around with it,
 *none of this code is going to be in production.
 */
struct Stats {
    int health;
    int defense;
    int attack;
    int sanity;
    int soulEnergy;
};


class ISoul {
public:
    virtual Stats getBaseStats() = 0;
    virtual float getResistance(string damageType) = 0;
    virtual string getName() = 0;
};


class WarriorSoul : public ISoul {
public:
    Stats getBaseStats() override {
        return {120, 80, 70, 50, 50};
    }

    float getResistance(string damageType) override {
        if (damageType == "health") return 0.5f;
        return 1.0f;
    }

    string getName() override { return "Warrior"; }
};

class TalentedSoul : public ISoul {
public:
    Stats getBaseStats() override {
        return {80, 50, 100, 70, 60};
    }

    float getResistance(string damageType) override {
        if (damageType == "sanity") return 0.6f;
        return 1.0f;
    }

    string getName() override { return "Talented"; }
};

class ExplorerSoul : public ISoul {
public:
    Stats getBaseStats() override {
        return {90, 60, 60, 80, 90};
    }

    float getResistance(string damageType) override {
        if (damageType == "soul") return 0.5f;
        return 1.0f;
    }

    string getName() override { return "Explorer"; }
};


class Player {
private:
    string name;
    unique_ptr<ISoul> soul;
    Stats stats;

public:
    Player(string name, unique_ptr<ISoul> soul)
        : name(name), soul(move(soul)) {
        stats = this->soul->getBaseStats();
    }

    void takeDamage(string type, int amount) {
        float resistance = soul->getResistance(type);
        int finalDamage = (int)(amount * resistance);

        if (type == "health") stats.health -= finalDamage;
        else if (type == "sanity") stats.sanity -= finalDamage;
        else if (type == "soul") stats.soulEnergy -= finalDamage;

        cout << "Damage taken: " << finalDamage << " (" << type << ")\n";
    }

    void heal(string type, int amount) {
        if (type == "health") stats.health += amount;
        else if (type == "sanity") stats.sanity += amount;
        else if (type == "soul") stats.soulEnergy += amount;

        cout << "Healed: " << amount << " (" << type << ")\n";
    }

    bool isAlive() {
        return stats.health > 0 && stats.sanity > 0 && stats.soulEnergy > 0;
    }

    void printStats() {
        cout << "Health: " << stats.health
             << " | Sanity: " << stats.sanity
             << " | Soul: " << stats.soulEnergy << endl;
    }
};


class Event {
public:
    virtual void trigger(Player& player) = 0;
    virtual ~Event() {}
};


class PotionEvent : public Event {
public:
    void trigger(Player& player) override {
        int type = rand() % 3;
        if (type == 0) player.heal("health", 20);
        else if (type == 1) player.heal("sanity", 20);
        else player.heal("soul", 20);
    }
};

class MonsterEvent : public Event {
public:
    void trigger(Player& player) override {
        int type = rand() % 3;
        if (type == 0) player.takeDamage("health", 30);
        else if (type == 1) player.takeDamage("sanity", 30);
        else player.takeDamage("soul", 30);
    }
};

class EventFactory {
public:
    static unique_ptr<Event> createEvent() {
        int r = rand() % 2;
        if (r == 0) return make_unique<PotionEvent>();
        return make_unique<MonsterEvent>();
    }
};

class Game {
private:
    Player player;

public:
    Game(Player p) : player(move(p)) {}

    void run() {
        cout << "Game Started!\n";

        for (int col = 0; col < 10; col++) {
            cout << "\nEntering column " << col + 1 << endl;

            auto event = EventFactory::createEvent();
            event->trigger(player);

            player.printStats();

            if (!player.isAlive()) {
                cout << "Game Over!\n";
                return;
            }
        }

        cout << "You reached the end. You win!\n";
    }
};

int main() {
    srand(time(0));

    string name;
    int choice;

    cout << "Enter your name: ";
    cin >> name;

    cout << "Choose soul:\n1. Warrior\n2. Talented\n3. Explorer\n";
    cin >> choice;

    unique_ptr<ISoul> soul;

    if (choice == 1) soul = make_unique<WarriorSoul>();
    else if (choice == 2) soul = make_unique<TalentedSoul>();
    else soul = make_unique<ExplorerSoul>();

    Player player(name, move(soul));
    Game game(move(player));

    game.run();

    return 0;
}