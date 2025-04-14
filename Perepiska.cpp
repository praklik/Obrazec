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

void PrintListAllEmployeeDontParsing(Employee* employee) {
    if (head == NULL) {
        cout << "Список сотрудников пуст." << endl;
        return;
    }

    cout << "Список сотрудников:" << endl;
    int index = 1;
    Employee* current = head;
    while (current != NULL) {
        cout << index++ << ". Имя: " << current->name << ", возраст: " << current->age << "." << endl;
        current = current->next;
    }
}

void DeleteEmployee(Employee* employee, int choiceDelEmp) {
    if (head == NULL) {
        cout << "Список сотрудников пуст." << endl;
        return;
    }

    Employee* current = head;
    int index = 1;
    while (current != NULL) {
        index++;
        current = current->next;
    }

    if (choiceDelEmp < 1 || choiceDelEmp > index - 1) {
        cout << "Неверный номер сотрудника" << endl;
        return;
    }

    current = head;
    for (int i = 1; i < choiceDelEmp; i++) {
        current = current->next;
    }

    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        head = current->next;
    }

    if (current->next != NULL) {
        current->next->prev = current->prev;
    } else {
        tail = current->prev;
    }

    delete current;

    cout << "Сотрудник успешно удален." << endl;
}

void PrintParsingEmployee(const Employee emp) {
    cout << "--------------------------" << endl;
    cout << "Имя: " << emp.name << "." << endl;
    cout << "Возраст: " << emp.age << "." << endl;
    cout << "--------------------------" << endl;
}

void ShowLastEmployee(Employee* emp) {
    if (tail == NULL) {
        cout << "Список сотрудников пуст." << endl;
        return;
    }

    cout << "Последний сотрудник списка: " << endl;
    PrintParsingEmployee(*tail);
}

void ShowAllEmployee(Employee* emp) {
    if (tail == NULL) {
        cout << "Список сотрудников пуст." << endl;
        return;
    }

    cout << "Список всех сотрудников: " << endl;
    Employee* current = head;
    while (current != NULL) {
        PrintParsingEmployee(*current);
        current = current->next;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    system("color 2");

    Employee Employee;

    srand(time(0));

    string nameEmp;
    int ageEmp;
    int choiceDelEmployee;

    int choice;
    do {
        cout << "Меню управления сотрудниками:" << endl;
        cout << "1. Добавить сотрудника" << endl;
        cout << "2. Удалить сотрудника" << endl;
        cout << "3. Показать последнего сотрудника" << endl;
        cout << "4. Показать всех сотрудников" << endl;
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

            case 2:
                system("cls");
            PrintListAllEmployeeDontParsing(&Employee);
            cout << "Выберите номер сотрудника для удаления: ";
            cin >> choiceDelEmployee;
            DeleteEmployee(&Employee, choiceDelEmployee);
            break;

            case 3:
                system("cls");
            ShowLastEmployee(&Employee);
            break;

            case 4:
                system("cls");
            ShowAllEmployee(&Employee);
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