#include "employee.h"

int main()
{
    Employee *head = NULL;
    int number;
    printf("Enter number of employees: ");
    scanf("%d", &number);
    input_people(head, number);
    show_employee(head);
    return 0;
}