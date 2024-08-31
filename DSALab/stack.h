typedef struct stack {
    char val;
    struct stack *next;
} stack;

void printStack(stack *head);
stack *makeNewStack(char v);
stack *push(stack *head, char v);
stack *pop(stack *head);


void printStack(stack *head)
{
    stack *p = head;
    while (p != NULL)
    {
        printf("%c ", (p -> val));
        p = p -> next;
    }
    printf("\n");
}

stack* makeNewStack(char v)
{
    stack *s = (stack*) malloc(sizeof(stack));
    s -> val = v;
    s -> next = NULL;
    return s;
}

stack* push(stack *head, char v)
{
    if (head == NULL) {
        head = makeNewStack(v);
    }
    else {
        stack *p = makeNewStack(v);
        p -> next = head;
        head = p;
    }
    return head;
}

stack *pop(stack *head)
{
    if (head != NULL) {
        stack *p = head;
        head = head -> next;
        free(p);
    }
    return head;

}