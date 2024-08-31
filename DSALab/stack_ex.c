#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#define MAXSIZE 1000

char s[MAXSIZE];
int main()
{
    //FILE* inp;
    //inp = fopen("stack_ex.txt", "r");
    //fgets(s, MAXSIZE, inp);
    scanf("%s", s);
    int len = strlen(s);
    s[len] = '\0';
    stack *head = (stack*) malloc(sizeof(stack));
    for (int i = 0; i < len; i++) {
        if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
            if (head ->next == NULL) {
                printf("0");
                return 0;
            }
            else if (s[i] == ')' && head -> val == '(') {
                head = pop(head);
            }
            else if (s[i] == ']'&& head -> val == '[') {
                head = pop(head);
            }
            else if (s[i] == '}' && head -> val == '{') {
                head = pop(head);
            }
        }
        else {
                head = push(head, s[i]);
        }

    }
    if (head -> next == NULL) printf("1");
    else printf("0");
    return 0;
}