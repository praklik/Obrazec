#include <conio.h>
#include <iostream>
#include <string>
#include <fstream>
#include "FileWorker.h"

using namespace std;

struct Employee {
    string name;
    int age;

    Employee* next;
    Employee* prev;
};

int main() {
    setlocale(LC_ALL, "Russian");
    system("color 2");

    Employee Employee;

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
        cout << "5. Сохранить сотрудников в файл" << endl;
        cout << "6. Загрузить сотрудников из файла" << endl;
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

            case 5:
                system("cls");
                SaveToFile(&Employee);
            break;

            case 6:
                system("cls");
            LoadFromFile(&Employee);
            break;

            case 0:
                DeleteAllEmployees();
                cout << "Программа завершена." << endl;
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