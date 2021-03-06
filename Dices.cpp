#include "Dices.h"
#include <iostream>
#include <sstream>
#include <string>  
using namespace std;

//Initializing Dices class to create an empty Dice class array for your dices
Dices :: Dices() {
    Dice dice_list [5] = {};
    int throws = 0; //Why does this not work ?
};

//Generates dices to dice_list array
void Dices::createDices(){
    for (int i = 0; i < 5; i++){
        Dice dice(i);
        dice_list[i] = dice;
    }
    //I am not sure why I have to initialize throws like this, but at least it works...
    throws = 0;
};

//Releases all dices to make them free for rerolling, resets throws counter
void Dices::releaseDices(){
    for (int i = 0; i < 5; i++){
        dice_list[i].releaseHold(); 
    }
    throws = 0;
};

//Rolls dices -> new random value to Dice.result. Adds one throw to counter
//throwDice() checks if Dice object has value hold = 0 -> roll, hold = 1 -> no rolling
void Dices::throwDices(){
    for (int j = 0; j < 5; j++){
        dice_list[j].throwDice();
    }
    throws += 1;
};

//Generates text where dice size and results are shown -> return text
void Dices::showDices(){
    string text ="";
    for (int i = 0; i<5 ;i++){
        text +="(" + to_string(i+1) + ") " + dice_list[i].name + " = " + to_string(dice_list[i].getResult());
        if (dice_list[i].hold == 1)
            text += "    **HOLD**";
        text += "\n";
    }
    cout << "Throw: " << throws << endl << "---Dice throw results---" << endl << text << "---Dice throw results---" << endl << endl;
};

void Dices::holdDice(int hold){
        //hold = 0 -> changeHold ALL
        if (hold == 0){
            for (int i=0; i<5; i++){
                dice_list[i].changeHold();
            }
        }
        else if (hold < 0 || hold > 5){
            cout << "****Invalid value****" << endl << "Press any key";
            cin.get();
        }

        else
            dice_list[hold-1].changeHold();        //hold = 1-5 -> changeHold a dice 
};

Dices::~Dices(){};