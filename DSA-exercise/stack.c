#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

stack *head;

int main()
{
    head = push(head, 1);
    printStack(head);
    head = push(head, 2);
    printStack(head);
    head = pop(head);
    printStack(head);
}

