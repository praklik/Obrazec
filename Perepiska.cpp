#include <conio.h>
#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

// Структура для хранения данных о сотруднике
struct Employee {
    string name;        // Имя сотрудника
    int age;            // Возраст сотрудника

    Employee* next;     // Указатель на следующего сотрудника
    Employee* prev;     // Указатель на предыдущего сотрудника
};

// Глобальные переменные
Employee* head = NULL;  // Указатель на начало списка
Employee* tail = NULL;  // Указатель на конец списка

// Функция добавления нового сотрудника
void AddEmployee(Employee* employee) {
    // Создаём нового сотрудника "newEmployee"
    Employee* newEmployee = new Employee;

    // Заполняем данные о сотруднике
    cout << "Добавление нового сотрудника:\n" << endl;
    cout << "Введите имя нового сотрудника: ";
    // Используем функцию "getline" для того что бы можно было использовать пробел
    getline(cin, newEmployee->name);
    cout << "Введите возраст нового сотрудника: ";
    // Используем "cin" так как нам нужно только 1 число
    cin >> newEmployee->age;

    // Устанавливаем новые указатели
    newEmployee->next = NULL;   // Указатель на следующего сотрудника указывает на конец списка
    newEmployee->prev = tail;   // Указывает на предыдущего сотрудника указывает на
}

int main() {
    setlocale(LC_ALL, "Russian");
    system("color 2");



    return 0;
}