#include <iostream>
#include <vector>
#include <map>

using namespace std;

class LinkedNode {
public:
    LinkedNode(int val): val(val), next(NULL) {}

    int val;
    LinkedNode *next;
};

void printNode(LinkedNode *n) {
    while (n != NULL) {
        cout << n->val << " ";
        n = n->next;
    }
    cout << endl;
}

void printInts(const vector<int> &ints) {
    for (auto i : ints) {
        cout << i << " ";
    }
    cout << endl;
}

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        buildGraph(wordList);
        return findShortestPath(mapping[beginWord], mapping[endWord])+1;
    }

private:
    void buildGraph(const vector<string> &words) {
        // fill base nodes
        vector<string>::size_type i = 0;
        vector<string>::size_type j = 0;
        graph.resize(words.size());

        for (i=0; i<words.size(); ++i) {
            LinkedNode *n = new LinkedNode(i);
            mapping[words[i]] = i;
            graph[i] = n;
        }
        for (i=0; i<words.size(); ++i) {
            for (j=0; j<i; ++j) {
                if (distance(words[i], words[j]) == 1) {
                    // add to graph
                    LinkedNode *n1 = new LinkedNode(j);
                    n1->next = graph[i]->next;
                    graph[i]->next = n1;

                    LinkedNode *n2 = new LinkedNode(i);
                    n2->next = graph[j]->next;
                    graph[j]->next = n2;
                }
            }
        }
    }

    int distance(const string &a, const string &b) {
        int count = 0;
        for (string::size_type i=0; i<a.length(); i++) {
            if (a[i] != b[i]) {
                ++count;
            }
        }
        return count;
    }

    int findShortestPath(int start, int end) {
        vector<LinkedNode *>::size_type i = 0;
        vector<LinkedNode *>::size_type j = 0;
        vector<int>::size_type k = 0;
        vector<int>::size_type minIdx = 0;

        dj.resize(graph.size());
        for (i=0; i<graph.size(); ++i) {
            dj[i] = -1;
            visited[i] = false;
        }
        dj[start] = 0;
        LinkedNode *n = NULL;

        for (i=0; i<graph.size(); ++i) {
            minIdx = -1;
            for (j=0; j<graph.size(); ++j) {
                if (visited[j]) {
                    continue;
                }

                if ( (-1 == minIdx || dj[j] < dj[minIdx]) && dj[j] != -1) {
                    minIdx = j;
                }
            }

            visited[minIdx] = true;
            n = graph[minIdx];
            while (n != NULL) {
                if (dj[n->val] == -1 || dj[minIdx] < dj[n->val] - 1) {
                    dj[n->val] = dj[minIdx] + 1;
                }
                n = n->next;
            }
        }

        return dj[end];
    }

    map<string, int> mapping;
    vector<LinkedNode*> graph;
    vector<int> dj;
    map<int, bool> visited;
};

int main() {
    Solution s;
    string beginWord = "hot";
    string endWord = "dog";
    vector<string> vec = {"hot","dog"};
    cout << s.ladderLength(beginWord, endWord, vec) << endl;
    return 0;
}
