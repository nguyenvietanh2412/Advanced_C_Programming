#include "employee.h"

int main()
{
    Employee *head = NULL;
    int number;
    printf("Enter number of employees: ");
    scanf("%d", &number);
    input_people(&head, number);
    printf("Original employee list:\n");
    show_employee(head);
    insert_sort(&head);
    return 0;
}
