//Guess the Number Game
//Rules:
    //1. The computer randomly selects a number between 1 and 100.
    //2. The player has to guess the number.
    //3. After each guess, the computer tells the player if the guess is too high, too low, or correct.
    //4. The game continues until the player guesses the correct number or decides to quit.
    //5. The player can quit the game by entering 0.
#include <iostream>
#include <random>
#include <limits>

using namespace std;
int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 100);

    int target = dist(gen);
    int guess = 0;
    int attempts = 0;

    cout << "Guess the number (1-100). Type 0 to quit.\n";

    while (true) {
        cout << "Your guess: ";
        if (!(cin >> guess)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a valid number.\n";
            continue;
        }
        if (guess == 0) {
            cout << "Goodbye! The number was " << target << ".\n";
            break;
        }
        attempts++;
        if (guess == target) {
            cout << "Correct! You guessed in " << attempts << " attempts.\n";
            break;
        } 
        else if (guess < target) cout << "Higher.\n";
        else cout << "Lower.\n";
    }
    return 0;
}