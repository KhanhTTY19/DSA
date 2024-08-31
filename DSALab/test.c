/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
 
int sum = 0;
bool ans = false;
bool hasPathSum(struct TreeNode* root, int targetSum) {
    if (root == NULL) {printf("ans = %d", ans); return ans;}
                                printf("sum = %d\n", sum);
    sum += root -> val; 
                                printf("sum = %d\n", sum);
                                printf("root.val = %d ", root -> val);
    hasPathSum(root -> left, targetSum);
    hasPathSum(root -> right, targetSum);
    if (root -> left == NULL && root -> right == NULL) {
        printf("%d ans = %d\n", sum, ans);
        if (targetSum == sum)
            ans = true;
            
    }
    printf("sum = %d, ans = %d\n", sum, ans);
    sum -= root -> val;
    return ans;
}

int main()
{
    int a[] = {5,4,8,11,NULL,13,4,7,2,NULL,NULL,NULL,1};
    struct TreeNode b[10];
    int i;
    for (i = 0; i < 13; i++)
}