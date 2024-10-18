# craps.cpp

Stephen Omitoki

Overview:
This program simulates the game of Craps with wagering features. The player starts with 100 credits and can place bets on each game round. The game involves rolling two dice, and the outcome determines whether the player wins or loses. The player can keep playing until they either run out of credits or choose to quit.

How It Works:
The player places a bet before each round.
The dice are rolled, and the sum is calculated.
If the sum is 7 or 11 on the first roll, the player wins.
If the sum is 2, 3, or 12 on the first roll, the player loses.
If any other number is rolled, that number becomes the " target point." The player continues rolling until they either roll the target point again (win) or roll a 7 (lose).
The game keeps track of the player's balance, updating it based on the result of each round.


Key Variables:
playerBalance: Tracks the player's current credits (starts at 100).
betAmount: The amount wagered on each game.
targetPoint: The number the player must roll again to win if they don’t win or lose on the first roll.

Functions:
rollDice: Simulates rolling two dice and returns the sum.
playerWins: Updates the player's balance and announces a win.
playerLoses: Announces a loss and keeps track of the remaining balance.
playGame: The main game logic that rolls the dice and checks for wins or losses.

Running the Program:
The player will be prompted to place a wager.
The dice will be rolled, and the result will be displayed.
Depending on the result, the game will continue or end the round.
The player can choose to play again or quit.
The game ends automatically if the player's balance reaches zero.

Requirements:
C++ compiler.
