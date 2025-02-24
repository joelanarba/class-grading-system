# Class Grading System (C++)

## Description

This is a simple C++ program that manages a small class grading system. It allows users to input student names and test scores, calculates their average scores, and assigns final grades based on predefined criteria. The program also provides a menu system for easy navigation.

## Features

- Stores student data (names, test scores, and grades) using arrays.
- Allows up to 10 students, each with a maximum of 5 test scores.
- Validates input to ensure test scores are between 0 and 100.
- Calculates average scores for each student.
- Assigns letter grades based on a grading scale:
  - A: 90 and above
  - B: 80 - 89
  - C: 70 - 79
  - D: 60 - 69
  - F: Below 60
- Displays results in a formatted table, sorted by average score.
- User-friendly menu for adding students, computing grades, and displaying results.

## Compilation & Execution

### Requirements

- A C++ compiler 

### Steps to Compile & Run

```sh
# Compile the program
g++ main.cpp -o class_grading_system

# Run the executable
./class_grading_system

Usage
Menu Options
Add Students & Input Scores
Enter the number of students.
Input student names and test scores.
Calculate Average Test Scores & Assign Grades
Computes average scores and assigns letter grades.
Display Results
Shows student names, average scores, and assigned grades in a sorted table.
Exit
Terminates the program.
Sample Output
Menu:
1. Add Students & Input Scores
2. Calculate Average Test Scores & Assign Grades
3. Display Results
4. Exit
Enter your choice: 1

Enter the number of students (max 10): 2
Enter name of student #1: Alice
Enter test #1 score (0 to 100): 85
Enter test #2 score (0 to 100): 90
Enter test #3 score (0 to 100): 78
Enter test #4 score (0 to 100): 92
Enter test #5 score (0 to 100): 88

Enter name of student #2: Bob
Enter test #1 score (0 to 100): 70
Enter test #2 score (0 to 100): 75
Enter test #3 score (0 to 100): 65
Enter test #4 score (0 to 100): 80
Enter test #5 score (0 to 100): 72

Students' names and test scores recorded successfully!

Menu:
Enter your choice: 2
Average test scores and grades calculated successfully!

Menu:
Enter your choice: 3

Final Report:
-------------------------------------------
Student             Average   Grade
-------------------------------------------
Alice                 86.6        B
Bob                   72.4        C

Author
Joel Anarba Amuni

License
This project is licensed under the MIT License.

Contributions
Contributions, issues, and feature requests are welcome! Feel free to fork this repository and submit a pull request.