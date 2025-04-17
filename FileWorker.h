#ifndef FILEWORKER_H
#define FILEWORKER_H

#include <iostream>
#include <string>

using namespace std;

struct Employee;

inline Employee* head = NULL;
inline Employee* tail = NULL;

inline string FILE_NAME = "JSON_JSON_Employees.txt";
inline char SEPARATOR = ':';
const string NEW_NAME_KEY = "name";
const string NEW_AGE_KEY = "age";

void AddEmployee(Employee* employee, const string &nameEmp, int ageEmp);

void DeleteAllEmployees();

void PrintListAllEmployeeDontParsing(Employee* employee);

void DeleteEmployee(Employee* employee, int choiceDelEmp);

void PrintParsingEmployee(const Employee &emp);

void ShowLastEmployee(Employee* emp);

void ShowAllEmployee(Employee* emp);

void DeleteAllEmployees(Employee* employee);

void SaveToFile(Employee* employee);

void LoadFromFile(Employee* employee);
#endif //FILEWORKER_H
