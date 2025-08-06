
void  reverse(struct TreeNode* node, int *soma) {

    if (node == NULL) {
        return;
    }

    reverse(node->right, soma);

    *soma += node->val;
    node->val = *soma;

    reverse(node->left, soma);

}

struct TreeNode* convertBST(struct TreeNode* root) {
    int  somar = 0;

    reverse(root, &somar);

    return root;
}
