#include <conio.h>
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

struct Employee {
    string name;
    int age;

    Employee* next;
    Employee* prev;
};

Employee* head = NULL;
Employee* tail = NULL;

void AddEmployee(Employee* employee, string nameEmp, int ageEmp) {
    Employee* newEmployee = new Employee;

    newEmployee->name = nameEmp;
    newEmployee->age = ageEmp;

    newEmployee->next = NULL;
    newEmployee->prev = tail;

    if (tail != NULL) {
        tail->next = newEmployee;
    } else {
        head = newEmployee;
    }

    tail = newEmployee;

    cout << "Новый сотрудник успешно добавлен." << endl;
}

void DeleteAllEmployees() {
    Employee* current = head;
    while (current != NULL) {
        Employee* next = current->next;
        delete current;
        current = next;
    }
    head = NULL;
    tail = NULL;
}


int main() {
    setlocale(LC_ALL, "Russian");
    system("color 2");

    Employee Employee;

    srand(time(0));

    string nameEmp;
    int ageEmp;

    int choice;
    do {
        cout << "Меню управления сотрудниками:" << endl;
        cout << "1. Добавить сотрудника" << endl;
        cout << "0. Выход" << endl;
        cout << "Выберите действие: ";

        if (!(cin >> choice)) {
            cin.clear();
            choice = -1;
        }

        cin.ignore();

        switch (choice) {
            case 1:
                system("cls");
            cout << "Добавление нового сотрудника:\n" << endl;
            cout << "Введите имя нового сотрудника: ";
            getline(cin, nameEmp);
            cout << "Введите возраст нового сотрудника: ";
            cin >> ageEmp;
            AddEmployee(&Employee, nameEmp, ageEmp);
            break;

            case 0:
                DeleteAllEmployees();
            cout << "Программа завершена.\n";
            break;
            default: cout << "Неверный ввод. Повторите попытку снова." << endl;
        }
        if (choice != 0) {
            cout << "\nНажмите Enter для продолжения..." << endl;
            // ВНИМАНИЕ!!!
            // Если программа запускается в Clion, тогда _getch(); - нужно убирать для корректной работы
            // Если в MS Visual Studio - необходимо оставить
            //_getch();
            system("cls");
        }
    } while (choice != 0);

    return 0;
}