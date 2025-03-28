/**
 * @file prog2.cpp
 * @brief A simple Student Management System using C++ templates and inheritance.
 * 
 * This program allows users to manage student records, including adding, displaying,
 * removing, and searching for students. It uses a template-based class structure
 * to handle student data generically.
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
 * @class Memory
 * @brief A generic class to store student data.
 * 
 * This class provides two vectors to store student IDs and names.
 * It serves as a base class for more specific student management functionality.
 * 
 * @tparam T The data type for student IDs and names.
 */
template<typename T>
class Memory {
    public:
        vector<T> studentIDs; ///< Vector to store student IDs.
        vector<T> studentNames; ///< Vector to store student names.
    
        /**
         * @brief Default constructor.
         * Displays a message when the Memory class is initialized.
         */
        Memory() {
            cout << "Memory class initialized."; 
        }

        /**
         * @brief Destructor.
         * Displays a message when the Memory class is destroyed.
         */
        ~Memory() {
            cout << "Memory class destroyed." << endl;
        }
};

/**
 * @class StudentsDetails
 * @brief A derived class for managing student records.
 * 
 * This class inherits from the Memory class and provides methods to add, display,
 * remove, and search for student records.
 * 
 * @tparam T The data type for student IDs and names.
 */
template<typename T>
class StudentsDetails : public Memory<T> {
    public:
        /**
         * @brief Default constructor.
         * Displays a message when the StudentsDetails class is initialized.
         */
        StudentsDetails() {
            cout << endl;
            cout << "StudentsDetails class initialized." << endl;
        }

        /**
         * @brief Adds student records.
         * Prompts the user to enter the number of students and their details (ID and name).
         */
        void addStudents() {
            cout << endl;
            int numstudents;
            cout << "Enter the number of students: ";
            cin >> numstudents;

            for (int i = 0; i < numstudents; i++) {
                T studentid, studentname; 
                cout << "Enter Student ID: ";
                cin >> studentid;
                cout << "Enter Student Name: ";
                cin >> studentname;

                this->studentIDs.push_back(studentid);
                this->studentNames.push_back(studentname);
            }
        }

        /**
         * @brief Displays all student records.
         * Iterates through the stored student IDs and names and prints them.
         */
        void displayAllStudents() {
            cout << endl;
            cout << "Student List:" << endl;
            for (size_t i = 0; i < this->studentIDs.size(); i++) {
                cout << "ID: " << this->studentIDs[i] << endl;
                cout << "Name: " << this->studentNames[i] << endl;
                cout << "======================" << endl;
            }
        }

        /**
         * @brief Removes a student record.
         * Prompts the user to enter a student ID and removes the corresponding record.
         */
        void removeStudent() {
            cout << endl;
            T studentid;
            cout << "Enter Student ID: ";
            cin >> studentid;

            for (size_t i = 0; i < this->studentIDs.size(); i++) {
                if (studentid == this->studentIDs[i]) {
                    this->studentIDs.erase(this->studentIDs.begin() + i);
                    this->studentNames.erase(this->studentNames.begin() + i);
                    cout << "Student removed.";
                    return;
                }
            }
        }

        /**
         * @brief Searches for a student record.
         * Prompts the user to enter a student ID and displays the corresponding record if found.
         */
        void searchStudent() {
            cout << endl;
            T studentid;
            cout << "Enter Student ID: ";
            cin >> studentid;

            for (size_t i = 0; i < this->studentIDs.size(); i++) {
                if (studentid == this->studentIDs[i]) {
                    cout << "ID: " << this->studentIDs[i] << endl;
                    cout << "Name: " << this->studentNames[i] << endl;
                    return;
                }
            }
        }

        /**
         * @brief Destructor.
         * Displays a message when the StudentsDetails class is destroyed.
         */
        ~StudentsDetails() {
            cout << "StudentsDetails class destroyed." << endl;
        }
};

/**
 * @brief Main function.
 * 
 * Provides a menu-driven interface for the user to interact with the Student Management System.
 * 
 * @return int Returns 0 on successful execution.
 */
int main() {
    StudentsDetails<string> std; // Create an instance of StudentsDetails with string type
    
    int choice;

    do {
        cout << endl;
        cout << "--- Student Management System ---" << endl;
        cout << "1. Add Students" << endl;
        cout << "2. Display All Students" << endl;
        cout << "3. Remove a Student" << endl;
        cout << "4. Search for a Student" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
            case 1:
                std.addStudents();
                break;
                
            case 2:
                std.displayAllStudents();
                break;

            case 3:
                std.removeStudent();
                break;

            case 4:                
                std.searchStudent();
                break;

            case 0:
                cout << "Exit the program...";
                break;
            default:
                cout << "Invalid choice!";
        }
    } while (choice != 0);

    return 0;
}