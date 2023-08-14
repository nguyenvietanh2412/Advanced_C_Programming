#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct employee
{
    int id, salary;
    char fullname[50], department[50], start_date[50];
    struct employee *next;
} Employee;

void input_new_employee(Employee *head, int id, const char *fullname, const char *department, int salary, const char *start_date);
void input_people(Employee *employee, int number);
void show_employee(Employee *employee);