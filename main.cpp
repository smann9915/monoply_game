#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

static const int MAX_SPACES = 40;

// -------------------------------
// Data class (NOT a struct)
// -------------------------------
class MonopolySpace {
public:
    string propertyName;
    string propertyColor;
    int value;
    int rent;

    MonopolySpace() {
        propertyName = "Template";
        propertyColor = "Brown";
        value = 100;
        rent = 10;
    }

    MonopolySpace(string propertyName, string propertyColor, int value, int rent) {
        this->propertyName = propertyName;
        this->propertyColor = propertyColor;
        this->value = value;
        this->rent = rent;
    }

    //Compares spaces by there propertyName
    bool isEqual(MonopolySpace other) {
        return this->propertyName == other.propertyName;
    }

    void print() {
        cout << "Name: " << propertyName << ", Color " << propertyColor <<
            ", Value: $" << value << ", Rent " << rent << endl;
    }
};

// -------------------------------
// Template Node class (NOT a struct)
// -------------------------------
template <typename T>
class Node {
public:
    T data;
    Node<T>* nextNode;

    Node(T value) {
        data = value;
        nextNode = nullptr;
    }
};

// -------------------------------
// Template Circular Linked List class
// Spring 2026 version: traversable board
// -------------------------------
template <typename T>
class CircularLinkedList {
private:
    Node<T>* headNode;
    Node<T>* tailNode;

    // player cursor for traversal-based gameplay
    Node<T>* playerNode;

    int nodeCount;
    int passGoCount;

public:
    CircularLinkedList() {
        headNode = nullptr;
        tailNode = nullptr;
        playerNode = nullptr;

        nodeCount = 0;
        passGoCount = 0;
    }

    // -------------------------------
    // Core A: Add a Space with Capacity Enforcement
    // -------------------------------
    bool addSpace(T value) {
        if (nodeCount == MAX_SPACES) {
            return false;
        }
        Node<T>* newNode = new Node<T>(value);
        if (headNode == nullptr) {
            headNode = newNode;
            tailNode = newNode;
            playerNode = newNode;

            headNode->nextNode = headNode;
        }
        else {
            tailNode->nextNode = newNode;
            tailNode = newNode;
            tailNode->nextNode = headNode;
        }
        nodeCount++;
        return true;
    }

    // -------------------------------
    // Core B: Add Multiple Spaces at Once
    // -------------------------------
    int addMany(vector<T> values) {
        for (int i = 0; i < values.size(); i++) {
            bool check = addSpace(values[i]);
            if (!check) {
                return i;
            }
        }

        return values.size();
    }

    // -------------------------------
    // Core C: Traversal-Based Player Movement
    // -------------------------------
    void movePlayer(int steps) {
        if (headNode == nullptr) {
            cout << "There is no board currently" << endl;
            return;
        }

        for (int i = 0; i < steps; i++) {
            playerNode = playerNode->nextNode;
            if (headNode == playerNode) {
                cout << "Player has passed Go";
                passGoCount++;
            }
        }
    }

    int getPassGoCount() {
        return passGoCount;
    }

    // -------------------------------
    // Core D: Controlled Board Display
    // -------------------------------
    void printFromPlayer(int count) {
        if (headNode == nullptr) return;
        Node<T> *temp = playerNode;

        for (int i = 0; i < count; i++) {
            temp->data.print();
            temp = temp->nextNode;
        }
    }

    // Print full board once (one full cycle)
    void printBoardOnce() {
        if (headNode == nullptr) {
            return;
        }

        Node<T> *temp = headNode;

        while (true) {
            temp->data.print();
            temp = temp->nextNode;

            if (temp == headNode) {
                break;
            }
        }
    }

    // -------------------------------
    // Advanced Option B (Level 2): Mirror the Board (Circular Reversal)
    // -------------------------------
    void mirrorBoard() {
        if (headNode == nullptr) {
            return;
        }
        Node<T> *prev = tailNode;
        Node<T> *current = headNode;
        Node<T> *next = current->nextNode;

        //Reverses the linked list
        while (true){
            next = current->nextNode;
            current->nextNode = prev;

            prev = current;
            current = next;

            if (current == headNode) {
                break;
            }
        }

        //Flip what nodes are the head and what node is the tail
        tailNode = headNode;
        headNode = headNode->nextNode;
    }

    // -------------------------------
    // Edge-case helper: countSpaces O(n)
    // -------------------------------
    int countSpaces() {
        if (headNode == nullptr) {
            return 0;
        }

        int count = 0;
        Node<T> *temp = headNode;

        while (true) {
            count++;
            temp = temp->nextNode;

            if (temp == headNode) {
                break;
            }
        }

        return count;
    }

    // -------------------------------
    // Cleanup
    // -------------------------------
    void clear() {
        //Disconnect the Circular Structure of the List
        tailNode->nextNode = nullptr;
        Node<T> *temp = headNode;

        //Destroys the Linked list as if it wasn't circular
        while (temp != nullptr) {
            temp = headNode->nextNode;
            delete headNode;
            headNode = temp;
        }
    }
};

// -------------------------------
// Main: playable loop demo
// -------------------------------
int rollDice2to12() {
    return (rand() % 6 + 1) + (rand() % 6 + 1);
}

vector<MonopolySpace> makeBoardVector() {
    vector<MonopolySpace> spaces;
    spaces.push_back(MonopolySpace("GO", "None", 0, 0));
    spaces.push_back(MonopolySpace("Mediterranean Avenue", "Brown", 100, 10));
    spaces.push_back(MonopolySpace("Commmunity Chest", "None", 0, 0));
    spaces.push_back(MonopolySpace("Old Kent Road", "Brown", 100, 10));
    spaces.push_back(MonopolySpace("Income Tax", "None", 0, 0));

    spaces.push_back(MonopolySpace("Reading Railroad", "None", 0, 0));
    spaces.push_back(MonopolySpace("Oriental Avenue", "Light Blue", 200, 20));
    spaces.push_back(MonopolySpace("Chance", "None", 0, 0));
    spaces.push_back(MonopolySpace("Vermont Avenue", "Light Blue", 200, 20));
    spaces.push_back(MonopolySpace("Conneticut Avenue", "Light Blue", 200, 20));

    spaces.push_back(MonopolySpace("Jail", "None", 0, 0));
    spaces.push_back(MonopolySpace("ST. Charles Place", "Purple", 300, 30));
    spaces.push_back(MonopolySpace("Electrical Company", "None", 0, 0));
    spaces.push_back(MonopolySpace("States Avenue", "Purple", 300, 30));
    spaces.push_back(MonopolySpace("Virginia Avenue", "Purple", 300, 30));

    spaces.push_back(MonopolySpace("Pennsylvania Railroad", "None", 0, 0));
    spaces.push_back(MonopolySpace("ST. James Place Avenue", "Orange", 400, 40));
    spaces.push_back(MonopolySpace("Commmunity Chest", "None", 0, 0));
    spaces.push_back(MonopolySpace("Tennesse Avenue", "Orange", 400, 40));
    spaces.push_back(MonopolySpace("New York Avenue", "Orange", 400, 40));

    spaces.push_back(MonopolySpace("Free Parking", "None", 0, 0));
    spaces.push_back(MonopolySpace("Kentucky Avenue", "Red", 500, 50));
    spaces.push_back(MonopolySpace("Chance", "None", 0, 0));
    spaces.push_back(MonopolySpace("Indiana Avenue", "Red", 500, 50));
    spaces.push_back(MonopolySpace("Illinois Avenue", "Red", 500, 50));
    spaces.push_back(MonopolySpace("B. & O. Railroad", "None", 0, 0));

    spaces.push_back(MonopolySpace("Atlantic Avenue", "Yellow", 600, 60));
    spaces.push_back(MonopolySpace("Verton Avenue", "Yellow", 600, 60));
    spaces.push_back(MonopolySpace("Water Works", "None", 0, 0));
    spaces.push_back(MonopolySpace("Marvin Gardens", "Yellow", 600, 60));
    spaces.push_back(MonopolySpace("Go to Jail", "None", 0, 0));

    spaces.push_back(MonopolySpace("Pacific Avenue", "Green", 700, 70));
    spaces.push_back(MonopolySpace("North Carolina Avenue", "Green", 700, 70));
    spaces.push_back(MonopolySpace("Community Chest", "None", 0, 0));
    spaces.push_back(MonopolySpace("Pennsylvania Avenue", "Green", 700, 70));
    spaces.push_back(MonopolySpace("Short Line", "None", 0, 0));
    spaces.push_back(MonopolySpace("Chance", "None", 0, 0));

    spaces.push_back(MonopolySpace("Park Place", "Blue", 800, 80));
    spaces.push_back(MonopolySpace("Luxury Tax", "None", 0, 0));
    spaces.push_back(MonopolySpace("Boardwalk", "Blue", 800, 80));

    return spaces;
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    CircularLinkedList<MonopolySpace> board;

    // -------------------------------
    // Board Construction Phase
    // -------------------------------

    vector<MonopolySpace> spaces = makeBoardVector();
    board.addMany(spaces);

    // -------------------------------
    // Playable Traversal Loop
    // -------------------------------
    for (int turn = 1; turn <= 10; turn++) {
        int roll = rollDice2to12();
        cout << "\nTurn " << turn << " | Rolled: " << roll << endl;

        board.movePlayer(roll);

        cout << "Board view from player (next 5 spaces):" << endl;
        board.printFromPlayer(5);

        cout << "Times passed GO so far: " << board.getPassGoCount() << endl;
    }

    //Mirrors the board and prints the mirrored board
    cout << endl << "Mirrored Board:" << endl;
    board.mirrorBoard();
    board.printBoardOnce();

    //Destroy the Board
    board.clear();

    return 0;
}
