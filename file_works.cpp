/*************************
* Автор: Сатин В.С.      *
* Дата: 22.10.2024       *
* Название: Вариант№8    *
*************************/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <format>
using namespace std;

class Employee {
public:
    string department;
    string surname;
    string name;
    string patronymic;
    string phone;
    
    Employee(const string& dept, const string& sur, const string& nam,
    const string& patron, const string& ph): 
    department(dept), surname(sur), name(nam), patronymic(patron), phone(ph) {}
};

void readDirectory(const string& filename, vector<Employee>& employees) {
    ifstream path(filename);
    if (!path.is_open()) {
        cerr << "Не удалось открыть файл." << endl;
        return;
    }
    
    string dept, sur, num, patron, ph;
    while (path >> dept >> sur >> num >> patron >> ph) {
        employees.emplace_back(dept, sur, num, patron, ph);
    }
    
    path.close();
}

void printDepartmentNumbers(const string& department, 
    const vector<Employee> employees) {
    int count = 0;
    for (const auto& emp : employees) {
        if (emp.department == department) {
            cout << emp.surname << " " << emp.name << " " 
            << emp.patronymic << ": " << emp.phone << endl;
            count++;
        }
    }
    
    if (count == 0) {
        cout << "Нет данных для подразделения: " << department << endl;
    } 
    else {
        cout << format("Количество номеров в подразделении {}: {}", department,
        count) << endl;
    } 
}

int main() {
    setlocale(LC_ALL, "russian");
    
    vector<Employee> employees;
    string filename = "telephone_directory.txt";
    
    // Чтение данных из файла
    readDirectory(filename, employees);
    
    // Ввод нужно подразделения
    string department;
    cout << "Введите название подразделения: ";
    cin >> department;
    
    // Вывод номеров и подсчет количества
    printDepartmentNumbers(department, employees);
    
    return 0;
}