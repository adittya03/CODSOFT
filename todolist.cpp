#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function prototypes
void displayMenu();
void addTask(vector<string>& tasks);
void viewTasks(const vector<string>& tasks);
void deleteTask(vector<string>& tasks);

int main() {
    vector<string> tasks; // Store tasks

    char choice;
    do {
        displayMenu();
        cin >> choice;

        switch(choice) {
            case '1':
                addTask(tasks);
                break;
            case '2':
                viewTasks(tasks);
                break;
            case '3':
                deleteTask(tasks);
                break;
            case '4':
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != '4');

    return 0;
}

// Function to display the menu
void displayMenu() {
    cout << "\n===== To-Do List Manager =====\n";
    cout << "1. Add a task\n";
    cout << "2. View tasks\n";
    cout << "3. Delete a task\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}

// Function to add a task
void addTask(vector<string>& tasks) {
    string task;
    cout << "Enter the task to add: ";
    cin.ignore(); // Ignore the newline character left in the input buffer
    getline(cin, task);
    tasks.push_back(task);
    cout << "Task added successfully.\n";
}

// Function to view tasks
void viewTasks(const vector<string>& tasks) {
    cout << "\n===== Tasks =====\n";
    if (tasks.empty()) {
        cout << "No tasks available.\n";
    } else {
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i] << endl;
        }
    }
}

// Function to delete a task
void deleteTask(vector<string>& tasks) {
    viewTasks(tasks);
    if (tasks.empty()) {
        cout << "No tasks available to delete.\n";
        return;
    }
    
    int index;
    cout << "Enter the index of the task to delete: ";
    cin >> index;

    if (index < 1 || index > tasks.size()) {
        cout << "Invalid index.\n";
    } else {
        tasks.erase(tasks.begin() + index - 1);
        cout << "Task deleted successfully.\n";
    }
}
