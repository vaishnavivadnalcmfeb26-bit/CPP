#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Employee {
private:
    int empID;
    string empName;
    double empSalary;

public:
    Employee(int id, string name, double sal) : empID(id), empName(name), empSalary(sal) {}

    // Getters and Setters
    int getID() { return empID; }
    void setName(string n) { empName = n; }
    void setSalary(double s) { empSalary = s; }

    double calculateGross() {
        double bonus = (empSalary <= 5000) ? 0.10 : (empSalary <= 10000) ? 0.15 : 0.20;
        return empSalary + (empSalary * bonus);
    }

    void display() {
        cout << "ID: " << empID << " | Name: " << empName 
             << " | Base: $" << empSalary << " | Gross: $" << calculateGross() << endl;
    }
};

int main() {
    vector<Employee> list;
    int choice, id;
    string name;
    double sal;

    while (true) {
        cout << "\n1.Add 2.Gross 3.Display 4.Update 5.Exit\nChoice: ";
        cin >> choice;
        if (choice == 5) break;

        if (choice == 1) {
            cout << "Enter ID, Name, Salary: ";
            cin >> id >> name >> sal;
            // Simple uniqueness check
            bool exists = false;
            for(auto &e : list) if(e.getID() == id) exists = true;
            if(!exists) list.push_back(Employee(id, name, sal));
            else cout << "ID already exists!\n";
        } 
        else {
            cout << "Enter Employee ID: ";
            cin >> id;
            for (auto &e : list) {
                if (e.getID() == id) {
                    if (choice == 2) cout << "Gross: $" << e.calculateGross() << endl;
                    if (choice == 3) e.display();
                    if (choice == 4) {
                        cout << "New Name & Salary: ";
                        cin >> name >> sal;
                        e.setName(name); e.setSalary(sal);
                    }
                }
            }
        }
    }
    return 0;
}