/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */


#define  MAX_LEVEL 200
#define  MAX 2000

void dfs(struct TreeNode *root, int level, int **result , int *returnColumnSizes, int *levelCounts) {
    if (root == NULL) {
        return;
    }   

    if (returnColumnSizes[level] == 0) {
        result[level] = (int *) malloc (MAX_LEVEL * sizeof(int));
    }

    result[level][levelCounts[level]] = root->val;
    levelCounts[level]++;
    returnColumnSizes[level]++;

    dfs(root->left, level + 1, result, returnColumnSizes, levelCounts);
    dfs(root->right, level + 1, result, returnColumnSizes, levelCounts);
} 

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    int **result = (int **) malloc (MAX * sizeof(int*));
    *returnColumnSizes = (int *) calloc( MAX ,sizeof(int));
    int *levelCounts = (int *) calloc( MAX , sizeof(int));

    dfs (root, 0 , result, *returnColumnSizes, levelCounts);

    int levels = 0;
    for (int i = 0 ; i < MAX; i++) {
        if ((*returnColumnSizes)[i] > 0) {
            levels++;
        } else {
            break;
        }
    }

    *returnSize = levels;
    free(levelCounts);
    return result;

}