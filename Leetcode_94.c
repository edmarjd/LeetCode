/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

<<<<<<< HEAD
void inorder (struct TreeNode* root, int* result , int* index) {
    if (root == NULL) {
        return;
    }

    inorder(root->left , result, index);
    result[(*index)++] = root->val;
    inorder(root->right , result , index);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    
    int *result = (int *) malloc(1000 * sizeof(int));
    int index = 0;

    inorder(root, result, &index);
    *returnSize = index;

    return result;
}
=======
void inorder (struct TreeNode* root, int* result , int* index) {
    if (root == NULL) {
        return;
    }

    inorder(root->left , result, index);
    result[(*index)++] = root->val;
    inorder(root->right , result , index);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    
    int *result = (int *) malloc(1000 * sizeof(int));
    int index = 0;

    inorder(root, result, &index);
    *returnSize = index;

    return result;
}

>>>>>>> a0003d77640a23a69b34d7f1a187ca697f1c0a8d