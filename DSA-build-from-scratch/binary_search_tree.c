#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int key;
    struct TreeNode *left, *right, *parent;
} TreeNode;

TreeNode createNode(int v)
{
    TreeNode *p = (TreeNode*) malloc (sizeof(TreeNode));
    p ->key = v;
    p->left = NULL;
    p->right = NULL;
    p->parent = NULL;
}

TreeNode* search(int target, TreeNode* root)
{
    if (root == NULL) return;
    if (target == root->key) return root;
    if (target < root->key) search(target, root->left);
    if (target > root->key) search(target, root->right);
}

TreeNode* find_min(TreeNode* root)
{
    if (root != NULL) while (root->left != NULL)
    {
        root = root->left;
    }
    return root;    
}

TreeNode* find_max(TreeNode *root)
{
    if (root != NULL) while (root->right != NULL)
    {
        root = root->right;
    }
    return root;    
}