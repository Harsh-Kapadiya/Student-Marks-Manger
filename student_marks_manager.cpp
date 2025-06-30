#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

int main() {
    int choice;
    string studentname;
    int studentmark;
    int rollno = 1;

    vector<string> name;
    vector<int> marks;

    //Load Existing or Create Sample Students
    ifstream infile("students.txt");
    if (infile.is_open()) {
        string tempName;
        int tempMarks;
        while (infile >> tempName >> tempMarks) {
            name.push_back(tempName);
            marks.push_back(tempMarks);
        }
        infile.close();
    }

    //Print All Loaded Data on Startup
    cout << "\n========== Initial Student List ==========\n";
    for (int i = 0; i < name.size(); i++) {
        cout << "Roll No: " << i + 1 << " | Name: " << name[i] << " | Marks: " << marks[i] << endl;
    }
    cout << "==========================================\n\n";

    // ====== Menu Starts Here ======
    while (true) {
        cout << "\n===== Student Marks Manager =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Marks\n";
        cout << "5. Delete Student\n";
        cout << "6. Exit\n";
        cout << "=================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // 1. Add Student
        if (choice == 1) {
            int numberofstudent;
            cout << "Enter the total number of students you want to add: ";
            cin >> numberofstudent;

            for (int i = 0; i < numberofstudent; i++) {
                cout << "Roll number: " << name.size() + 1 << endl;
                cout << "Enter the student name: ";
                cin >> studentname;
                name.push_back(studentname);

                cout << "Enter the total marks of the student: ";
                cin >> studentmark;
                marks.push_back(studentmark);
            }

            // Write updated data to file
            ofstream outfile("students.txt");
            for (int i = 0; i < name.size(); i++) {
                outfile << name[i] << " " << marks[i] << endl;
            }
            outfile.close();

            cout << "All data has been saved successfully.\n";
        }

        // 2. Display All Students
        else if (choice == 2) {
            if (name.empty()) {
                cout << "No Student details found.\n";
            } else {
                cout << "\nStudent details:\n";
                for (int i = 0; i < name.size(); i++) {
                    cout << "Roll No: " << i + 1 << endl;
                    cout << "Name   : " << name[i] << endl;
                    cout << "Marks  : " << marks[i] << "\n\n";
                }
            }
        }

        // 3. Search Student by Roll No
        else if (choice == 3) {
            int searchRoll;
            cout << "Enter the roll number to search: ";
            cin >> searchRoll;

            if (searchRoll <= 0 || searchRoll > name.size()) {
                cout << "Invalid Roll Number!\n";
            } else {
                cout << "Student details:\n";
                cout << "Name  : " << name[searchRoll - 1] << endl;
                cout << "Marks : " << marks[searchRoll - 1] << endl;
            }
        }

        // 4. Update Student Marks
        else if (choice == 4) {
            int updateRoll;
            cout << "Enter the roll number to update marks: ";
            cin >> updateRoll;

            if (updateRoll <= 0 || updateRoll > name.size()) {
                cout << "Invalid Roll Number!\n";
            } else {
                cout << "Current Marks of " << name[updateRoll - 1] << ": " << marks[updateRoll - 1] << endl;
                cout << "Enter the new marks: ";
                cin >> studentmark;
                marks[updateRoll - 1] = studentmark;

                // Update file
                ofstream outfile("students.txt");
                for (int i = 0; i < name.size(); i++) {
                    outfile << name[i] << " " << marks[i] << endl;
                }
                outfile.close();

                cout << "Marks updated successfully.\n";
            }
        }

        // 5. Delete Student
        else if (choice == 5) {
            int delRoll;
            cout << "Enter the roll number to delete student data: ";
            cin >> delRoll;

            if (delRoll <= 0 || delRoll > name.size()) {
                cout << "Invalid Roll Number!\n";
            } else {
                name.erase(name.begin() + delRoll - 1);
                marks.erase(marks.begin() + delRoll - 1);

                // Update file
                ofstream outfile("students.txt");
                for (int i = 0; i < name.size(); i++) {
                    outfile << name[i] << " " << marks[i] << endl;
                }
                outfile.close();

                cout << "Student data deleted successfully.\n";
            }
        }

        // 6. Exit
        else if (choice == 6) {
            cout << "Exiting the program.\n";
            break;
        }

        // Invalid choice
        else {
            cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
