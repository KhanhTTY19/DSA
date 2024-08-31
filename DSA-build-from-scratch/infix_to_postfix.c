#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 100

typedef struct Stack {
    char val;
    struct Stack *next;
    struct Stack *left;
    struct Stack *right;
} Stack;

Stack* MakeNode(char v)
{
    Stack* p = (Stack*) malloc(sizeof(Stack));
    p->val = v;
    p->next = NULL;
    return p;
}

Stack* push(Stack* node, char v)
{
    Stack* p = MakeNode(v);
    if (node == NULL) node = p;
    else {
        p->next = node;
        node = p;
    }
    return node;
}

Stack* pop(Stack**node)
{
    if ((*node) == NULL) return NULL;
    Stack* p = (*node);
    *node = (*node)->next;
    return p;
}

Stack* invert(Stack* node)
{
    Stack* p = node, *pre = NULL, *new_stack;
    while (p != NULL)
    {
        new_stack = p->next;
        p->next = pre;
        pre = p;
        p = new_stack;
    }
    return pre;
}

int prior(char c)
{
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

int isOp(char c)
{
    if (c == '^' || c == '+' || c == '-' || c == '*' || c == '/') return 1;
    return 0;
}

void printPrefix(Stack*tree)
{
    Stack* p = tree;
    if (p == NULL) return;
    printf("%c",p->val);
    printPrefix(p->left);
    printPrefix(p->right);
}

int main()
{
    char s[MAXSIZE];
    fgets(s, MAXSIZE, stdin);
    int len = strcspn(s, "\n"), i;
    s[len] = '\0';
    Stack *op, *postfix, *temp;
    op = (Stack*) malloc(sizeof(Stack));
    postfix = (Stack*) malloc(sizeof(Stack));
    temp = (Stack*) malloc(sizeof(Stack));
    // for (i = 0; i <= (len-1)/2; i++) {
    //     // printf("%c ", s[len-1-i]);
    //     // printf("%c ", s[i]);
    //      //char temp = s[i];
    //      //s[i] = s[len - 1 - i];
    //      //printf("%c ", temp);
    //     // s[len - 1 - i] = temp;
    // }
    for (i = 0; i < len; i++) {
        if (s[i] == '(') {
            op = push(op, s[i]);
        }
        else if (isOp(s[i])) {
            while (prior(op->val) > prior(s[i]))
            {
                postfix = push(postfix, op->val);
                temp = pop(&op);
            }
            op = push(op, s[i]);
        }
        else if (s[i] == ')')
        {
            while (op->val != '(')
            {
                postfix = push(postfix, op->val);
                temp = pop(&op);
            }
            temp = pop(&op);     
        }
        else {
            postfix = push(postfix, s[i]);
        }
    }
    while (op != NULL)
    {
        postfix = push(postfix, op->val);
        temp = pop(&op);
    }
    postfix = invert(postfix);
    Stack* root = (Stack*) malloc(sizeof(Stack));
    Stack* lleft = (Stack*) malloc(sizeof(Stack));
    Stack* rright = (Stack*) malloc(sizeof(Stack));
    
    while (postfix->next != NULL )
    {
        if (isOp(postfix->val)) {
            rright = pop(&root);
           // printf("right = %c ", rright->val);
            lleft = pop(&root);
           // printf("left = %c ", lleft->val);
            root = push(root, postfix->val);
            root->left = lleft;
            root->right = rright;
           // printf("root = %c\n", root->val);
        }
        else {
            root = push(root, postfix->val);
            //printf("%c", root->val);
        }
       // printf("postfix = %c\n", postfix->val);
        postfix = postfix->next;
    }
    printPrefix(root);

    return 0;
}