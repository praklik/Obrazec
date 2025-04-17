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

void AddEmployee(Employee* employee, const string &nameEmp, int ageEmp) {
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

void PrintParsingEmployee(const Employee &emp) {
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

void DeleteAllEmployees(Employee* employee) {
    Employee* current = head;
    while (current != NULL) {
        Employee* next = current->next;
        delete current;
        current = next;
    }

    head = NULL;
    tail = NULL;
}

void SaveToFile(Employee* employee) {
    if (head == nullptr) {
        cout << "Список сотрудников пуст. Нечего сохранять, добавьте сотрудников" << endl;
        return;
    }

    ofstream fout(FILE_NAME);
    if (!fout) {
        cout << "Ошибка при открытии файла для записи." << endl;
        return;
    }

    Employee* current = head;
    bool firstEmployee = true;

    fout << "[\n";
    while (current != NULL) {
        if (!firstEmployee) {
            fout << ";" << endl;
        }
        firstEmployee = false;

        fout << "\t{" << endl;
        fout << "\t\t\"Name\": \"" << current->name << "\", " << endl;
        fout << "\t\t\"Age\": \"" << current->age << "\"" << endl;
        fout << "\t}" << endl;

        current = current->next;
    }

    fout << "]" << endl;
    fout.close();
    cout << "Данные успешно сохранены в файл " << FILE_NAME << "." << endl;
}

void LoadFromFile(Employee* employee) {
    ifstream fin(FILE_NAME);
    if (!(fin.is_open())) {
        cout << "Ошибка открытия файла для чтения или не существует." << endl;
        return;
    }
    DeleteAllEmployees(employee);

    string line;
    Employee* current = NULL;
    bool inEmployee = false;

    while (getline(fin, line)) {
        line.erase(0, line.find_first_not_of(" \t\""));
        size_t endPos = line.find_last_not_of(" \t\",");
        if (endPos != string::npos) {
            line = line.substr(0, endPos + 1);
        }
        if (line.find('{') != string::npos) {
            current = new Employee();
            current->prev = tail;
            current->next = NULL;

            if (tail!=NULL) {
                tail->next = current;
            } else {
                head = current;
            }
            tail =current;
            inEmployee = true;
        }
        else if (line.find('}') != string::npos) {
           inEmployee = false;
        }
        else if (inEmployee && current != NULL) {
            size_t colonPos = line.find(SEPARATOR);
            if (colonPos != string::npos) {
                string key = line.substr(0, colonPos);
                string value = line.substr(colonPos + 1);

                key.erase(0, key.find_first_not_of(" \t\""));
                key.erase(key.find_last_not_of(" \t\"")+1);
                value.erase(0, value.find_first_not_of(" \t\""));
                value.erase(value.find_last_not_of(" \t\"")+1);

                if (key == "Name") {
                    current->name = value;
                }
                else if (key == "Age") {
                    current->age = stoi(value);
                }
            }
        }
    }
    fin.close();
    cout << "Данные успешно загружены из файла: " << FILE_NAME << "." << endl;
}