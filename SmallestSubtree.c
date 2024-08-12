struct Result {
    struct TreeNode *node;
    int depth;
};

struct Result dfs(struct TreeNode *root) {
    if (root == NULL) {
        return (struct Result){NULL, 0};
    }

    struct Result left = dfs(root->left);
    struct Result right = dfs(root->right);

    if (left.depth > right.depth) {
        return (struct Result){left.node, left.depth + 1};
    }

    if (right.depth > left.depth) {
        return (struct Result){right.node, right.depth + 1};
    }

    return (struct Result){root, left.depth + 1};
}

struct TreeNode* subtreeWithAllDeepest(struct TreeNode* root) {
    return dfs(root).node;
}

struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}