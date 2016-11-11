#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
  void travel(TreeNode *root, map<TreeNode*, int>* node2id, vector<TreeNode*>* id2node) {
    if (root == NULL) {
      return;
    }
    travel(root->left, node2id, id2node);
    int id = id2node->size();
    (*node2id)[root] = id;
    id2node->insert(id2node->end(), root);
    travel(root->right, node2id, id2node);
  }

  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    if (root == NULL) {
      return "";
    }
    // 1,2,5 0:1,2;1:,;2:,
    map<TreeNode*, int>* node2id = new map<TreeNode*, int>;
    vector<TreeNode*>* id2node = new vector<TreeNode*>;
    stringstream ss;

    travel(root, node2id, id2node);

    // first part
    for (auto it = id2node->cbegin(); it != id2node->cend(); it ++) {
      ss << (*it)->val;
      if (it != id2node->cend()-1) {
        ss << ',';
      }
    }
    ss << ' ';
    
    // second part
    for (auto it = id2node->cbegin(); it != id2node->cend(); it ++) {
      ss << it - id2node->cbegin();
      ss << ':';
      if ((*it)->left != NULL) {
        ss << (*node2id)[(*it)->left];
      } else {
        ss << -1;
      }
      ss << ',';
      if ((*it)->right != NULL) {
        ss << (*node2id)[(*it)->right];
      } else {
        ss << -1;
      }
      if (it != id2node->cend()-1) {
        ss << ';';
      }
    }

    // third part set root
    ss << ' ' << node2id->at(root);
    return ss.str();
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    if (data.length() == 0) {
      return NULL;
    }
    // 1,2,5 0:1,2;1:,;2:,
    stringstream ss;
    vector<TreeNode*>* id2node = new vector<TreeNode*>;
    char c = 0;
    int id = 0, val = 0;

    ss.str(data);

    // first part
    while (1) {
      ss >> val;

      // handle
      id2node->insert(id2node->end(), new TreeNode(val));

      if (ss.peek() == ',') {
        ss.ignore();
      }
      if (ss.peek() == ' ') {
        break;
      }
      id ++;
    }
    ss.ignore();

    // second part
    int idl, idr;
    while (1) {
      ss >> id;
      if (ss.peek() == ':') {
        ss.ignore();
      }
      ss >> idl;
      if (ss.peek() == ',') {
        ss.ignore();
      }
      ss >> idr;
      
      // handle
      if (idl != -1) {
        (id2node->at(id))->left = id2node->at(idl);
      }
      if (idr != -1) {
        (id2node->at(id))->right = id2node->at(idr);
      }

      if (ss.peek() == ';') {
        ss.ignore();
      }
      if (ss.peek() == ' ') {
        break;
      }
    }

    // read root
    ss >> id;

    return id2node->at(id);
  }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main() {
  TreeNode* root = new TreeNode(10);
  TreeNode* n1 = new TreeNode(5);
  TreeNode* n2 = new TreeNode(12);
  root->left = n1;
  root->right = n2;
  Codec codec;
  cout << "final " << codec.serialize(codec.deserialize(codec.serialize(root))) << endl;
  cout << "final " << codec.serialize(codec.deserialize(codec.serialize(NULL))) << endl;
}
