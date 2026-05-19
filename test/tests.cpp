// Copyright 2026 UNN
#include <gtest/gtest.h>
#include "../include/Automata.h"

TEST(AutomataTest, InitialStateIsOff) {
    Automata a;
    EXPECT_EQ(a.getState(), STATES::OFF);
}

TEST(AutomataTest, TurnOnChangesStateToWait) {
    Automata a;
    a.on();
    EXPECT_EQ(a.getState(), STATES::WAIT);
}

TEST(AutomataTest, TurnOffFromWaitChangesStateToOff) {
    Automata a;
    a.on();
    a.off();
    EXPECT_EQ(a.getState(), STATES::OFF);
}

TEST(AutomataTest, CoinInWaitChangesStateToAccept) {
    Automata a;
    a.on();
    a.coin(10);
    EXPECT_EQ(a.getState(), STATES::ACCEPT);
    EXPECT_EQ(a.getCash(), 10);
}

TEST(AutomataTest, MultipleCoinsAccumulate) {
    Automata a;
    a.on();
    a.coin(10);
    a.coin(20);
    EXPECT_EQ(a.getCash(), 30);
}

TEST(AutomataTest, ChoiceChangesStateToCheck) {
    Automata a;
    a.on();
    a.coin(50);
    a.choice(1);
    EXPECT_EQ(a.getState(), STATES::CHECK);
}

TEST(AutomataTest, CheckReturnsTrueIfEnoughCash) {
    Automata a;
    a.on();
    a.coin(100);
    a.choice(0);
    EXPECT_TRUE(a.check());
}

TEST(AutomataTest, CheckReturnsFalseIfNotEnoughCash) {
    Automata a;
    a.on();
    a.coin(5);
    a.choice(0);
    EXPECT_FALSE(a.check());
}

TEST(AutomataTest, CancelFromAcceptReturnsToWait) {
    Automata a;
    a.on();
    a.coin(50);
    a.cancel();
    EXPECT_EQ(a.getState(), STATES::WAIT);
    EXPECT_EQ(a.getCash(), 0);
}

TEST(AutomataTest, CookChangesStateAndDeductsCash) {
    Automata a;
    a.on();
    a.coin(30);
    a.choice(1);
    a.cook();
    EXPECT_EQ(a.getState(), STATES::COOK);
    EXPECT_EQ(a.getCash(), 0);
}

TEST(AutomataTest, FinishChangesStateToWait) {
    Automata a;
    a.on();
    a.coin(30);
    a.choice(1);
    a.cook();
    a.finish();
    EXPECT_EQ(a.getState(), STATES::WAIT);
}
