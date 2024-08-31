#include <stdio.h>
#include <stdlib.h>

typedef struct NodeBinaryTree
{
    int val;
    struct NodeBinaryTree *left;
    struct NodeBinaryTree *right;
}NodeBinaryTree;

NodeBinaryTree* root;
int num_node = 0;

NodeBinaryTree* makeNode(int v)
{
    NodeBinaryTree* p = (NodeBinaryTree*) malloc(sizeof(NodeBinaryTree));
    p->val = v;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void preOrder(NodeBinaryTree* r)
{
    NodeBinaryTree* p = r;
    if (p != NULL){
        printf("%d ", p->val);
        preOrder(p->left);
        preOrder(p->right);
    }
}

void postOrder(NodeBinaryTree* r) 
{
    NodeBinaryTree* p = r;
    if (p == NULL)return; else{
        postOrder(p->left);
        postOrder(p->right);
        printf("%d ", p->val);
    }
}

void inOrder(NodeBinaryTree* r) 
{
    NodeBinaryTree* p = r;
    if (p == NULL) return;
    inOrder(p->left);
    printf("%d ", p-> val);
    inOrder(p->right);  
}


NodeBinaryTree* insertNode(NodeBinaryTree* r, int v)
{
    NodeBinaryTree* p = r; 
    if (p == NULL) {
        return makeNode(v);
    }
    else if(p->left == NULL) {
        p->left = makeNode(v);
    }
    else if (p->right == NULL)
    {
        p->right = makeNode(v);
    }
    else{
        if(p->left != NULL) p->left = insertNode(p->left, v);
        else if(p->right != NULL) p->right = insertNode(p->right, v);
    }
    num_node++;
    return r;
}

void listTree(NodeBinaryTree* r)
{
    NodeBinaryTree* p = r;
    if (p == NULL) return;
    else {
        printf("%d ", p->val);
        listTree(p->left);
        listTree(p->right);
    }
}