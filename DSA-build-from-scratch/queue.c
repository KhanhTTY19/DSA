#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
    struct queue *head, *tail;
};

typedef struct NodeQueue
{
    char val;
    struct NodeQueue *next;
} NodeQueue;

FILE* out;
int openfile = 0;
NodeQueue *head = NULL, *tail = NULL;

NodeQueue* makeNewNode(char v)
{
    NodeQueue* p = (NodeQueue*) malloc(sizeof(NodeQueue));
    p -> val = v;
    p -> next = NULL;
    return p;
}

NodeQueue* enqueue(char v)
{
    NodeQueue* p = makeNewNode(v);
    if (head == NULL) {
        head = p;
        head -> next = tail;
    }
    else if (tail == NULL)
    {
        tail = p;
        head -> next = tail;
    }
    else if (tail -> val) tail -> next = p;
    return head;
}

NodeQueue* dequeue(NodeQueue* head)
{
    if (head == NULL || tail == NULL) return head;
    else {
        NodeQueue *p = head;
        head = head -> next;
        free(p);
        return head;
    }
}

void printAllNode(NodeQueue *had)
{
    if (openfile == 0){
        out = fopen("out.txt", "w");
        openfile = 1;
    }
    NodeQueue* p = had;
    while (p != NULL)
    {
        fprintf(out,"%c ", p -> val);
        p = p -> next;
    }
    fprintf(out, "\n");
}