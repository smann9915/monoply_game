#include <iostream>
#include <random>
#include <string>

using namespace std;

int rollDice() {
    int dice1 =  rand() % 6 + 1;
    int dice2 = rand() % 6 + 1;

    return dice1 + dice2;
}

void playTurn() {
    //Rolls the dice
    string answer = "";
    cout << "Enter anything to roll the dice: ";
    cin >> answer;
    cout << rollDice() << endl;
}

int main() {
    //temporary gameplay loop
    for (int i = 1; i <= 12; i++) {
        playTurn();
    }
}