#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Structure representing data of an employee
typedef struct data
{
    int id;
    int salary;
    char fullname[50];
    char department[50];
    char start_date[50];
} data_t;
// Structure representing an employee
typedef struct employee
{
    // int id, salary;
    // char fullname[50], department[50], start_date[50];
    struct data emp;
    struct employee *next;
} employee_t;
/**
 * Check if a date prompted from keyboard is valid or not
 * 
 * @param start_date The starting date of employees.
 */
int is_valid_date(char *start_date);
/**
 * Check if an id is duplicated
 * 
 * @param head List of employees.
 * @param id Employee ID.
 */
int check_duplicate_id(employee_t *head, int id);
/**
 * Prompt user to input id from keyboard
 * 
 */
int check_id();
/**
 * Add information of a new employee to the list.
 * 
 * @param head List of employees.
 * @param id Employee ID.
 * @param fullname Full name.
 * @param department Department.
 * @param salary Salary.
 * @param start_date Start date of employment.
 */
void input_new_employee(employee_t **head, int id, const char *fullname, const char *department, int salary, const char *start_date);

/**
 * Input information of multiple employees.
 * 
 * @param employee List of employees.
 * @param number Number of employees to input information for.
 */
void input_employee_information(employee_t **employee, int number);

/**
 * Display information of an employee.
 * 
 * @param employee Employee to be displayed.
 */
void show_employee(employee_t *employee);

/**
 * Insert a new employee into the list.
 * 
 * @param head List of employees.
 */
void insert_new_employee(employee_t **head);

/**
 * Sort the list of employees.
 * 
 * @param head List of employees.
 */
void sort_employee_list(employee_t **head);
void deleteList(employee_t** head);
#endif // EMPLOYEE_H_
