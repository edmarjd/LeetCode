/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int max (int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
} 

struct TreeNode *newNode (int val) {
    struct TreeNode *p = (struct TreeNode*) malloc (sizeof(struct TreeNode));
    p->val = val;
    p->left = NULL;
    p->right = NULL;
    return p;
}
int Altura (struct TreeNode *p) {

    if (p == NULL) {
        return 0;
    } else {
       int  a = Altura(p->left);
       int  b = Altura(p->right);
       return max(a, b) + 1;
    }
} 

int getBalnce (struct TreeNode *p) {
    if (p == NULL) {
        return 0;
    } else {
       return Altura(p->left) - Altura(p->right);
    }
}


bool isBalanced(struct TreeNode* root) {
    if (root == NULL) {
        return true;
    }

    int FB = getBalnce(root);

    if (abs(FB) > 1) {
        return false;
    }


    bool left_balance = isBalanced(root->left);
    bool right_balance = isBalanced(root->right);

    return left_balance && right_balance;
}
