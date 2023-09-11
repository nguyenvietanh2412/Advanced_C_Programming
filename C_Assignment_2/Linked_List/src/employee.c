#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "employee.h"

/* FUNCTION=================================================================

 *  Function Name: check_id

 *  Description: Prompt the user to input a valid employee ID.

 ==========================================================================*/
int check_id() 
{
    int id;
    printf("ID: ");

    // Loop until a valid positive integer input is provided
    while (scanf("%d", &id) != 1 || id < 0) 
    {
        printf("Invalid input. Enter again:\nID:");
        while (getchar() != '\n');
    }
    getchar();
    return id;
}
/* FUNCTION=================================================================

 *  Function Name: check_duplicate_id.

 *  Description: Check if id already existed.

 ==========================================================================*/
int check_duplicate_id(employee_t *head, int id)
{
    employee_t *current = head;

    // Loop until reaching the end of the list
    while (current != NULL)
    {
        if (current->emp.id == id)
        {
            return 1;
        }
        current = current->next;
    }
    return 0;
}
/* FUNCTION=================================================================

 *  Function Name: check_salary

 *  Description: Prompt the user to input a valid employee salary.

 ==========================================================================*/
int check_salary()
{
    int salary;
    printf("Salary: ");

    // Loop until a valid positive integer input is provided
    while (scanf("%d", &salary) != 1 || salary < 0)
    {
        printf("Invalid input. Enter again:\nSalary:");
        while (getchar() != '\n');
    }
    getchar();
    return salary;
}
/* FUNCTION=================================================================

 *  Function Name: is_alphabet_character

 *  Description: Check if the provided string consists of only alphabet characters and spaces.

 *  Parameters:
 *      - fullname: The string to be checked.

 ==========================================================================*/
bool is_alphabet_character(char *fullname) 
{
    int i;
    bool is_no_space = false;

    for (i = 0; fullname[i] != '\0'; i++) 
    {
        // Check if the character is not an alphabet character and not a space
        if (!isalpha(fullname[i]) && !isspace(fullname[i])) 
        {
            // Return false if any non-alphabet non-space character is found
            return false;
        }
        
        // Check if the character is not a space
        if (!isspace(fullname[i])) 
        {
            is_no_space = true;
        }
    }

    // Return true if at least one non-space alphabet character is found
    return is_no_space; 
}

/* FUNCTION=================================================================

 *  Function Name: check_fullname

 *  Description: Prompt the user to input a valid employee full name.

 *  Parameters:
 *      - fullname: Pointer to the character array to store the employee full name.

 ==========================================================================*/
void check_fullname(char *fullname) 
{
    printf("Fullname:");
    fgets(fullname, 50, stdin);

    // Remove the trailing newline character from the input
    fullname[strcspn(fullname, "\n")] = '\0';

    // Loop until a valid full name is provided (consists of alphabet characters and at least one non-space character)
    while (strlen(fullname) == 0 || is_alphabet_character(fullname) == false) 
    {
        printf("Invalid fullname. Enter again:\nFullname:");
        fgets(fullname, 50, stdin);

        // Remove the trailing newline character from the input
        fullname[strcspn(fullname, "\n")] = '\0';
    }
}

/* FUNCTION=================================================================

 *  Function Name: is_character_or_integer

 *  Description: Check if the provided string consists of only alphabet characters and/or digits.

 *  Parameters:
 *      - department: The string to be checked.

 *  Returns:
 *      - bool: True if the string contains only alphabet characters and/or digits, otherwise false.

 ==========================================================================*/
bool is_character_or_integer(char *department) {
    int i;
    for (i = 0; department[i] != '\0'; i++) 
    {
       
        // Check if the character is neither an alphabet character nor a digit
        if (!isalnum(department[i]) && !isalpha(department[i])) 
        {

            return false; // Return false if any character is not an alphabet character or digit
        }
    }
    return true; // Return true if all characters are either alphabet characters or digits
}

/* FUNCTION=================================================================

 *  Function Name: check_department

 *  Description: Prompt the user to input a valid department name.

 *  Parameters:
 *      - department: Pointer to the character array to store the department name.

 ==========================================================================*/
void check_department(char *department) {
    printf("Department:");
    fgets(department, 50, stdin);

    // Remove the trailing newline character from the input
    department[strcspn(department, "\n")] = '\0';

    // Loop until a valid department name is provided (consists of alphabet characters and/or digits)
    while (strlen(department) == 0 || is_character_or_integer(department) == false) 
    {
        printf("Invalid department. Enter again:\nDepartment:");
        fgets(department, 50, stdin);

        // Remove the trailing newline character from the input
        department[strcspn(department, "\n")] = '\0';
    }
}
/* FUNCTION=================================================================

 *  Function Name: input_new_employee

 *  Description: Add information of a new employee to the list.

 *  Parameters:
 *      - head: Pointer to the head of the employee list.
 *      - id: employee_t ID.
 *      - fullname: Full name of the employee.
 *      - department: Department of the employee.
 *      - salary: Salary of the employee.
 *      - start_date: Start date of employment.

 ==========================================================================*/
void input_new_employee(employee_t **head, int id, const char *fullname, const char *department, int salary, const char *start_date) 
{
    employee_t *new_employee = (employee_t *)malloc(sizeof(employee_t));
    if (new_employee == NULL) 
    {
        return;
    }

    new_employee->emp.id = id;
    new_employee->emp.salary = salary;
    strcpy(new_employee->emp.fullname, fullname);
    strcpy(new_employee->emp.department, department);
    strcpy(new_employee->emp.start_date, start_date);
    new_employee->next = *head;
    *head = new_employee;
}
/* FUNCTION=================================================================

 *  Function Name: input_employee_information

 *  Description: Input information for multiple employees and add them to the employee list.

 *  Parameters:
 *      - employee: Pointer to the pointer of the employee list.
 *      - number: Number of employees to be input.

 ==========================================================================*/
void input_employee_information(employee_t **employee, int number)
{
    int i;
    for (i = 0; i < number; i++)
    {
        int id, salary;
        char fullname[50], department[50], start_date[50];
        printf("-------------------------------\n");
        printf("Employee %d:\n", i+1);
        id = check_id();
        
        // Check duplicated id before putting into the list
        while (check_duplicate_id(*employee, id))
        {
            printf ("ID already exists. Enter again:\n");
            id = check_id();
        }

        check_fullname(fullname);
        check_department(department);
        salary = check_salary();

        printf("Start date: ");
        fgets(start_date, sizeof(start_date), stdin);
        start_date[strcspn(start_date, "\n")] = '\0';

        // Add the new employee to the employee list
        input_new_employee(employee, id, fullname, department, salary, start_date);
    }
}
/* FUNCTION=================================================================

 *  Function Name: show_employee

 *  Description: Display the details of all employees in the list.

 *  Parameters:
 *      - employee: Pointer to the head of the employee list.

 ==========================================================================*/
void show_employee(employee_t *employee)
{
    while(employee != NULL)
    {
        printf("ID: %d\n", employee->emp.id);
        printf("Fullname: %s\n", employee->emp.fullname);
        printf("Department: %s\n", employee->emp.department);
        printf("Salary: %d\n", employee->emp.salary);
        printf("Start date: %s\n\n", employee->emp.start_date);
        employee = employee->next;
    }
}
/* FUNCTION=================================================================

 *  Function Name: sort_employ_salary_ascending

 *  Description: Insert an employee node into the employee list in ascending order of salary.

 *  Parameters:
 *      - head: Pointer to the pointer of the head of the employee list.
 *      - unsorted_node: Pointer to the employee node to be inserted.

 ==========================================================================*/
void sort_employ_salary_ascending(employee_t **head, employee_t *unsorted_node) 
{
    if (*head == NULL || unsorted_node->emp.salary <= (*head)->emp.salary) 
    {
        // Insert the unsorted_node at the beginning of the list
        unsorted_node->next = *head;
        *head = unsorted_node;
    } 
    else 
    {
        employee_t *current_sorted_node = *head;

        // Traverse the sorted list to find the appropriate position for insertion
        while (current_sorted_node->next != NULL && current_sorted_node->next->emp.salary < unsorted_node->emp.salary) 
        {
            current_sorted_node = current_sorted_node->next;
        }

        // Insert the unsorted_node into the sorted list
        unsorted_node->next = current_sorted_node->next;
        current_sorted_node->next = unsorted_node;
    }
}

/* FUNCTION=================================================================

 *  Function Name: sort_employ_salary_descending

 *  Description: Insert an employee node into the employee list in descending order of salary.

 *  Parameters:
 *      - head: Pointer to the pointer of the head of the employee list.
 *      - unsorted_node: Pointer to the employee node to be inserted.

 ==========================================================================*/
void sort_employ_salary_descending(employee_t **head, employee_t *unsorted_node) 
{
    if (*head == NULL || unsorted_node->emp.salary >= (*head)->emp.salary) 
    {
        // Insert the unsorted_node at the beginning of the list
        unsorted_node->next = *head;
        *head = unsorted_node;
    } 
    else 
    {
        employee_t *current_sorted_node = *head;

        // Traverse the sorted list to find the appropriate position for insertion
        while (current_sorted_node->next != NULL && current_sorted_node->next->emp.salary > unsorted_node->emp.salary) 
        {
            current_sorted_node = current_sorted_node->next;
        }

        // Insert the unsorted_node into the sorted list
        unsorted_node->next = current_sorted_node->next;
        current_sorted_node->next = unsorted_node;
    }
}

/* FUNCTION=================================================================

 *  Function Name: sort_employee_fullname

 *  Description: Insert an employee node into the employee list in ascending order of full name.

 *  Parameters:
 *      - head: Pointer to the pointer of the head of the employee list.
 *      - unsorted_node: Pointer to the employee node to be inserted.

 ==========================================================================*/
void sort_employee_fullname(employee_t **head, employee_t *unsorted_node) 
{
    if (unsorted_node == NULL) 
    {
        return; // Return if the unsorted_node is NULL
    }

    if (*head == NULL || strncmp(unsorted_node->emp.fullname, (*head)->emp.fullname, 50) <= 0) 
    {
        // Insert the unsorted_node at the beginning of the list
        unsorted_node->next = *head;
        *head = unsorted_node;
    } 
    else 
    {
        employee_t *current_sorted_node = *head;

        // Traverse the sorted list to find the appropriate position for insertion
        while (current_sorted_node->next != NULL && strncmp(current_sorted_node->next->emp.fullname, unsorted_node->emp.fullname, 50) > 0) 
        {
            current_sorted_node = current_sorted_node->next;
        }

        // Insert the unsorted_node into the sorted list
        unsorted_node->next = current_sorted_node->next;
        current_sorted_node->next = unsorted_node;
    }
}

/* FUNCTION=================================================================

 *  Function Name: sort_employee_list

 *  Description: Sort the employee list based on the user's sorting choice.

 *  Parameters:
 *      - head: Pointer to the pointer of the head of the employee list.

 ==========================================================================*/
void sort_employee_list(employee_t **head) 
{
    employee_t *sorted_employ;
    employee_t *current;
    int choice;

    while (true) 
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

            // Loop through the employee list and sort by salary ascendingly
            while (current != NULL) 
            {
                employee_t *next = current->next;
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

            // Loop through the employee list and sort by salary descendingly
            while (current != NULL) 
            {
                employee_t *next = current->next;
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

            // Loop through the employee list and sort by fullname
            while (current != NULL) 
            {
                employee_t *next = current->next;
                current->next = NULL;
                sort_employee_fullname(&sorted_employ, current);
                current = next;
            }

            *head = sorted_employ;

            printf("------SORT EMPLOYEES BY FULLNAME (A->Z)------\n");
            show_employee(sorted_employ);
            break;

        case 0:
            return; // Exit the function
            break;

        default:
            break;
        }
    }
}

/* FUNCTION=================================================================

 *  Function Name: insert_at_head

 *  Description: Insert a new employee node at the beginning of the employee list.

 *  Parameters:
 *      - head: Pointer to the pointer of the head of the employee list.
 *      - new_employee: Pointer to the new employee node to be inserted.

 ==========================================================================*/
void insert_at_head(employee_t **head)//, employee_t *new_employee) 
{
    int id;
    id = check_id();
    while (check_duplicate_id(*head, id))
    {
        printf("ID already exists. Enter again.\n");
        id = check_id();
    }
    input_employee_information(head, 1);
    // new_employee->next = *head;
    // *head = new_employee;
}

/* FUNCTION=================================================================

 *  Function Name: insert_at_tail

 *  Description: Insert a new employee node at the end of the employee list.

 *  Parameters:
 *      - head: Pointer to the pointer of the head of the employee list.
 *      - new_employee: Pointer to the new employee node to be inserted.

 ==========================================================================*/
void insert_at_tail(employee_t **head, employee_t *new_employee)
{
    int id;
    id = check_id();
    while (check_duplicate_id(*head, id))
    {
        printf("ID already exists. Enter again.\n");
        id = check_id();
    }
    // Input information for the new employee
    input_employee_information(&new_employee, 1);

    // If the list is empty, set the new employee as the head
    if (*head == NULL)
    {
        new_employee->next = NULL;
        *head = new_employee;
        return;
    }

    // Traverse to the end of the list
    employee_t *current = *head;
    while (current->next != NULL)
    {
        current = current->next;
    }

    // Insert the new employee at the end
    new_employee->next = NULL;
    current->next = new_employee;
}
/* FUNCTION=================================================================

 *  Function Name: insert_at_any_position

 *  Description: Insert a new employee node at a specific position in the employee list.

 *  Parameters:
 *      - head: Pointer to the pointer of the head of the employee list.
 *      - new_employee: Pointer to the new employee node to be inserted.

 ==========================================================================*/
void insert_at_any_position(employee_t **head, employee_t *new_employee)
{
    // Initialize variables
    employee_t *current = *head;
    int index, count, id;
    count = 1;
    id = check_id();
    while (check_duplicate_id(*head, id))
    {
        printf("ID already exists. Enter again.\n");
        id = check_id();
    }
    // Input information for the new employee
    input_employee_information(&new_employee, 1);

    // Get the position to insert the new employee
    printf("Type position you want to add:");
    scanf("%d", &index);

    // If the list is empty or index is 1, insert at the beginning
    if (*head == NULL || index == 1)
    {
        new_employee->next = NULL;
        *head = new_employee;
    }

    // Check if the provided index is invalid
    if (index < 1)
    {
        printf("Cannot find position to add\n");
        return;
    }

    // Traverse to the desired position
    while (current->next != NULL && count < index - 1)
    {
        current = current->next;
        count++;
    }

    // Insert the new employee at the specified position
    if (count == index - 1)
    {
        new_employee->next = current->next;
        current->next = new_employee;
    }
    else
    {
        printf("Cannot find position to add");
    }
}

/* FUNCTION=================================================================

 *  Function Name: insert_new_employee

 *  Description: Insert new employees at different positions in the employee list based on user's choice.

 *  Parameters:
 *      - head: Pointer to the pointer of the head of the employee list.

 ==========================================================================*/
void insert_new_employee(employee_t **head)
{
    // Initialize variables
    int choice, number;

    // Loop to continuously insert new employees
    while (true)
    {
        // Allocate memory for the new employee
        employee_t *new_employee = (employee_t *)malloc(sizeof(employee_t));
        if (new_employee == NULL)
        {
            return; // Memory allocation failed
        }

        // User's choice for insertion
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
            // Insert at the beginning
            insert_at_head(head);//, new_employee);
            printf("\n-----LIST AFTER INSERTING AT HEAD-----\n");
            show_employee(*head);
            break;

        case 2:
            // Insert at the end
            insert_at_tail(head, new_employee);
            printf("\n-----LIST AFTER INSERTING AT TAIL-----\n");
            show_employee(*head);
            break;

        case 3:
            // Insert at any position
            insert_at_any_position(head, new_employee);
            printf("\n-----LIST AFTER INSERTING AT SPECIFIC POSITION-----\n");
            show_employee(*head);
            break;

        case 0:
            // Free memory and exit
            free(new_employee);
            return;
            break;

        default:
            break;
        }
    }
}
