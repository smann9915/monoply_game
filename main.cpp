#include <iostream>
#include <random>
#include <string>
#include "LinkedList.cpp"

using namespace std;

LinkedList<Data> *createBoard() {
    //Creates a LL of 40 spaces that contain data
    //pertaining to what space they are on the board
    Data *a1 = new Data(1);
    LinkedList<Data> *board = new LinkedList<Data>(a1);

    for (int i = 2; i <= 40; i++) {
        board->append(new Data(i));
    }

    return board;
}

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
    LinkedList<Data> *board = createBoard();

    board->printList();

    //temporary gameplay loop
    for (int i = 1; i <= 12; i++) {
        playTurn();
    }
}