#include "employee.h"

int main()
{
    Employee *head = NULL;
    int number;
    printf("Enter number of employees: ");
    scanf("%d", &number);
    input_people(&head, number);
    printf("\n-----Display employees information-----\n");
    show_employee(head);
    
    printf("Sorted list via salary:\n");
    insert_sort(&head);
    show_employee(head);
    return 0;
}