#pragma once
#include <iostream>
#include "Dice.h"
using namespace std;

class Dices {
    public:
    Dice dice_list [5];
    int throws;

    public:
    Dices();
    void createDices();
    void releaseDices();
    void throwDices();
    string showDices();
};