#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *next;
} Node;

int numofnode = 0;

Node* makeNode(int v)
{
    Node* p = (Node*) malloc(sizeof(Node));
    p->val = v;
    numofnode++;
    p->next = NULL;
    return p;
}

Node* pushVal(Node* h, int v)
{
    Node* p = makeNode(v);
    p->next = h;
    return p;
}

Node* popVal(Node* h)
{
    if (h == NULL) return NULL;
    else {
        numofnode--;
        Node* p = h;
        h = h->next;
        free(p);
        return h;
    }
}

Node* tailList(Node* h)
{
    Node* p = h;
    // while (p ->next != NULL)
    // {
    //     printf("%d ", p->val);
    //     p = p->next;
    // }
    // printf("\n");
    // while (h != NULL)
    // {
    //     printf("%d ", h->val);
    //     h = h->next;
    // }
    

Node* reverse = NULL;
        Node* prev = NULL;
        Node* cpy_head = h;
        int sze = 0;

        while(h != NULL) {
            sze++;
            reverse = h;
            h = h->next;
            reverse->next = prev;
            prev = reverse;
        }
        
        while(cpy_head != NULL) {printf("%d ",cpy_head->val); cpy_head = cpy_head -> next;}


    return p;
}

void goToHead(Node* h, Node* p)
{
    Node* q = h;
    while (q -> next != p)
    {
        q = q->next;
    }
    q->next = p->next;
    p->next = h;
    h = p;
}

void sortList(Node* h, Node* tail)
{
    Node *p = h->next, *pre_p = h; int i = 1;
    //Node *tail = tailList(h);
    while (i <= numofnode)
    {
        if (p->val > h->val)  {
            tail->next = p;
            pre_p->next = p->next;
            p->next = NULL;
            tail = p;
            p = pre_p->next;
           
        } else {
            p = p->next;
            pre_p = pre_p -> next;}
        i++;
    }
    
}

int main()
{
    Node *h = (Node*) malloc(sizeof(Node));
    h = NULL;
    h = pushVal(h, 2);
    h = pushVal(h, 5);
    h = pushVal(h, 8);
    h = pushVal(h, 10);
    h = pushVal(h, 1);
    h = pushVal(h, 3);
    h = pushVal(h, 7);
    h = pushVal(h, 9);
    h = pushVal(h, 5);
    Node* t = tailList(h);
    // printf("%d %d\n", numofnode, tailList(h)->val);
    // sortList(h, tailList(h));
    // while (h != NULL)
    // {
    //     printf("%d ", h->val);
    //     h = h->next;
    // }
}
