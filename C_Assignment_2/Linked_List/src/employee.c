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


void input_employee_information(Employee **employee, int number)
{
    int i;
    for (i = 0; i < number; i++)
    {
        int id, salary;
        char fullname[50], department[50], start_date[50];
        printf("-------------------------------\n");
        printf("Employee %d:\n", i+1);
        printf("ID: ");
        scanf("%d", &id);
        getchar();

        printf("Fullname: ");
        fgets(fullname, sizeof(fullname), stdin);
        fullname[strcspn(fullname, "\n")] = '\0';

        printf("Department: ");
        fgets(department, sizeof(department), stdin);
        department[strcspn(department, "\n")] = '\0';

        printf("Salary: ");
        scanf("%d", &salary);
        getchar();

        printf("Start date: ");
        fgets(start_date, sizeof(start_date), stdin);
        start_date[strcspn(start_date, "\n")] = '\0';
        input_new_employee(employee, id, fullname, department, salary, start_date);
    }
}
void show_employee(Employee *employee)
{
    while(employee != NULL)
    {
        printf("ID: %d\n", employee->id);
        printf("Fullname: %s\n", employee->fullname);
        printf("Department: %s\n", employee->department);
        printf("Salary: %d\n", employee->salary);
        printf("Start date: %s\n", employee->start_date);
        employee = employee->next;
    }
}
void sort_employ_salary_ascending(Employee **head, Employee *unsorted_node)
{
    if (*head == NULL || unsorted_node->salary <= (*head)->salary)
    {
        unsorted_node->next = *head;
        *head = unsorted_node; 
    }
    else
    {
        Employee *current_sorted_node = *head;
        while (current_sorted_node->next != NULL && current_sorted_node->next->salary < unsorted_node->salary)
        {
            current_sorted_node = current_sorted_node->next;
        }
        unsorted_node->next = current_sorted_node->next;
        current_sorted_node->next = unsorted_node;
    }
}
void sort_employ_salary_descending(Employee **head, Employee *unsorted_node)
{
    if (*head == NULL || unsorted_node->salary >= (*head)->salary)
    {
        unsorted_node->next = *head;
        *head = unsorted_node; 
    }
    else
    {
        Employee *current_sorted_node = *head;
        while (current_sorted_node->next != NULL && current_sorted_node->next->salary > unsorted_node->salary)
        {
            current_sorted_node = current_sorted_node->next;
        }
        unsorted_node->next = current_sorted_node->next;
        current_sorted_node->next = unsorted_node;
    }
}
void sort_employee_fullname(Employee **head, Employee *unsorted_node)
{
    if (unsorted_node == NULL)
    {
        return;
    }
    if (*head == NULL || strcmp(unsorted_node->fullname, (*head)->fullname) <= 0)
    {
        unsorted_node->next = *head;
        *head = unsorted_node;
    }
    else
    {
        Employee *current_sorted_node = *head;
        while (current_sorted_node->next != NULL && strcmp(current_sorted_node->next->fullname, unsorted_node->fullname) > 0)
        {
            current_sorted_node = current_sorted_node->next;
        }
        unsorted_node->next = current_sorted_node->next;
        current_sorted_node->next = unsorted_node;
    }
}
void insert_sort(Employee **head)
{
    Employee *sorted_employ;
    Employee *current;
    int choice;
    while(true)
    {
        printf("\nEnter your sorting choice:\n");
        printf("1. Sort employee ascendingly\n");
        printf("2. Sort employee descendingly\n");
        printf("3. Sort employee by fullname\n");
        printf("0. Exit\n");
        printf("Your choice:");
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
                sort_employ_salary_ascending(&sorted_employ, current);
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
                sort_employ_salary_descending(&sorted_employ, current);
                current = next;
            }
            *head = sorted_employ; 
            printf("------SORT SALARY OF EMPLOYEES DESCENDINGLY------\n");
            show_employee(sorted_employ);
            break;
        case 3:
            sorted_employ = NULL;
            current = *head;
            while (current != NULL)
            {
                Employee *next = current->next;
                current->next = NULL;
                sort_employee_fullname(&sorted_employ, current);
                current = next;
            }
            *head = sorted_employ; 
            printf("------SORT EMPLOYEES BY FULLNAME (A->Z)------\n");
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
void insert_at_head(Employee **head, Employee *new_employee)
{
    input_employee_information(&new_employee, 1);
    new_employee->next = *head;
    *head = new_employee;
}
void insert_at_tail(Employee **head, Employee *new_employee)
{
    Employee *current = *head;
    input_employee_information(&new_employee, 1);
    if(*head == NULL)
    {
        new_employee->next = NULL;
        *head = new_employee;
        return;
    }
    while (current->next != NULL)
    {
        current = current->next;
    }
    new_employee->next = NULL;
    current->next = new_employee;
}
void insert_at_any_position(Employee **head, Employee *new_employee)
{
    Employee *current = *head;
    int index, count;
    count = 1;
    input_employee_information(&new_employee, 1);
    printf("Type position you want to add:");
    scanf("%d", &index);
    if (*head == NULL || index == 1)
    {
        new_employee->next = NULL;
        *head = new_employee;
    }
    if (index < 1)
    {
        printf("Cannot find position to add\n");
        return;
    }
    while (current->next != NULL && count < index - 1)
    {
        current = current->next;
        count++;
    }
    if (count = index - 1)
    {
        new_employee->next = current->next;
        current->next = new_employee;
    }
    else
    {
        printf("Cannot find position to add");
    }
}
void insert_new_employee(Employee *head)
{
    int choice, number;
    while(true)
    {
        Employee *new_employee = (Employee *)malloc(sizeof(Employee));
        if (new_employee == NULL)
        {
            return;
        }
        printf("\nEnter your inserting choice:\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert at any position\n");
        printf("0. Exit\n");
        printf("Your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert_at_head(&head, new_employee);
            printf("\n-----LIST AFTER INSERTING AT HEAD-----\n");
            show_employee(head);
            break;
        case 2:
            insert_at_tail(&head, new_employee);
            printf("\n-----LIST AFTER INSERTING AT TAIL-----\n");
            show_employee(head);
            break;
        case 3:
            insert_at_any_position(&head, new_employee);
            printf("\n-----LIST AFTER INSERTING AT SPECIFIC POSITION-----\n");           
            show_employee(head);
            break;
        case 0:
            free(new_employee);
            return;
            break;
        default:
            break;
        }
    }
}
