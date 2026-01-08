#include "habit.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

HabitTracker::HabitTracker(const string &filename) {
    dataFile = filename;
    loadHabits();
}

void HabitTracker::loadHabits() {
    habits.clear();
    ifstream file(dataFile);
    if (!file.is_open()) return;

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string name;
        int progress, goal;
        getline(ss, name, ',');
        ss >> progress;
        ss.ignore();
        ss >> goal;
        habits.push_back({name, progress, goal});
    }
    file.close();
}

void HabitTracker::saveHabits() {
    ofstream file(dataFile);
    for (auto &h : habits) {
        file << h.name << "," << h.progress << "," << h.goal << "\n";
    }
    file.close();
}

void HabitTracker::addHabit(const string &name, int goal) {
    habits.push_back({name, 0, goal});
    saveHabits();
    cout << "Habit \"" << name << "\" added with goal " << goal << "!\n";
}

void HabitTracker::logProgress(const string &name, int amount) {
    for (auto &h : habits) {
        if (h.name == name) {
            h.progress += amount;
            if (h.progress > h.goal) h.progress = h.goal;
            cout << "Logged " << amount << " for " << name << ". Total: " << h.progress << "/" << h.goal << "\n";
            saveHabits();
            return;
        }
    }
    cout << "Habit not found!\n";
}

void HabitTracker::showHabits() const {
    cout << "\nCurrent Habits:\n";
    cout << left << setw(20) << "Habit" << setw(10) << "Progress" << setw(10) << "Goal" << endl;
    cout << "--------------------------------------\n";
    for (auto &h : habits) {
        cout << left << setw(20) << h.name
             << setw(10) << h.progress
             << setw(10) << h.goal << endl;
    }
}

void HabitTracker::showStatistics() const {
    cout << "\nStatistics:\n";
    for (auto &h : habits) {
        double percent = ((double)h.progress / h.goal) * 100;
        cout << h.name << ": " << h.progress << "/" << h.goal << " (" << fixed << setprecision(1) << percent << "%)\n";
    }
}
