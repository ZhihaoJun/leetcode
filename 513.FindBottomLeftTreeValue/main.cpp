#include <iostream>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int findBottomLeftValue(TreeNode *root) {
        this->maxDepth = -1;
        inorder(root, 0);
        return node->val;
    }

private:
    void inorder(TreeNode *root, int depth) {
        if (NULL == root) {
            return;
        }
        inorder(root->left, depth+1);
        if (depth > maxDepth) {
            maxDepth = depth;
            node = root;
        }
        inorder(root->right, depth+1);
    }

    int maxDepth;
    TreeNode *node;
};

int main() {
    TreeNode *root = new TreeNode(1);
    TreeNode *n1 = new TreeNode(2);
    TreeNode *n2 = new TreeNode(3);
    TreeNode *n3 = new TreeNode(4);
    TreeNode *n4 = new TreeNode(5);
    TreeNode *n5 = new TreeNode(6);
    TreeNode *n6 = new TreeNode(7);

    root->left = n1;
    root->right = n2;
    n1->left = n3;
    n2->left = n4;
    n2->right = n5;
    n4->left = n6;

    Solution s;

    cout << s.findBottomLeftValue(root) << endl;

    return 0;
}
