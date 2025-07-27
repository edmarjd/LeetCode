#define UNCOVERED 0
#define HAS_CAMERA 1
#define COVERED 2

int cameras = 0;

int dfs(struct TreeNode* root) {
    if (root == NULL) return COVERED;

    int left = dfs(root->left);
    int right = dfs(root->right);

    if (left == UNCOVERED || right == UNCOVERED) {
        cameras++;
        return HAS_CAMERA;
    }

    if (left == HAS_CAMERA || right == HAS_CAMERA) {
        return COVERED;
    }

    return UNCOVERED;
}

int minCameraCover(struct TreeNode* root) {
    cameras = 0;
    if (dfs(root) == UNCOVERED) {
        cameras++;
    }
    return cameras;
}
