#include "binary_tree.c"

int main()
{
    root = insertNode(root, 1);listTree(root); printf("\n");
    root = insertNode(root, 2);listTree(root);printf("\n");
    root = insertNode(root, 3);listTree(root);printf("\n");
    root = insertNode(root, 4);listTree(root);printf("\n");
    root = insertNode(root, 5);listTree(root);printf("\n");
    root = insertNode(root, 6);listTree(root);printf("\n");
    root = insertNode(root, 7);listTree(root);printf("\n\n");
    root = insertNode(root, 8);inOrder(root);printf("\n\n");
    root = insertNode(root, 9);
    listTree(root);printf("\n");
    printf("%d", root->val);
}