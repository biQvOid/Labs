int nodes_count(struct TreeNode* root)
{
    if (root != NULL) {
        return nodes_count(root->left) + nodes_count(root->right) + 1;
    }
    return 0;
}

void traversal(struct TreeNode* root, int* ans, int* size)
{
    if (root != NULL) {
        if (root->left != NULL) {
            traversal(root->left, ans, size);
        }
        ans[(*size)++] = root->val;
        if (root->right != NULL) {
            traversal(root->right, ans, size);
        }
    }
}

int* inorderTraversal(struct TreeNode* root, int* returnSize){
    *returnSize = 0;
    int h = 0;
    int size = nodes_count(root);
    int* ans = (int*)malloc(sizeof(int) * size);
    traversal(root, ans, returnSize);
    return ans;
}
