#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class PreorderIterator {
public:
    vector<TreeNode*> stack;

    PreorderIterator(TreeNode* root) {
        if (root != NULL) {
            stack.push_back(root);
        }
    }

    bool hasNext() {
        return !stack.empty();
    }

    int next() {
        TreeNode* ret = stack.back();
        stack.pop_back();
        if (ret->right != NULL) {
            stack.push_back(ret->right);
        }
        if (ret->left != NULL) {
            stack.push_back(ret->left);
        }
        return ret->val;
    }
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        PreorderIterator i = PreorderIterator(root);
        vector<int> v = vector<int>();
        while (i.hasNext()) {
            v.push_back(i.next());
        }
        return v;
    }
};

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    vector<int> v = Solution().preorderTraversal(root);
    for (int i=0; i<v.size(); i++) {
        cout << v.at(i) << " ";
    }
    return 0;
}
