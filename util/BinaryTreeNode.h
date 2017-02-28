#ifndef BINARY_TREE_NODE_H
#define BINARY_TREE_NODE_H

#include <string>
#include <vector>

const int READY_STATE = 0;
const int LEFT_BRACKET_STATE = 1;
const int RIGHT_BRACKET_STATE = 2;
const int INT_DFA_STATE = 3;
const int NULL_DFA_STATE = 4;
const int COMMA_STATE = 5;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class IntDFA {
public:
    IntDFA();

    int parse(std::string::iterator it, std::string::iterator end);
    int parsedLen();

private:
    int len;
};

class NullDFA {
public:
    NullDFA();

    int parse(std::string::iterator it, std::string::iterator end);
    int parsedLen();
};

class BinaryTreeNodeParser {
public:
    BinaryTreeNodeParser();

    TreeNode *parse(std::string s);

private:
    void transition(char c);
    int postTransition();

    std::vector<TreeNode *> nodes;
    std::string::iterator it;
    std::string::iterator end;
    int state;
    int nodeIndex;
    bool stop;
};

#endif
