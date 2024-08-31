#include <stdio.h>
#include <stdlib.h>



typedef struct Node
{
    char val;
    struct Node *next;
} Node;
Node* makeNewNode(char v);
Node* head = NULL;
FILE* out;
int openfile = 0;

Node* makeNewNode(char v)
{
    Node* p = (Node*) malloc(sizeof(Node));
    p -> val = v;
    p -> next = NULL;
    return p;
}

Node* push(char v)
{
    Node* p = makeNewNode(v);
    if (head == NULL) {
        head = p;
    }
    else{
        p -> next = head;
        head = p;
    }    
    return head;
}

Node* pop(Node *head)
{
    if (head == NULL) return head;
    else {
        Node* p = head;
        head = head -> next;
        //fprintf(out, "_%c_", head -> val);
        //fprintf(out, "_%c_", head -> next -> val);
        free(p);
        return head;
    }
}

void printAllStack(Node *had)
{
    if (openfile == 0){
        out = fopen("out.txt", "w");
        openfile = 1;
    }
    Node* p = had;
    while (p != NULL)
    {
        fprintf(out,"%c ", p -> val);
        p = p -> next;
    }
    fprintf(out, "\n");
}