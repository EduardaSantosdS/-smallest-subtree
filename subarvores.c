#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

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

void freeTree(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    // Exemplo 1
    struct TreeNode *root = newNode(3);
    root->left = newNode(5);
    root->right = newNode(1);
    root->left->left = newNode(6);
    root->left->right = newNode(2);
    root->right->left = newNode(0);
    root->right->right = newNode(8);
    root->left->right->left = newNode(7);
    root->left->right->right = newNode(4);

    struct TreeNode *result = subtreeWithAllDeepest(root);
    printf("Exemplo 1 Output: %d\n", result->val);  // Deve imprimir 2

    freeTree(root);  // Libera a memória da árvore do Exemplo 1

    // Exemplo 2
    struct TreeNode *root2 = newNode(1);

    struct TreeNode *result2 = subtreeWithAllDeepest(root2);
    printf("Exemplo 2 Output: %d\n", result2->val);  // Deve imprimir 1

    freeTree(root2);  // Libera a memória da árvore do Exemplo 2

    // Exemplo 3
    struct TreeNode *root3 = newNode(0);
    root3->left = newNode(1);
    root3->right = newNode(3);
    root3->left->right = newNode(2);

    struct TreeNode *result3 = subtreeWithAllDeepest(root3);
    printf("Exemplo 3 Output: %d\n", result3->val);  // Deve imprimir 2

    freeTree(root3);  // Libera a memória da árvore do Exemplo 3

    return 0;
}
