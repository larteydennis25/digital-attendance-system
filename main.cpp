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

class AttendanceSession {
public:
    string courseCode;
    string date;
    string startTime;
    int durationHours;

    AttendanceSession() {
        courseCode = "";
        date = "";
        startTime = "";
        durationHours = 0;
    }

    AttendanceSession(string code, string d, string time, int duration) {
        courseCode = code;
        date = d;
        startTime = time;
        durationHours = duration;
    }

    void display() const {
        cout << left
             << setw(15) << courseCode
             << setw(15) << date
             << setw(12) << startTime
             << setw(10) << durationHours
             << endl;
    }
};

vector<Student> students;
vector<AttendanceSession> sessions;

void displayMenu();
void registerStudent();
void viewAllStudents();
void searchByIndexNumber();
void clearInputBuffer();
void createSession();
void viewAllSessions();

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
            case 4:
                createSession();
                break;
            case 5:
                viewAllSessions();
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
    cout << "\n============================================" << endl;
    cout << "           MAIN MENU" << endl;
    cout << "============================================" << endl;
    cout << " STUDENT MANAGEMENT" << endl;
    cout << " 1. Register a new student" << endl;
    cout << " 2. View all registered students" << endl;
    cout << " 3. Search student by index number" << endl;
    cout << "\n SESSION MANAGEMENT" << endl;
    cout << " 4. Create new attendance session" << endl;
    cout << " 5. View all sessions" << endl;
    cout << "\n 0. Exit" << endl;
    cout << "============================================" << endl;
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

void createSession() {
    string courseCode, date, startTime;
    int durationHours;

    cout << "\n--- CREATE NEW ATTENDANCE SESSION ---" << endl;

    cout << "Enter course code        : ";
    getline(cin, courseCode);

    cout << "Enter date (YYYY-MM-DD)  : ";
    getline(cin, date);

    cout << "Enter start time (HH:MM) : ";
    getline(cin, startTime);

    cout << "Enter duration (hours)   : ";
    cin >> durationHours;
    clearInputBuffer();

    if (courseCode.empty() || date.empty() || startTime.empty() || durationHours <= 0) {
        cout << "\nERROR: All fields are required and duration must be positive." << endl;
        return;
    }

    AttendanceSession newSession(courseCode, date, startTime, durationHours);
    sessions.push_back(newSession);

    cout << "\nSession for " << courseCode << " created successfully!" << endl;
}

void viewAllSessions() {
    cout << "\n--- ALL ATTENDANCE SESSIONS ---" << endl;

    if (sessions.empty()) {
        cout << "No sessions created yet." << endl;
        return;
    }

    cout << left
         << setw(15) << "COURSE CODE"
         << setw(15) << "DATE"
         << setw(12) << "START TIME"
         << setw(10) << "DURATION"
         << endl;

    cout << string(52, '-') << endl;

    for (int i = 0; i < sessions.size(); i++) {
        sessions[i].display();
    }

    cout << "\nTotal sessions: " << sessions.size() << endl;
}
