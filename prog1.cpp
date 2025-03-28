#include <iostream>
#include <vector>
#include <string>
using namespace std;

template<typename T>
class Memory {
    public:
        vector<T> studentIDs; // Vector to store student IDs
        vector<T> studentNames; // Vector to store student names
    
    // Default constructor
    Memory() {
        cout << "Memory class initialized."; // Message displayed when Memory class is initialized
    }

    // Destructor
    ~Memory() {
        cout << "Memory class destroyed."<<endl; // Message displayed when Memory class is destroyed
    }
};

template<typename T>
class StudentsDetails : public Memory<T> {

    public:       
        StudentsDetails() {
            cout<<endl;
            cout << "StudentsDetails class initialized."<<endl; // Message displayed when StudentsDetails class is initialized
        }

        void addStudents() {
            cout<<endl;
            int numstudents;
            cout << "Enter the number of students: "; // Prompt to enter the number of students
            cin >> numstudents;

            for (int i = 0; i < numstudents; i++) {
                T studentid, studentname; 
                cout << "Enter Student ID: ";
                cin >> studentid; // Taking student ID
                cout << "Enter Student Name: ";
                cin >> studentname; // Taking student name

                // Add student ID and name to respective vectors
                this->studentIDs.push_back(studentid);
                this->studentNames.push_back(studentname);
            }
        }

        void displayAllStudents() {
            cout<<endl;
            cout << "Student List:"<<endl; // Display all students
            for (size_t i = 0; i < this->studentIDs.size(); i++) {
                cout << "ID: " << this->studentIDs[i] <<endl; 
                cout << "Name: " << this->studentNames[i] << endl; 
                cout<<"======================"<<endl;
            }
        }

        void removeStudent() {
            cout<<endl;
            T studentid;
            cout << "Enter Student ID: "; // Prompt to enter the student ID to remove
            cin >> studentid;

            for (size_t i = 0; i < this->studentIDs.size(); i++) {
                if (studentid == this->studentIDs[i]) { // Check if the student ID matches
                    this->studentIDs.erase(this->studentIDs.begin() + i); // Remove student ID
                    this->studentNames.erase(this->studentNames.begin() + i); // Remove student name
                    cout << "Student removed."<<endl; // Confirmation message                    
                }
                else{
                    cout<<"Invalid Choice Id."<<endl;
                }
            }
        }

        void searchStudent() {
            cout<<endl;
            T studentid;
            cout << "Enter Student ID: "; // Prompt to enter the student ID to search
            cin >> studentid;

            for (size_t i = 0; i < this->studentIDs.size(); i++) {
                if (studentid == this->studentIDs[i]) { // Check if the student ID matches
                    cout << "ID: " << this->studentIDs[i]<<endl;
                    cout<< "Name: " << this->studentNames[i] << endl; // Display student details
                }
                else{
                    cout<<"Invalid Choice Id."<<endl;
                }
            }
        }

        ~StudentsDetails() {
            cout << "StudentsDetails class destroyed."<<endl; // Message displayed when StudentsDetails class is destroyed
        }
};

int main() {
    StudentsDetails<string> std; // Create an instance of StudentsDetails with string type
    
    int choice;

    do {
        cout<<endl;
        cout << "***** Student Management System *****"<<endl; // Menu header
        cout << "1. Add Students"<<endl; // Option to add students
        cout << "2. Display All Students"<<endl; // Option to display all students
        cout << "3. Remove a Student"<<endl; // Option to remove a student
        cout << "4. Search for a Student"<<endl; // Option to search for a student
        cout << "0. Exit"<<endl; // Option to exit the program
        cout << "Enter your choice: "; // Prompt to enter user choice
        cin >> choice;
        cout<<endl;

        // User choice
        switch (choice) {
            case 1:
                std.addStudents(); // Call addStudents method
                break;
                
            case 2:
                std.displayAllStudents(); // Call displayAllStudents method
                break;

            case 3:
                std.removeStudent(); // Call removeStudent method
                break;

            case 4:                
                std.searchStudent(); // Call searchStudent method
                break;

            case 0:
                cout << "Exit the program..."<<endl; // Exit message
                break;
            default:
                cout << "Invalid choice!"; // Invalid choice message
        }
    } while (choice != 0); // Loop until the user chooses to exit

    return 0;
}