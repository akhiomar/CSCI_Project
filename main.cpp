#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0)); // Creates the random number generator

    char playAgain = 'y';

    while (playAgain == 'y') {
        // Gives player one a starting number
        int playerHand = 0;

        // Deals initial cards which is limited to 10
        playerHand += (rand() % 10) + 1;  // First card 1-10


        // Game loop
        bool playerTurn = true;
        while (playerTurn) {
            // Player's turn
            cout << "Your hand: " << playerHand << endl;
            if (playerHand < 21) {
                char choice;
                cout << "Hit or Stand (h/s)? ";
                cin >> choice;
                if (choice == 'h') {
                    playerHand += (rand() % 10) + 1;  // New card 1-10
                    if (playerHand > 21) {
                        cout << "You Bust!" << endl;
                        playerTurn = false;
                    }
                } else {
                    playerTurn = false;
                }
            } else {
                playerTurn = false;
            }
        }

        // Determines the winner
        cout << "Final Hand:" << endl;
        cout << "You: " << playerHand << endl;

        if (playerHand > 21) {
            cout << "You Bust! You lose!" << endl;
        } else {
            cout << "You win!" << endl;
        }

        cout << "Play again? (y/n): ";
        cin >> playAgain;
    }

    return 0;

}