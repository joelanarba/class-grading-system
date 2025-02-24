#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <algorithm>

using namespace std;

const int maxStudents = 10;
const int maxTests = 5;

struct Student {
    string name;
    int testScores[maxTests] = {0};
    double average = 0.0;
    char grade = ' ';
};

// Clears input buffer
void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Validates integer input within a range
int getValidatedInt(string prompt, int min, int max) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail() || cin.peek() != '\n' || value < min || value > max) {
            cout << "Invalid input! Enter a whole number between " << min << " and " << max << ".\n";
            clearInputBuffer();
        } else {
            clearInputBuffer();
            return value;
        }
    }
}

// Validates that a name contains only allowed characters
bool isValidName(const string& name) {
    for (char c : name) {
        if (!isalpha(c) && c != ' ' && c != '-' && c != '\'' && c != '.') {
            return false;
        }
    }
    return !name.empty();
}

// Function to input student data
void inputStudentData(Student students[], int &currentStudentCount, int &numTests) {
    if (currentStudentCount >= maxStudents) {
        cout << "Maximum number of students reached!\n";
        return;
    }

    int numStudents = getValidatedInt("Enter the number of students (max 10): ", 1, maxStudents - currentStudentCount);
    
    if (currentStudentCount == 0) {
        numTests = getValidatedInt("Enter the number of tests per student (max 5): ", 1, maxTests);
    }

    for (int i = 0; i < numStudents; i++) {
        string name;
        bool validName;
        do {
            cout << "Enter name of student #" << (currentStudentCount + 1) << ": ";
            getline(cin, name);
            validName = isValidName(name);
            if (!validName) {
                cout << "Invalid name! Only letters, spaces, hyphens, apostrophes, and periods are allowed. Try again.\n";
            }
        } while (!validName);

        students[currentStudentCount].name = name;
        for (int j = 0; j < numTests; j++) {
            students[currentStudentCount].testScores[j] = getValidatedInt("Enter test #" + to_string(j + 1) + " score (0 to 100): ", 0, 100);
        }
        currentStudentCount++;
    }
    cout << "Students' names and test scores recorded successfully!\n";
}

// Function to assign grades based on average score
char getGrade(double avg) {
    if (avg >= 90) return 'A';
    if (avg >= 80) return 'B';
    if (avg >= 70) return 'C';
    if (avg >= 60) return 'D';
    return 'F';
}

// Function to calculate averages and assign grades
void calculateAveragesAndGrades(Student students[], int currentStudentCount, int numTests, bool &averagesCalculated) {
    if (currentStudentCount == 0) {
        cout << "No students found! Please input student data first.\n";
        return;
    }

    for (int i = 0; i < currentStudentCount; i++) {
        int total = 0;
        for (int j = 0; j < numTests; j++) {
            total += students[i].testScores[j];
        }
        students[i].average = static_cast<double>(total) / numTests;
        students[i].grade = getGrade(students[i].average);
    }

    averagesCalculated = true;
    cout << "Average test scores and grades calculated successfully!\n";
}

// Function to display results
void displayResults(Student students[], int currentStudentCount, bool averagesCalculated) {
    if (!averagesCalculated) {

        cout << "Please calculate average test scores before displaying results!\n";
        return;
    }

    // Sort students by average score in descending order
    sort(students, students + currentStudentCount, [](const Student &a, const Student &b) {
        return a.average > b.average;
    });

    cout << "\nFinal Report:\n";
    cout << "-------------------------------------------\n";
    cout << left << setw(20) << "Student" << setw(10) << "Average" << setw(5) << "Grade\n";
    cout << "-------------------------------------------\n";
    
    for (int i = 0; i < currentStudentCount; i++) {
        cout << left << setw(20) << students[i].name
             << setw(10) << fixed << setprecision(2) << students[i].average
             << setw(5) << students[i].grade << endl;
    }
}

// Main menu function
int main() {
    Student students[maxStudents];
    int currentStudentCount = 0;
    int numTests = 0;
    bool averagesCalculated = false;

    int choice;
    while (true) {
        choice = getValidatedInt("\nMenu:\n1. Add Students & Input Scores\n2. Calculate Average Test Scores & Assign Grades\n3. Display Results\n4. Exit\nEnter your choice: ", 1, 4);
        
        switch (choice) {
            case 1:
                inputStudentData(students, currentStudentCount, numTests);
                averagesCalculated = false;
                break;
            case 2:
                calculateAveragesAndGrades(students, currentStudentCount, numTests, averagesCalculated);
                break;
            case 3:
                displayResults(students, currentStudentCount, averagesCalculated);
                break;
            case 4:
                cout << "Exiting program. Goodbye!\n";
                return 0;
        }
    }
}
