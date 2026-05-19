// Copyright 2024 UNN
#include "../include/Automata.h"

Automata::Automata() {
    cash = 0;
    state = STATES::OFF;
    chosen_beverage = -1;
    menu = { "Tea", "Coffee", "Milk", "Hot Chocolate" };
    prices = { 20, 30, 15, 40 };
}

void Automata::on() {
    if (state == STATES::OFF) {
        state = STATES::WAIT;
        cash = 0;
        chosen_beverage = -1;
    }
}

void Automata::off() {
    if (state == STATES::WAIT) {
        state = STATES::OFF;
    }
}

void Automata::coin(int amount) {
    if (state == STATES::WAIT || state == STATES::ACCEPT) {
        cash += amount;
        state = STATES::ACCEPT;
    }
}

std::vector<std::string> Automata::getMenu() const {
    return menu;
}

STATES Automata::getState() const {
    return state;
}

void Automata::choice(int item) {
    if (state == STATES::ACCEPT) {
        if (item >= 0 && item < static_cast<int>(menu.size())) {
            chosen_beverage = item;
            state = STATES::CHECK;
        }
    }
}

bool Automata::check() {
    if (state == STATES::CHECK) {
        if (cash >= prices[chosen_beverage]) {
            return true;
        }
    }
    return false;
}

void Automata::cancel() {
    if (state == STATES::ACCEPT || state == STATES::CHECK) {
        cash = 0;
        chosen_beverage = -1;
        state = STATES::WAIT;
    }
}

void Automata::cook() {
    if (state == STATES::CHECK) {
        if (check()) {
            state = STATES::COOK;
            cash -= prices[chosen_beverage];
        }
    }
}

void Automata::finish() {
    if (state == STATES::COOK) {
        chosen_beverage = -1;
        state = STATES::WAIT;
    }
}

int Automata::getCash() const {
    return cash;
}
