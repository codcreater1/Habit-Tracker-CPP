#ifndef HABIT_H
#define HABIT_H

#include <string>
#include <vector>

struct Habit {
    std::string name;
    int progress;
    int goal;
};

class HabitTracker {
private:
    std::vector<Habit> habits;
    std::string dataFile;

    void loadHabits();
    void saveHabits();

public:
    HabitTracker(const std::string &filename);
    void addHabit(const std::string &name, int goal);
    void logProgress(const std::string &name, int amount);
    void showHabits() const;
    void showStatistics() const;
};

#endif
