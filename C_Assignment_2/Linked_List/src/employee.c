#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employee.h"


// void input_new_employee(Employee *head, int id, const char *fullname, const char *department, int salary, const char *start_date)
// {
//     Employee *new_employee = (Employee*)malloc(sizeof(Employee));
//     strcpy(new_employee->fullname, fullname);
//     strcpy(new_employee->department, department);
//     strcpy(new_employee->start_date, start_date);
//     new_employee->id = id;
//     new_employee->fullname = fullname;
//     new_employee->department = department;
//     new_employee->salary = salary;
//     new_employee->start_date = start_date;
//     head = new_employee;
// }

void input_new_employee(Employee *head, int id, const char *fullname, const char *department, int salary, const char *start_date)
{
    Employee *new_employee = (Employee*)malloc(sizeof(Employee));
    if (new_employee == NULL) {
        return;
    }

    new_employee->id = id;
    new_employee->salary = salary;
    strcpy(new_employee->fullname, fullname);
    strcpy(new_employee->department, department);
    strcpy(new_employee->start_date, start_date);
    new_employee->next = head;
    head = new_employee;
}


void input_people(Employee *employee, int number)
{
    int i;
    for (i = 0; i < number; i++)
    {
        int id, salary;
        char fullname[50], department[50], start_date[50];

        printf("Employee %d:\n", i+1);
        printf("ID: ");
        scanf("%d", &id);
        getchar();

        printf("Fullname: ");
        fgets(fullname, sizeof(fullname), stdin);

        printf("Department: ");
        fgets(department, sizeof(department), stdin);

        printf("Salary: ");
        scanf("%d", &salary);
        getchar();

        printf("Start date: ");
        fgets(start_date, sizeof(start_date), stdin);

        input_new_employee(employee, id, fullname, department, salary, start_date);
    }
}
void show_employee(Employee *employee)
{
    printf("\n-----Display employees information-----\n");
    while(employee != NULL)
    {
        printf("ID: %d\n", employee->id);
        printf("Fullname: %s", employee->fullname);
        printf("Department: %s", employee->department);
        printf("Salary: %d\n", employee->salary);
        printf("Start date: %s\n", employee->start_date);
        employee = employee->next;
    }
}