#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char val;
    struct Node *next;
}Node;

Node* MakeNode(char v)
{
    Node *p = (Node*) malloc(sizeof(Node));
    p->val = v;
    p->next = NULL;
    return p;
}

int prior(char c)
{
    if (c == '^') return 2;
    if (c == '*' || c == '/') return 1;
    else if (c == '+' || c == '-') return 0;
    return -1;
}

void push(Node** n, char v)
{
    Node *p = MakeNode(v);
    if (*n == NULL) *n = p;
    else {
        p->next = *n;
        *n = p;
    }
}
 
void pop(Node** n)
{
    Node* p = *n;
    if (*n != NULL) {
        *n = (*n)->next;
        free(p);
    }
}

Node* invert(Node** n)
{
    Node *p = (*n), *pre = NULL, *newl;
    while ((p) != NULL)
    {
        newl = p->next;
        p->next = pre;
        pre = p;
        p = newl;
    }
    return pre;
}

int is_op(char c)
{
    if (c == '^' || c == '+' || c == '-' || c == '*' || c == '/') return 1;
    else return 0;
}

int main()
{
    int i;
    char s[50];
    Node* opertor, *number, *infix;
    opertor = (Node*) malloc(sizeof(Node));
    number = (Node*) malloc(sizeof(Node));
    infix = (Node*) malloc(sizeof(Node));
    scanf("%s", s);
    //printf("1");
    int len = strcspn(s, "\n");
    for (i = 0; i < len; i++) {
        //printf("%d", i);
        if (s[i] == '(') 
        {
            push(&opertor, s[i]); 
            // //printf("1");
        }
        else if (is_op(s[i])) {
            //printf("2");
            while (prior(s[i]) < prior(opertor->val)) {
                push(&infix, opertor->val);
                pop(&opertor);    
            }
            push(&opertor, s[i]);
        }
        else if (s[i] == ')') {
            while( (number != NULL) && (opertor->val != '(')) {
                push(&infix, opertor->val);
                pop(&opertor);
            }
            pop(&opertor);
        }
        else {
            push(&infix, s[i]);
        }
    }
    
    
    while (prior(opertor->val)>0)
    {
        push(&infix, opertor->val);
        pop(&opertor);
    }
    infix = invert(&infix);
    opertor = invert(&opertor);
    
     while (infix != NULL)
    {
        printf("%c", infix->val);
        infix = infix->next;
    }
    while (opertor != NULL)
    {
        printf("%c", opertor->val);
        pop(&opertor);
    }
}   