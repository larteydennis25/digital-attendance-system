//Digital Attendance System 
//EEE277 - Introduction to C++ Programing
//HND Electrical Engineering - Level 200
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

class Student {
public:
    string name;
    string indexNumber;
    string programme;
    string level;

    Student() {
        name = "";
        indexNumber = "";
        programme = "";
        level = "";
    }

    Student(string n, string id, string prog, string lvl) {
        name = n;
        indexNumber = id;
        programme = prog;
        level = lvl;
    }

    void display() const {
        cout << left
             << setw(25) << name
             << setw(15) << indexNumber
             << setw(30) << programme
             << setw(10) << level
             << endl;
    }
};

vector<Student> students;

void displayMenu();
void registerStudent();
void viewAllStudents();
void searchByIndexNumber();
void clearInputBuffer();

int main() {
    int choice;

    cout << "============================================" << endl;
    cout << "   DIGITAL ATTENDANCE SYSTEM" << endl;
    cout << "   HND Electrical Engineering - Level 200" << endl;
    cout << "============================================" << endl;

    do {
        displayMenu();
        cout << "Enter choice: ";
        cin >> choice;
        clearInputBuffer();

        switch (choice) {
            case 1:
                registerStudent();
                break;
            case 2:
                viewAllStudents();
                break;
            case 3:
                searchByIndexNumber();
                break;
            case 0:
                cout << "\nExiting system. Goodbye!" << endl;
                break;
            default:
                cout << "\nInvalid choice. Please try again." << endl;
        }

    } while (choice != 0);

    return 0;
}

void displayMenu() {
    cout << "\n--------------------------------------------" << endl;
    cout << "           STUDENT MANAGEMENT MENU" << endl;
    cout << "--------------------------------------------" << endl;
    cout << " 1. Register a new student" << endl;
    cout << " 2. View all registered students" << endl;
    cout << " 3. Search student by index number" << endl;
    cout << " 0. Exit" << endl;
    cout << "--------------------------------------------" << endl;
}

void clearInputBuffer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void registerStudent() {
    string name, indexNumber, programme, level;

    cout << "\n--- REGISTER NEW STUDENT ---" << endl;

    cout << "Enter student name       : ";
    getline(cin, name);

    cout << "Enter index number       : ";
    getline(cin, indexNumber);

    for (int i = 0; i < students.size(); i++) {
        if (students[i].indexNumber == indexNumber) {
            cout << "\nERROR: A student with index number '"
                 << indexNumber << "' is already registered." << endl;
            return;
        }
    }

    cout << "Enter programme          : ";
    getline(cin, programme);

    cout << "Enter level              : ";
    getline(cin, level);

 if (name.empty() || indexNumber.empty() || programme.empty() || level.empty()) {
        cout << "\nERROR: All fields are required. Student not registered." << endl;
        return;
    }

    Student newStudent(name, indexNumber, programme, level);
    students.push_back(newStudent);

    cout << "\nStudent '" << name << "' registered successfully!" << endl;
}

void viewAllStudents() {
    cout << "\n--- ALL REGISTERED STUDENTS ---" << endl;

    if (students.empty()) {
        cout << "No students registered yet." << endl;
        return;
    }

    cout << left
         << setw(25) << "NAME"
         << setw(15) << "INDEX NUMBER"
         << setw(30) << "PROGRAMME"
         << setw(10) << "LEVEL"
         << endl;

    cout << string(80, '-') << endl;

    for (int i = 0; i < students.size(); i++) {
        students[i].display();
    }

    cout << "\nTotal students registered: " << students.size() << endl;
}

void searchByIndexNumber() {
    string searchId;

    cout << "\n--- SEARCH STUDENT ---" << endl;
    cout << "Enter index number to search: ";
    getline(cin, searchId);

    for (int i = 0; i < students.size(); i++) {
        if (students[i].indexNumber == searchId) {
            cout << "\nStudent found:" << endl;
            cout << left
                 << setw(25) << "NAME"
                 << setw(15) << "INDEX NUMBER"
                 << setw(30) << "PROGRAMME"
                 << setw(10) << "LEVEL"
                 << endl;
            cout << string(80, '-') << endl;
            students[i].display();
            return;
        }
    }

    cout << "\nNo student found with index number: " << searchId << endl;
}
