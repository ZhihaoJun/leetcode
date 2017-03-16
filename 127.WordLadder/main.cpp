#include <iostream>
#include <vector>
#include <map>

using namespace std;

void printNode(const vector<int> &edges) {
    for (auto n : edges) {
        cout << n << " ";
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
            mapping[words[i]] = i;
        }
        for (i=0; i<words.size(); ++i) {
            for (j=0; j<i; ++j) {
                if (distance(words[i], words[j]) == 1) {
                    // add to graph
                    graph[i].push_back(j);
                    graph[j].push_back(i);
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
        vector< vector<int> >::size_type i = 0;
        vector< vector<int> >::size_type j = 0;
        vector<int>::size_type k = 0;
        vector<int>::size_type minIdx = 0;

        dj.resize(graph.size());
        for (i=0; i<graph.size(); ++i) {
            dj[i] = -1;
            visited[i] = false;
        }
        dj[start] = 0;

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
            const vector<int> &edges = graph[minIdx];
            for (auto n : edges) {
                if (dj[n] == -1 || dj[minIdx] < dj[n] - 1) {
                    dj[n] = dj[minIdx] + 1;
                }
            }
        }

        return dj[end];
    }

    map<string, int> mapping;
    vector< vector<int> > graph;
    vector<int> dj;
    map<int, bool> visited;
};

int main() {
    Solution s;
    string beginWord = "a";
    string endWord = "e";
    vector<string> vec = {"b", "c", "d", "e"};
    cout << s.ladderLength(beginWord, endWord, vec) << endl;
    return 0;
}
