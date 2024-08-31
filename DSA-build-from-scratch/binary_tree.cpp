#include <iostream>
#include <stdlib.h>
#include <queue>

using namespace std;

typedef struct Node
{
    int val;
    struct Node *left;
    struct Node *right;
}Node;
queue <int> q;
Node* root;

Node* makeNode(int v)
{
    Node* p = (Node*) malloc(sizeof(Node));
    p->val = v;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void insertNode(Node* r, int v)
{
    Node* p = r; 
    if (q.size() == 0) {
        q.push(v);
    } else {
        int n = 1, i = 0;
        while (n * 2 < q.size())
        {
            n *= 2;
            i++;
        }
        
    }
}

void listTree(Node* r)
{
    Node* p = r;
    if (p == NULL) return;
    else {
        printf("%d ", p->val);
        listTree(p->left);
        listTree(p->right);
    }
}