digital-attendance-system
c++ console-based digital attendance system for lecture sessions
Week 3 Features Implemented

- AttendanceRecord class to track student attendance per session
- Mark attendance for students (Present, Absent, Late)
- View attendance records for specific sessions
- Generate attendance summary with counts
- Validation to prevent duplicate attendance marking
- Link between students, sessions, and attendance records

 Week 4 Features Implemented

- File storage using fstream library
- Save students to students.txt
- Save sessions to sessions.txt
- Save attendance records to attendance.txt
- Load all data automatically on program start
- Data persists between program executions
- Automatic save on exit

Complete Feature List

Student Management:
- Register students with validation
- View all students in formatted table
- Search students by index number
- Prevent duplicate index numbers

Session Management:
- Create lecture sessions with course code, date, time, duration
- View all created sessions
- Session validation

Attendance Management:
- Mark attendance as Present/Absent/Late
- View attendance for specific sessions
- Generate attendance summary with statistics
- Prevent duplicate attendance marking

Data Persistence:
- Automatic file saving and loading
- Data preserved across sessions
- Three separate data files for organization

Testing Checklist

✅ Register multiple students  
✅ Create multiple sessions  
✅ Mark attendance for students  
✅ View attendance records  
✅ Generate attendance summary  
✅ Exit and restart - data persists  
✅ All validation working  
✅ No duplicate entries allowed  
