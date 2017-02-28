#include "BinaryTreeNode.h"

#include <iostream>

using namespace std;

BinaryTreeNodeParser::BinaryTreeNodeParser():
    state(READY_STATE),
    stop(false), nodeIndex(0)
{

}

TreeNode *BinaryTreeNodeParser::parse(string s) {
    it = s.begin();
    end = s.end();
    while (it < end) {
        transition(*it);
        it = it + postTransition();
        if (stop) {
            break;
        }
    }
    if (nodes.size() == 0) {
        return nullptr;
    }
    return nodes[0];
}

void BinaryTreeNodeParser::transition(char c) {
    if (c == '[' && READY_STATE == state) {
        state = LEFT_BRACKET_STATE;
    } else if (c >= '0' && c <= '9' && (LEFT_BRACKET_STATE == state || COMMA_STATE == state)) {
        state = INT_DFA_STATE;
    } else if (c == 'n' && (LEFT_BRACKET_STATE == state || COMMA_STATE == state)) {
        state = NULL_DFA_STATE;
    } else if (c == ',' && (INT_DFA_STATE == state || NULL_DFA_STATE == state)) {
        state = COMMA_STATE;
    } else if (c == ']' && INT_DFA_STATE == state) {
        state = RIGHT_BRACKET_STATE;
    }
}

int BinaryTreeNodeParser::postTransition() {
    if (INT_DFA_STATE == state) {
        IntDFA intDFA;
        int i = intDFA.parse(it, end);
        TreeNode *n = new TreeNode(i);
        nodes.resize(nodeIndex+1);
        nodes[nodeIndex] = n;
        if (0 == nodeIndex) {
        } else if (nodeIndex % 2 == 0) {
            nodes[(nodeIndex-1)/2]->right = n;
        } else {
            nodes[(nodeIndex-1)/2]->left = n;
        }
        nodeIndex ++;
        return intDFA.parsedLen();;
    } else if (NULL_DFA_STATE == state) {
        NullDFA nullDFA;
        int success = nullDFA.parse(it, end);
        nodeIndex ++;
        return nullDFA.parsedLen();
    } else if (RIGHT_BRACKET_STATE == state) {
        stop = true;
    }
    return 1;
}

IntDFA::IntDFA():
    len(0)
{

}

int IntDFA::parsedLen() {
    return len;
}

int IntDFA::parse(string::iterator it, string::iterator end) {
    int result = 0;
    while (it != end) {
        if (*it < '0' || *it > '9') {
            break;
        }
        result = result * 10 + (*it - '0');
        it ++;
        len ++;
    }
    return result;
}

NullDFA::NullDFA()
{

}

int NullDFA::parsedLen() {
    return 4;
}

int NullDFA::parse(string::iterator it, string::iterator end) {
    if (*it != 'n') {
        return 0;
    }
    if (*(it+1) != 'u') {
        return 0;
    }
    if (*(it+2) != 'l') {
        return 0;
    }
    if (*(it+3) != 'l') {
        return 0;
    }
    return 1;
}
