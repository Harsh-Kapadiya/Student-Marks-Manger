// here i am making an student marks manager using vector
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

int main(){

    int studentmark; // used to enter the student marks
    int choice;   // choice which i have to choose
    int studentnumber;  //used in the first condition so that i can check i enter all the student that i have to enter 
    string studentname; // to enter the student name
    int numberofstudent;
    int rollno = 1;  // roll number of the student 

    vector<string> name;
    vector<int> marks;

    // this loop used for the multiple choice entering 
    for(int i=1; ; i++){
        cout << "===== Student Marks Manager =====" << endl;
        cout << "1. Add Student" << endl;  
        cout << "2. Display All Students" << endl;
        cout << "3. Search Student" << endl;
        cout << "4. Update Marks" << endl;
        cout << "5. Delete Student" << endl;
        cout << "6. Exit" << endl;
        cout << "=================================" << endl; 
        cout << "Enter your choice: ";
        cin >> choice;
        
    // first choice to enter the details about the student
        if(choice == 1){
            cout << "Enter the number of student you have to add: ";
            cin >>numberofstudent;
            for(int i=0; i < numberofstudent; i++){
                cout << "Roll number: "<< rollno + i << endl;
                cout << "Enter the student name: ";
                cin >> studentname;
                name.push_back(studentname);
                cout << "Enter the total marks of the student: ";
                cin >> studentmark;
                marks.push_back(studentmark);
            }
            cout << "All the entered data are stored"<<endl;;
        }
    
    // second choice to display all the the details of the both the vector
        else if(choice == 2){
            if (name.empty() && marks.empty()){
                cout << "No Student details found" << endl << endl << endl;
            }
            else{
                cout << "Student details are: " <<endl;
                for (int i = 0; i < name.size(); i++){
                    cout << "Roll number: "<< rollno + i << endl;
                    cout << "Student name: ";
                    cout << name[i] << endl;
                    cout << "student marks: ";
                    cout << marks[i] << endl << endl;
                }
            }
        }

    // third choice to search for the student
        else if(choice == 3){
            if (name.empty() && marks.empty()){
                cout << "No Student details found" << endl << endl << endl;
            }
            else{
                cout << "Enter the roll number of the student you want to update the marks: ";
                cin >> rollno;
                cout << "Student detilas are: " << endl; 
                cout << "Name: " << name[rollno - 1] << endl;
                cout << "Marks: " << marks[rollno-1] << endl;


            }
        }

    // 4th choice to update the student marks
        else if(choice == 4){
            int updateroll;
            if (name.empty() && marks.empty()){
                cout << "No Student details found" << endl << endl << endl;
            }
            else{
                cout << "Enter the roll number of the student you want to update the marks: ";
                cin >> rollno;
                cout << "Student detilas are: " << endl; 
                cout << "Name: " << name[rollno - 1] << endl;
                cout << "Marks: " << marks[rollno-1] << endl;
                cout << "Enter the updated marks: " ;
                int newmarks;
                cin >> newmarks;
                marks[rollno-1] = newmarks;
                cout << "Marks updated successfully";
            }
        }

    // fith delet the student details
        else if(choice == 5){
            int dsr;
            cout << "Enter the roll number of the student you want to delet the data: ";
            cin >> dsr;
            name.erase(name.begin()+(rollno+1));
            marks.erase(marks.begin()+(rollno+1));
            cout << "Student data delected successfully";
        }   
        

    //choice 6 is for exit from the code
        else if (choice ==6){
            break;
        }   

    // show when any other number is inputed
        else{
            cout << "Please Enter a valid choice";
        }
    }
    
    return 0;
}