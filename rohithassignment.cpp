#include <iostream>
// #include <vector>
using namespace std;
#include <ctime>
#include <string>
#include <cmath>
// using namespace std;
#include <random>

string genders_arr[3] = {"male", "female", "others"};
string design_arr[5] = {"Executive", "Manager", "Engineer", "Accountant", "Clerk"};
class Employee
{
public:
    static string dept;

public:
    string empid;
    string name;
    int dob;
    int design;

    int gender;
    float salary;

public:
    void setEmployee(string id, string emp_name, int emp_dob, int emp_design, int emp_gender, float emp_salary)
    {
        empid = id;
        name = emp_name;
        dob = emp_dob;
        design = emp_design;
        gender = emp_gender;
        salary = emp_salary;
    }

    string getName()
    {
        return name;
    }
    // Employee(){
    //     string empid;
    //     string name;
    //     int dob;
    //     int design;

    //     int gender;
    //     float salary;
    // }
};

bool findEmployee(int n, Employee arr[], string name)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i].name == name)
        {
            return true;
        }
    }
    return false;
}

void printNamesWithGivenPrefix(Employee arr[], int n, string prefix)
{
    int k = prefix.length();
    for (int i = 0; i < n; i++)
    {
        if ((arr[i].name).substr(0, k) == prefix)
        {
            cout << arr[i].name << endl;
        }
    }
}

int deleteEmployee(int count, string empid, Employee arr[], int n)
{
    count = count + 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].empid == empid)
        {
            while (i < n)
            {
                arr[i] = arr[i + 1];
                i++;
            }
            break;
        }
    }
    cout << "employee with empid equal to " << empid << "is deleted" << endl;
    return count;
}

void printEmployee(string empid, int n, Employee arr[])
{
    cout << "employee details with empid equal to " << empid << endl;
    for (int i = 0; i < n; i++)
    {

        if (arr[i].empid == empid)
        {
            cout << "id:" << arr[i].empid << " ,"
                 << "name:" << arr[i].name << " ,"
                 << "dob:" << arr[i].dob << " ,"
                 << "designation:" << design_arr[arr[i].design] << " ,"
                 << "gender:" << genders_arr[arr[i].gender] << " ,"
                 << "salary:" << arr[i].salary << endl;
        }
    }
}

void findEmployeeBySalary(float salary, Employee arr[], int n)
{
    cout << "employees with salary equal " << salary << " are:" << endl;
    for (int i = 0; i < n; i++)
    {

        if (arr[i].salary == salary)
        {
            cout << "id:" << arr[i].empid << " ,"
                 << "name:" << arr[i].name << " ,"
                 << "dob:" << arr[i].dob << " ,"
                 << "designation:" << design_arr[arr[i].design] << " ,"
                 << "gender:" << genders_arr[arr[i].gender] << " ,"
                 << "salary:" << arr[i].salary << endl;
        }
    }
}

void findEmployeeBySalary(float min, float max, Employee arr[], int n)
{
    cout << "employees with salary between " << min << " and " << max << " are :" << endl;

    for (int i = 0; i < n; i++)
    {

        if (arr[i].salary > min && arr[i].salary < max)
        {
            cout << "id:" << arr[i].empid << " ,"
                 << "name:" << arr[i].name << " ,"
                 << "dob:" << arr[i].dob << " ,"
                 << "designation:" << design_arr[arr[i].design] << " ,"
                 << "gender:" << genders_arr[arr[i].gender] << " ,"
                 << "salary:" << arr[i].salary << endl;
        }
    }
}

void findEmployeeBySalary(float min, float max, int design, Employee arr[], int n)
{
    cout << "employees with salary between " << min << " and " << max << " and designation is " << design << " are :" << endl;
    for (int i = 0; i < n; i++)
    {

        if (arr[i].salary > min && arr[i].salary < max && arr[i].design == design)
        {
            cout << arr[i].empid << " ," << arr[i].name << " ," << arr[i].dob << " ," << design_arr[arr[i].design] << " ," << genders_arr[arr[i].gender] << " ," << arr[i].salary << endl;
        }
    }
}

int main()
{
    uniform_int_distribution<> p(100, 200);
    uniform_int_distribution<> id1(1000, 9999);
    uniform_int_distribution<> dob(10000000, 99999999);
    uniform_int_distribution<> design(0, 4);
    uniform_int_distribution<> salary(1000000, 9000000);
    uniform_int_distribution<> gender(0, 2);
    mt19937 gen(time(0));
    int n = p(gen);
    cout << "question number 1" << endl;
    Employee arr[200];
    for (int i = 0; i < n; i++)
    {
        string val = to_string(id1(gen));
        string prefix = "BO";

        string id = prefix + val;
        string emp_name = "rohith";
        int emp_dob = dob(gen);
        int emp_design = design(gen);
        int emp_gender = gender(gen);
        float emp_salary = salary(gen);
        arr[i].setEmployee(id, emp_name, emp_dob, emp_design, emp_gender, emp_salary);
    }
    cout << "array of " << n << " employees is created" << endl;
    arr[0].setEmployee("KO2345", "rohijnani", 123456, 1, 1, 57443454);
    int count = 0;
    cout << "question number 2" << endl;
    printNamesWithGivenPrefix(arr, n, "rohijnani");
    cout << findEmployee(n, arr, "jnani");
    cout << "question number 3" << endl;
    findEmployee(n, arr, "rohith");
    printEmployee("KO2345", n, arr);
    count = deleteEmployee(count, "KO2345", arr, n);
    cout << "question number 4" << endl;
    cout << "no.of deletion and insertions are " << count << endl;
    cout << "function overloading begins here" << endl;
    cout << "question number 5" << endl;
    findEmployeeBySalary(57443454, arr, n);
    findEmployeeBySalary(1000000, 2000000, arr, n);
    findEmployeeBySalary(1000000, 2000000, 1, arr, n);

    return 0;
}