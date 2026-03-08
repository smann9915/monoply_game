# CS210 Programming Assignment
## Monopoly Board Simulator (Spring 2026)

## How to Build and Run
### Build Using:
- `g++ -std=c++17 main.cpp -o monopoly_board`

### Run Using:
- `./monopoly_board`

---

### Data Structures Used
#### Circular Linked List: 
- This Data Structure connects nodes that are not next to each other in memory.
- To make it circular we always have the last node point to the first
- Used to allow us to track out player's position and loop around the Board

---

### All Funnctions 
#### MonoplySpace:
- bool isEqual(MonopolySpace other): Compares this objects monopoly spaces name to the argument monopoly spaces name and returns the outcome.
#### CircularLinkedList
- bool addSpace(T value): Takes in some T data make a node out of it and appends it to the end of the list while keeping the list circular. It returns whether it succeeding adding the space or not.
- int addMany(vector<T> values): This function loops over the given vector attempting to add each element to the list and if adding the space fails the loop stops. This function returns the amount of spaces added to the list.
- void movePlayer(int steps): This function moves the playerNode pointer one node up the list per the amount of steps given as an argument.
- int getPassGoCount(): Returns passGoCount.
- void printFromPlayer(int count): This method prints from the playerNode pointer and for the amount of count moves up the list printing one space per count.
- void printBoardOnce(): This function prints starting at the headNode and prints the tailNode last, meaning it prints the entire board once.
- void mirrorBoard(): This function mirrors the board, switching the tail and the head node. It also makes every node's next pointer point to the node that was previously before it.
- int countSpaces(): This function returns the length of the list by traversing from the head to the tail of the list.
- void clear(): Destroys the board by safely deleting all nodes
#### Other
- int rollDice2to12(): Returns the sum of simulating rolling 2 dice.
- vector<MonopolySpace> makeBoardVector(): Manually creates all the Spaces and returns them in the form of a vector
---
### How it Works
#### Traversal Logic
- We track the player's posititon by creating a playerNode pointer and moving that pointer up the list one node at a time to simulate moving real a monopoly piece up a board.
#### Limits:
- The board will never be larger than the Max_Spaces, default max is 40 spaces

---