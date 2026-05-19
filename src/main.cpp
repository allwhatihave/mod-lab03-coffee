// Copyright 2026 UNN
#include <iostream>
#include "../include/Automata.h"

int main() {
    Automata machine;

    machine.on();
    machine.coin(20);
    machine.coin(15);
    machine.choice(1);

    if (machine.check()) {
        machine.cook();
        machine.finish();
    } else {
        machine.cancel();
    }

    machine.off();

    return 0;
}
