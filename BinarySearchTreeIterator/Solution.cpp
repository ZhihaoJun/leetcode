/*
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.
 */
#include <iostream>
#include <vector>

using namespace std;

// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
public:
    vector<TreeNode*> stack;

    BSTIterator(TreeNode *root) {
        TreeNode* node = root;
        while (node != NULL) {
            this->stack.push_back(node);
            node = node->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !this->stack.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* top = this->stack.back();
        TreeNode* node = top->right;
        this->stack.pop_back();
        while (node != NULL) {
            this->stack.push_back(node);
            node = node->left;
        }
        return top->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

int main(void) {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right = new TreeNode(5);
    BSTIterator i = BSTIterator(root);
    while (i.hasNext()) cout << i.next();
    return 0;
}
