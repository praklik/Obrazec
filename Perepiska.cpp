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

int main() {
    setlocale(LC_ALL, "Russian");
    system("color 2");

    return 0;
}