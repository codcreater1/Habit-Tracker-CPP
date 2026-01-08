#include "habit.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    HabitTracker tracker("data/habits.csv");
    int choice;

    do {
        cout << "\n=== Habit Tracker ===\n";
        cout << "1. Add Habit\n";
        cout << "2. Log Progress\n";
        cout << "3. Show Habits\n";
        cout << "4. Show Statistics\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            string name;
            int goal;
            cout << "Enter habit name: ";
            getline(cin, name);
            cout << "Enter goal: ";
            cin >> goal;
            tracker.addHabit(name, goal);
        } else if (choice == 2) {
            string name;
            int amount;
            cout << "Enter habit name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter amount to log: ";
            cin >> amount;
            tracker.logProgress(name, amount);
        } else if (choice == 3) {
            tracker.showHabits();
        } else if (choice == 4) {
            tracker.showStatistics();
        } else if (choice != 0) {
            cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    cout << "Goodbye!\n";
    return 0;
}
