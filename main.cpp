#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>
#include <fstream>

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

class AttendanceRecord {
public:
    string sessionCourseCode;
    string sessionDate;
    string studentIndexNumber;
    string status;

    AttendanceRecord() {
        sessionCourseCode = "";
        sessionDate = "";
        studentIndexNumber = "";
        status = "";
    }

    AttendanceRecord(string course, string date, string index, string stat) {
        sessionCourseCode = course;
        sessionDate = date;
        studentIndexNumber = index;
        status = stat;
    }
};

vector<Student> students;
vector<AttendanceSession> sessions;
vector<AttendanceRecord> attendanceRecords;

void displayMenu();
void registerStudent();
void viewAllStudents();
void searchByIndexNumber();
void clearInputBuffer();
void createSession();
void viewAllSessions();
void markAttendance();
void viewSessionAttendance();
void getAttendanceSummary();
void saveStudentsToFile();
void loadStudentsFromFile();
void saveSessionsToFile();
void loadSessionsFromFile();
void saveAttendanceToFile();
void loadAttendanceFromFile();

int main() {
    int choice;

    cout << "============================================" << endl;
    cout << "   DIGITAL ATTENDANCE SYSTEM" << endl;
    cout << "   HND Electrical/Electronics Engineering - Level 200" << endl;
    cout << "============================================" << endl;
    
    loadStudentsFromFile();
    loadSessionsFromFile();
    loadAttendanceFromFile();
    
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
            case 6:
                markAttendance();
                break;
            case 7:
                viewSessionAttendance();
                break;
            case 8:
                getAttendanceSummary();
                break;
            case 0:
                saveStudentsToFile();
                saveSessionsToFile();
                saveAttendanceToFile();
                cout << "\nData saved. Exiting system. Goodbye!" << endl;
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
    cout << "\n ATTENDANCE MANAGEMENT" << endl;
    cout << " 6. Mark attendance for a session" << endl;
    cout << " 7. View attendance for a session" << endl;
    cout << " 8. Get attendance summary" << endl;
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

void markAttendance() {
    if (sessions.empty()) {
        cout << "\nNo sessions available. Create a session first." << endl;
        return;
    }
    
    if (students.empty()) {
        cout << "\nNo students registered. Register students first." << endl;
        return;
    }

    string courseCode, date;
    
    cout << "\n--- MARK ATTENDANCE ---" << endl;
    cout << "Enter course code: ";
    getline(cin, courseCode);
    
    cout << "Enter date (YYYY-MM-DD): ";
    getline(cin, date);
    
    bool sessionFound = false;
    for (int i = 0; i < sessions.size(); i++) {
        if (sessions[i].courseCode == courseCode && sessions[i].date == date) {
            sessionFound = true;
            break;
        }
    }
    
    if (!sessionFound) {
        cout << "\nSession not found!" << endl;
        return;
    }
    
    cout << "\n--- Students List ---" << endl;
    for (int i = 0; i < students.size(); i++) {
        cout << (i + 1) << ". " << students[i].name 
             << " (" << students[i].indexNumber << ")" << endl;
    }
    
    int studentNum;
    string status;
    
    cout << "\nEnter student number (or 0 to finish): ";
    cin >> studentNum;
    clearInputBuffer();
    
    while (studentNum != 0) {
        if (studentNum < 1 || studentNum > students.size()) {
            cout << "Invalid student number!" << endl;
        } else {
            string indexNum = students[studentNum - 1].indexNumber;
            
            bool alreadyMarked = false;
            for (int i = 0; i < attendanceRecords.size(); i++) {
                if (attendanceRecords[i].sessionCourseCode == courseCode &&
                    attendanceRecords[i].sessionDate == date &&
                    attendanceRecords[i].studentIndexNumber == indexNum) {
                    alreadyMarked = true;
                    break;
                }
            }
            
            if (alreadyMarked) {
                cout << "Attendance already marked for this student!" << endl;
            } else {
                cout << "Status (P=Present, A=Absent, L=Late): ";
                getline(cin, status);
                
                if (status == "P" || status == "A" || status == "L") {
                    AttendanceRecord record(courseCode, date, indexNum, status);
                    attendanceRecords.push_back(record);
                    cout << "Attendance marked successfully!" << endl;
                } else {
                    cout << "Invalid status!" << endl;
                }
            }
        }
        
        cout << "\nEnter student number (or 0 to finish): ";
        cin >> studentNum;
        clearInputBuffer();
    }
}

void viewSessionAttendance() {
    if (attendanceRecords.empty()) {
        cout << "\nNo attendance records found." << endl;
        return;
    }
    
    string courseCode, date;
    
    cout << "\n--- VIEW SESSION ATTENDANCE ---" << endl;
    cout << "Enter course code: ";
    getline(cin, courseCode);
    
    cout << "Enter date (YYYY-MM-DD): ";
    getline(cin, date);
    
    cout << "\nAttendance for " << courseCode << " on " << date << ":" << endl;
    cout << string(80, '-') << endl;
    cout << left
         << setw(25) << "NAME"
         << setw(15) << "INDEX NUMBER"
         << setw(10) << "STATUS"
         << endl;
    cout << string(80, '-') << endl;
    
    bool found = false;
    for (int i = 0; i < attendanceRecords.size(); i++) {
        if (attendanceRecords[i].sessionCourseCode == courseCode &&
            attendanceRecords[i].sessionDate == date) {
            found = true;
            
            for (int j = 0; j < students.size(); j++) {
                if (students[j].indexNumber == attendanceRecords[i].studentIndexNumber) {
                    string statusFull;
                    if (attendanceRecords[i].status == "P") statusFull = "Present";
                    else if (attendanceRecords[i].status == "A") statusFull = "Absent";
                    else if (attendanceRecords[i].status == "L") statusFull = "Late";
                    
                    cout << left
                         << setw(25) << students[j].name
                         << setw(15) << students[j].indexNumber
                         << setw(10) << statusFull
                         << endl;
                    break;
                }
            }
        }
    }
    
    if (!found) {
        cout << "No attendance records for this session." << endl;
    }
}

void getAttendanceSummary() {
    if (attendanceRecords.empty()) {
        cout << "\nNo attendance records found." << endl;
        return;
    }
    
    string courseCode, date;
    
    cout << "\n--- ATTENDANCE SUMMARY ---" << endl;
    cout << "Enter course code: ";
    getline(cin, courseCode);
    
    cout << "Enter date (YYYY-MM-DD): ";
    getline(cin, date);
    
    int present = 0, absent = 0, late = 0;
    
    for (int i = 0; i < attendanceRecords.size(); i++) {
        if (attendanceRecords[i].sessionCourseCode == courseCode &&
            attendanceRecords[i].sessionDate == date) {
            if (attendanceRecords[i].status == "P") present++;
            else if (attendanceRecords[i].status == "A") absent++;
            else if (attendanceRecords[i].status == "L") late++;
        }
    }
    
    cout << "\nSummary for " << courseCode << " on " << date << ":" << endl;
    cout << "Present: " << present << endl;
    cout << "Absent:  " << absent << endl;
    cout << "Late:    " << late << endl;
    cout << "Total:   " << (present + absent + late) << endl;
}

void saveStudentsToFile() {
    ofstream file("students.txt");
    if (!file) {
        cout << "Error: Could not save students." << endl;
        return;
    }
    
    for (int i = 0; i < students.size(); i++) {
        file << students[i].name << "|"
             << students[i].indexNumber << "|"
             << students[i].programme << "|"
             << students[i].level << endl;
    }
    
    file.close();
}

void loadStudentsFromFile() {
    ifstream file("students.txt");
    if (!file) {
        return;
    }
    
    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;
        
        Student s;
        size_t pos1 = line.find('|');
        size_t pos2 = line.find('|', pos1 + 1);
        size_t pos3 = line.find('|', pos2 + 1);
        
        s.name = line.substr(0, pos1);
        s.indexNumber = line.substr(pos1 + 1, pos2 - pos1 - 1);
        s.programme = line.substr(pos2 + 1, pos3 - pos2 - 1);
        s.level = line.substr(pos3 + 1);
        
        students.push_back(s);
    }
    
    file.close();
}

void saveSessionsToFile() {
    ofstream file("sessions.txt");
    if (!file) {
        cout << "Error: Could not save sessions." << endl;
        return;
    }
    
    for (int i = 0; i < sessions.size(); i++) {
        file << sessions[i].courseCode << "|"
             << sessions[i].date << "|"
             << sessions[i].startTime << "|"
             << sessions[i].durationHours << endl;
    }
    
    file.close();
}

void loadSessionsFromFile() {
    ifstream file("sessions.txt");
    if (!file) {
        return;
    }
    
    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;
        
        AttendanceSession sess;
        size_t pos1 = line.find('|');
        size_t pos2 = line.find('|', pos1 + 1);
        size_t pos3 = line.find('|', pos2 + 1);
        
        sess.courseCode = line.substr(0, pos1);
        sess.date = line.substr(pos1 + 1, pos2 - pos1 - 1);
        sess.startTime = line.substr(pos2 + 1, pos3 - pos2 - 1);
        sess.durationHours = stoi(line.substr(pos3 + 1));
        
        sessions.push_back(sess);
    }
    
    file.close();
}

void saveAttendanceToFile() {
    ofstream file("attendance.txt");
    if (!file) {
        cout << "Error: Could not save attendance." << endl;
        return;
    }
    
    for (int i = 0; i < attendanceRecords.size(); i++) {
        file << attendanceRecords[i].sessionCourseCode << "|"
             << attendanceRecords[i].sessionDate << "|"
             << attendanceRecords[i].studentIndexNumber << "|"
             << attendanceRecords[i].status << endl;
    }
    
    file.close();
}

void loadAttendanceFromFile() {
    ifstream file("attendance.txt");
    if (!file) {
        return;
    }
    
    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;
        
        AttendanceRecord rec;
        size_t pos1 = line.find('|');
        size_t pos2 = line.find('|', pos1 + 1);
        size_t pos3 = line.find('|', pos2 + 1);
        
        rec.sessionCourseCode = line.substr(0, pos1);
        rec.sessionDate = line.substr(pos1 + 1, pos2 - pos1 - 1);
        rec.studentIndexNumber = line.substr(pos2 + 1, pos3 - pos2 - 1);
        rec.status = line.substr(pos3 + 1);
        
        attendanceRecords.push_back(rec);
    }
    
    file.close();
}
