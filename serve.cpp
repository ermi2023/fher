#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to generate a random number within a range
int getRandomNumber(int min, int max) {
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

// Function to simulate a battle encounter
void battleEncounter() {
    cout << "You encounter a fierce enemy!" << endl;

    // Simulate battle
    int playerHealth = 100;
    int enemyHealth = 100;

    while (playerHealth > 0 && enemyHealth > 0) {
        // Player attacks
        int playerAttack = getRandomNumber(10, 20);
        enemyHealth -= playerAttack;
        cout << "You attack the enemy causing " << playerAttack << " damage. Enemy's health: " << enemyHealth << endl;

        if (enemyHealth <= 0) {
            cout << "You defeated the enemy!" << endl;
            break;
        }

        // Enemy attacks
        int enemyAttack = getRandomNumber(5, 15);
        playerHealth -= enemyAttack;
        cout << "The enemy attacks you causing " << enemyAttack << " damage. Your health: " << playerHealth << endl;

        if (playerHealth <= 0) {
            cout << "You were defeated in battle!" << endl;
            break;
        }
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed random number generator

    cout << "*** Welcome to Ermias's Adventure ***" << endl;
    cout << "You find yourself in a mysterious land. Your goal is to reach the final destination." << endl;

    char choice;
    do {
        cout << endl;
        cout << "What do you want to do?" << endl;
        cout << "a) Continue journey" << endl;
        cout << "b) Rest and regain strength" << endl;
        cout << "c) Quit" << endl;
        cout << "Your choice: ";
        cin >> choice;

        switch (choice) {
            case 'a':
                cout << "You continue your journey." << endl;
                battleEncounter(); // Simulate a battle encounter
                break;
            case 'b':
                cout << "You rest and regain strength." << endl;
                // Increase player's health or perform other actions to regain strength
                break;
            case 'c':
                cout << "Thank you for playing Ermias's Adventure! Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 'c');

    return 0;
}