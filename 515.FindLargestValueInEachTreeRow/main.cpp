#include <iostream>
#include <vector>

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
    vector<int> largestValues(TreeNode* root) {
        preorder(root, 0);
        return maxs;
    }

private:
    void preorder(TreeNode *root, int depth) {
        if (NULL == root) {
            return;
        }
        if (depth >= maxs.size()) {
            maxs.resize(depth+1);
            maxs[depth] = root->val;
        } else {
            if (root->val > maxs[depth]) {
                maxs[depth] = root->val;
            }
        }
        preorder(root->left, depth+1);
        preorder(root->right, depth+1);
    }

    vector<int> maxs;
};

int main() {
    TreeNode *root = new TreeNode(1);
    TreeNode *n1 = new TreeNode(2);
    TreeNode *n2 = new TreeNode(3);
    TreeNode *n3 = new TreeNode(4);
    TreeNode *n4 = new TreeNode(5);
    TreeNode *n5 = new TreeNode(6);
    TreeNode *n6 = new TreeNode(7);

    // root->left = n1;
    // root->right = n2;
    n1->left = n3;
    n2->left = n4;
    n2->right = n5;
    n4->left = n6;

    Solution s;

    for (auto i : s.largestValues(root)) {
        cout << i << endl;
    }

    return 0;
}
