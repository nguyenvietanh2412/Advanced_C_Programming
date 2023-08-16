#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "employee.h"



void input_new_employee(Employee **head, int id, const char *fullname, const char *department, int salary, const char *start_date)
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
    new_employee->next = *head;
    *head = new_employee;
}


void input_people(Employee **employee, int number)
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
void sort_employ_ascending(Employee **head, Employee *unsorted_node)
{
    if (*head == NULL || unsorted_node->salary <= (*head)->salary)
    {
        unsorted_node->next = *head;
        *head = unsorted_node; 
    }
    else
    {
        Employee *current_sorted = *head;
        while (current_sorted->next != NULL && current_sorted->next->salary < unsorted_node->salary)
        {
            current_sorted = current_sorted->next;
        }
        unsorted_node->next = current_sorted->next;
        current_sorted->next = unsorted_node;
    }
}
void sort_employ_descending(Employee **head, Employee *unsorted_node)
{
    if (*head == NULL || unsorted_node->salary >= (*head)->salary)
    {
        unsorted_node->next = *head;
        *head = unsorted_node; 
    }
    else
    {
        Employee *current_sorted = *head;
        while (current_sorted->next != NULL && current_sorted->next->salary > unsorted_node->salary)
        {
            current_sorted = current_sorted->next;
        }
        unsorted_node->next = current_sorted->next;
        current_sorted->next = unsorted_node;
    }
}
void insert_sort(Employee **head)
{
    Employee *sorted_employ;
    Employee *current;
    int choice;
    while(true)
    {
        printf("Enter your choice:\n1. Sort employee ascending\n2. Sort employee descending\n0. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            sorted_employ = NULL;
            current = *head;
            while (current != NULL)
            {
                Employee *next = current->next;
                current->next = NULL;
                sort_employ_ascending(&sorted_employ, current);
                current = next;
            }
            *head = sorted_employ; 
            printf("------SORT SALARY OF EMPLOYEES ASCENDINGLY------\n");
            show_employee(sorted_employ);
            break;
        case 2:
            sorted_employ = NULL;
            current = *head;
            while (current != NULL)
            {
                Employee *next = current->next;
                current->next = NULL;
                sort_employ_descending(&sorted_employ, current);
                current = next;
            }
            *head = sorted_employ; 
            printf("------SORT SALARY OF EMPLOYEES DESCENDINGLY------\n");
            show_employee(sorted_employ);
            break;
        case 0:   
            return;
            break;
        default:
            break;
        }
    }
    
}
