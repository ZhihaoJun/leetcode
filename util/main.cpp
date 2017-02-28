#include <iostream>
#include "BinaryTreeNode.h"

using namespace std;

void inorder(TreeNode *root) {
    if (nullptr == root) {
        return;
    }
    inorder(root->left);
    cout << root->val << endl;
    inorder(root->right);
}

int main() {
    string s("[1,2,30,null,4]");
    BinaryTreeNodeParser parser;
    TreeNode *root = parser.parse(s);
    inorder(root);
    return 0;
}
