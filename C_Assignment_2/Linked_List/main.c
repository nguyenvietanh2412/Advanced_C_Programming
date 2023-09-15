#include "employee.h"
#include <stdbool.h>

int main()
{
    // Initialize the list of employees
    employee_t *head = NULL; 
    int number;
    int option;

    // Infinite loop for menu options
    while(true) 
    {
        // Display menu options
        printf("WHAT YOU WANT?\n");
        printf("1. Input a number of employees\n");
        printf("2. Insert new employee\n");
        printf("3. Sort employee list\n");
        printf("0. Exit\n");
        
        // Get user's choice
        printf("Type your option:");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            // Input employee information
            printf("Enter number of employees: ");
            scanf("%d", &number);
            input_employee_information(&head, number);
            
            // Display the original employee list
            printf("\n-----ORIGINAL EMPLOYEE LIST-----\n");
            show_employee(head);
            break;

        case 2:
            // Insert a new employee into the list
            insert_new_employee(&head);
            break;

        case 3:
            // Sort the employee list
            sort_employee_list(&head);
            break;

        case 0:
            // Exit the program
            return 0; 
            break;

        default:
            break;
        }
    }

    return 0;
}
