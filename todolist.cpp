#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void banner() {
    cout << "___________________" << endl;
    cout << "     TO DO LIST    " << endl;
    cout << "___________________" << endl;
}

void Addtask() {
    system("cls");
    banner();
    string task;
    cout << "Enter new Task: ";
    getline(cin, task);
    char save;
    cout << "Save? (y/n): ";
    cin >> save;
    if (save == 'y') {
        static int ID = 0;
        ID++;
        ofstream fout("todo.txt", ios::app);
        fout << "\nID: " << ID << "\nTask: " << task << endl;
        fout.close();
        char more;
        cout << "Add more tasks? (y/n): ";
        cin >> more;
        if (more == 'y') {
            Addtask();
        }
        else {
            system("cls");
            cout << "Tasks added successfully." << endl;
        }
    }
}

void Showtask() {
    system("cls");
    banner();
    ifstream fin("todo.txt");
    string line;
    cout << "Tasks:" << endl;
    while (getline(fin, line)) {
        cout << line << endl;
    }
    fin.close();
}

void Searchtask() {
    system("cls");
    banner();
    ifstream fin("todo.txt");
    string task, line;
    cout << "Enter task to search: ";
    cin.ignore();
    getline(cin, task);
    bool found = false;
    while (getline(fin, line)) {
        if (line.find(task) != string::npos) {
            cout << "Task found: " << line << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Task not found." << endl;
    }
    fin.close();
}

void Deletetask() {
    system("cls");
    banner();
    ifstream fin("todo.txt");
    ofstream temp("temp.txt");
    string task, line;
    cout << "Enter task to delete: ";
    cin.ignore();
    getline(cin, task);
    bool found = false;
    while (getline(fin, line)) {
        if (line.find(task) != string::npos) {
            cout << "Task deleted: " << line << endl;
            found = true;
        }
        else {
            temp << line << endl;
        }
    }
    if (!found) {
        cout << "Task not found." << endl;
    }
    fin.close();
    temp.close();
    remove("todo.txt");
    rename("temp.txt", "todo.txt");
}

void Updatetask() {
    system("cls");
    banner();
    ifstream fin("todo.txt");
    ofstream temp("temp.txt");
    string task, line;
    cout << "Enter task to update: ";
    cin.ignore();
    getline(cin, task);
    bool found = false;
    while (getline(fin, line)) {
        if (line.find(task) != string::npos) {
            cout << "Enter new task: ";
            string newTask;
            getline(cin, newTask);
            static int ID = 0; // Resetting ID
            ID++;
            temp << "\nID: " << ID << "\nTask: " << newTask << endl;
            cout << "Task updated." << endl;
            found = true;
        }
        else {
            temp << line << endl;
        }
    }
    if (!found) {
        cout << "Task not found." << endl;
    }
    fin.close();
    temp.close();
    remove("todo.txt");
    rename("temp.txt", "todo.txt");
}

int main() {
    system("cls");
    while (true) {
        banner();
        cout << "\t1. Add task" << endl;
        cout << "\t2. Show tasks" << endl;
        cout << "\t3. Search task" << endl;
        cout << "\t4. Delete task" << endl;
        cout << "\t5. Update task" << endl;
        int choice;
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                Addtask();
                break;
            case 2:
                Showtask();
                break;
            case 3:
                Searchtask();
                break;
            case 4:
                Deletetask();
                break;
            case 5:
                Updatetask();
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}