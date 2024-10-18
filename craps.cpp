#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


int playerBalance = 100;
int betAmount = 0;
int targetPoint = 0;

// Simulate the roll of two dice
int rollDice() {
    int die1 = rand() % 6 + 1;
    int die2 = rand() % 6 + 1;
    int sum = die1 + die2;
    cout << "Player rolled " << die1 << " + " << die2 << " = " << sum << "\n";
    return sum;
}

// When the player wins
void playerWins() {
    cout << "Player wins\n\nYou won " << betAmount 
         << " credits. Your new balance is " << (playerBalance + betAmount * 2) 
         << " credits\n\n";
        
    playerBalance += betAmount * 2;  // Add winnings (double the wager)
    betAmount = 0;
    targetPoint = 0;
}

// When the player loses
void playerLoses() {
    cout << "Player loses\n\nYou lost " << betAmount 
         << " credits. Your new balance is " << playerBalance << " credits\n\n";
    betAmount = 0;
    targetPoint = 0;
}

//game
int playGame() {
    cout << "You wagered " << betAmount << " credits.\n";
    int currentThrow = rollDice();
    
    // Check if the player wins or loses on the first roll
    if (currentThrow == 7 || currentThrow == 11) {
        playerWins();
        return 0;
    } else if (currentThrow == 2 || currentThrow == 3 || currentThrow == 12) {
        playerLoses();
        return 0;
    } else {
        targetPoint = currentThrow;
        cout << "Your point is " << targetPoint << "\n";
    }
    
    // Continue rolling until the player rolls the point or 7
    bool finished = false;
    do {
        currentThrow = rollDice();
        if (currentThrow == targetPoint) {
            playerWins();
            return 0;
        } else if (currentThrow == 7) {
            playerLoses();
            return 0;
        }
    } while (!finished);
    
    return 0;
}

// Main function
int main() {
    srand(time(NULL)); // Seed for random number generation
    char ans;
    bool done = false;
    
    while (!done) {
        // Prompt for wager amount
        do {
            cout << "You have " << playerBalance << " credits. How much credits will you wager? ";
            cin >> betAmount;
            if (betAmount <= 0 || betAmount > playerBalance) {
                cout << "You cannot wager that.\n\n";
            }
        } while (betAmount <= 0 || betAmount > playerBalance);

        // Deduct wager from player's balance
        playerBalance -= betAmount;

        // Play the game
        playGame();

        // Check if the player is out of credits
        if (playerBalance == 0) {
            cout << "You are out of credits - game over!\n";
            break;
        }

        // Ask if the player wants to play again
        cout << "Play again (y/n)? ";
        cin >> ans;

        if (ans == 'n' || ans == 'N') {
            done = true; // End the loop, the game is over
        } else if (ans == 'y' || ans == 'Y') {
            done = false;  // Continue playing (loop will keep running)
        } else {
            // If the input is not 'y' or 'n', continue prompting the player
            cout << "Invalid input. Please enter 'y' to play again or 'n' to quit.\n";
        }
    }
    
    return 0;
}
