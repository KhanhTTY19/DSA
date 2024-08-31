#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int value;
    struct Node* next;
} Node;

void printlist();
Node* makenode(int);
Node* insertFirst(int);
Node* findLastNode();
Node* insertLast(int);
Node* findPreNode(Node*);
Node* insertBeforeNode(Node*, int);
Node* reverse();
Node* h;
int size = 0;


int main()
{
    h = (Node*) malloc(sizeof(Node));
    h = NULL;
    int j;
    //scanf("%d", &j);
    //makenote(3);
    printlist();
    //printf("\n");
    insertFirst(1);
    insertFirst(2);
    insertLast(3);
    reverse();
    //insertBeforeNode(1, 4);
    printlist();
}

void printlist() 
{
    Node* p = h;
    if (p == NULL) {
        printf("empty\n");
        return;
    }
    while(p != NULL) {
        printf("%d", p->value);
        p = p->next;
    }
}

Node* makenode(int v)
{
    Node* p = (Node*) malloc(sizeof(Node));
    p->value = v;
    p->next = NULL;
    return p;
}

Node* insertFirst(int v)
{
    Node* new_node = makenode(v);
    if (h == NULL) {
        h = new_node;
        return new_node;
    }
    new_node->next = h;
    h = new_node;
    return h;
}

Node* findLastNode()
{
    Node* p = h;
    while (p != NULL)
    {
        if (p->next == NULL) return p;
        p = p->next;
    }
    return p;
}

Node* insertLast(int v)
{
    Node* p = makenode(v);
    if (h == NULL) {
        h == p;
        return p;
    }
    Node* near_last_node = findLastNode();
    near_last_node->next = p;
    return p;
}

Node* findPreNode(Node* p) 
{
    Node* q = h;
    while(q != NULL) {
        if (q->next == p) return q;
        q = q->next;
    }
    return NULL;
}

Node* insertBeforeNode(Node* p, int v)
{
    Node* pp = findPreNode(p);
    if (pp == NULL && p != NULL) return h;
    Node* q = makenode(v);
    if (pp == NULL) {
        if (h == NULL) 
            return q;
        q->next = h;
        return q;
    }
    q->next = p;
    pp->next = q;
    return h;
}

Node* findDelNode(Node* X)
{
    Node* p = h;
    while (p != NULL)
    {
        if (p->next == X) return p;
        p = p->next;
    }
    return NULL;
}

Node* deleteNode(Node* X)
{
    if (h == NULL) return h;
    else {
        Node* p = findDelNode(X);
        free(X);    
        p->next = p->next->next;
    }
}

Node* reverse() 
{
    Node* cur = h, *next, *pre;
    pre = NULL;
    next = NULL;
    while (cur != NULL)
    {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    h = pre;
    return h;
}