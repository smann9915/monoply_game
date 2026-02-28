#include <iostream>
#include <random>
#include <string>
#include "LinkedList.cpp"

using namespace std;

struct Player {
    Node<Data> *position;
    int timesPassedGo;
};

//Global Variables
Player player;
LinkedList<Data> *board;

void setUpGame() {
    //Creates a LL of 40 spaces that contain data
    //pertaining to what space they are on the board
    Data *a1 = new Data(1);
    board = new LinkedList<Data>(a1);

    for (int i = 2; i <= 40; i++) {
        board->append(new Data(i));
    }

    player.position = board->getHead();
    player.timesPassedGo = 0;
}

int rollDice() {
    int dice1 =  rand() % 6 + 1;
    int dice2 = rand() % 6 + 1;

    return dice1 + dice2;
}

void movePlayer() {
    int spacesToMove = rollDice();

    cout << "You rolled a " << spacesToMove << endl;

    for (int i = 0; i < spacesToMove; i++) {
        player.position = player.position->next;
        if (player.position->value->value == 1) {
            cout << "Player has passed Go";
            player.timesPassedGo++;
        }
    }

    cout << player.position->value->value << endl;
}

void playTurn() {
    //Rolls the dice
    string answer = "";
    cout << "Enter anything to roll the dice: ";
    cin >> answer;

    movePlayer();
}

int main() {
    setUpGame();

    board->printList();

    //temporary gameplay loop
    for (int i = 1; i <= 12; i++) {
        playTurn();
    }
}