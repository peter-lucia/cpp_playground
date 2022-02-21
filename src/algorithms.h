//
// Created by Peter Lucia on 2/20/22.
//

#ifndef MYPROJECT_ALGORITHMS_H
#define MYPROJECT_ALGORITHMS_H
#include <algorithm>

using std::min;
using std::max;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void dfs(TreeNode *root, int depth, int &max_depth) {

    if (root == nullptr)
        return;

    if (root->left != nullptr)
        dfs(root->left, 1 + depth, max_depth);
    if (root->right != nullptr)
        dfs(root->right, 1 + depth, max_depth);
    if (root->left == nullptr and root->right == nullptr) {
        max_depth = max(max_depth, depth);
    }


}

int maxDepth(TreeNode* root) {
    int result = 0;
    dfs(root, 1, result);
    return result;
}

#endif //MYPROJECT_ALGORITHMS_H
