#include "employee.h"
#include <stdbool.h>
int main()
{
    Employee *head = NULL;
    int number, option;
    while(true)
    {
        printf("WHAT YOU WANT?\n");
        printf("1. Input a number of employees\n");
        printf("2. Insert new employee\n");
        printf("3. Sort employee list\n");
        printf("0. Exit\n");
        printf("Type your option:");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("Enter number of employees: ");
            scanf("%d", &number);
            input_employee_information(&head, number);
            printf("\n-----ORIGINAL EMPLOYEE LIST-----\n");
            show_employee(head);
            break;
        case 2:
            insert_new_employee(head);
            break;
        case 3:
            insert_sort(&head);
            break;
        case 0:
            return 0;
            break;
        default:
            break;
        }
    }
    return 0;
}