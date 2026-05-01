#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct Course {
    string name;
    double grade;
    int credits;
};

int main() {
    int numCourses;
    double totalGradePoints = 0;
    int totalCredits = 0;

    cout << "--- Student CGPA Calculator ---" << endl;
    cout << "Enter the number of courses: ";
    cin >> numCourses;

    vector<Course> courses(numCourses);

    for (int i = 0; i < numCourses; i++) {
        cout << "\nEnter details for Course " << i + 1 << ":" << endl;
        cout << "Course Name/ID: ";
        cin >> courses[i].name;
        cout << "Grade points : ";
        cin >> courses[i].grade;
        cout << "Credit hours: ";
        cin >> courses[i].credits;

        totalGradePoints += (courses[i].grade * courses[i].credits);
        totalCredits += courses[i].credits;
    }

    cout << "\n-------------------------------" << endl;
    cout << "Summary of Results:" << endl;
    cout << left << setw(15) << "Course" << setw(10) << "Grade" << "Credits" << endl;

    for (const auto& c : courses) {
        cout << left << setw(15) << c.name << setw(10) << c.grade << c.credits << endl;
    }

    if (totalCredits > 0) {
        double cgpa = totalGradePoints / totalCredits;

        cout << "-------------------------------" << endl;
        cout << "Total Credits: " << totalCredits << endl;
        cout << fixed << setprecision(2);
        cout << "Final CGPA:    " << cgpa << endl;
        cout << "-------------------------------" << endl;
    } else {
        cout << "No credits earned. Cannot calculate CGPA." << endl;
    }

    return 0;
}
