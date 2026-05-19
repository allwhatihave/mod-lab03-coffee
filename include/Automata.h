#pragma once
#include <string>
#include <vector>

enum class STATES {
    OFF,
    WAIT,
    ACCEPT,
    CHECK,
    COOK
};

class Automata {
private:
    int cash;
    std::vector<std::string> menu;
    std::vector<int> prices;
    STATES state;
    int chosen_beverage;

public:
    Automata();
    void on();
    void off();
    void coin(int amount);
    std::vector<std::string> getMenu() const;
    STATES getState() const;
    void choice(int item);
    bool check();
    void cancel();
    void cook();
    void finish();
    int getCash() const;
};
