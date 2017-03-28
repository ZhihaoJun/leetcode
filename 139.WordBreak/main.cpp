#include <iostream>
#include <vector>

using namespace std;

void print(vector<bool> &vec) {
    for (bool b : vec) {
        cout << b << " ";
    }
    cout << endl;
}

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // dp[i] s[0..i] is splitable
        vector<bool> dp(s.length());
        for (int i=0; i<s.length(); i++) {
            for (int j=-1; j<i; j++) {
                if (-1 == j || dp[j]) {
                    if (find(wordDict, s, j+1, i)) {
                        // found
                        dp[i] = true;
                    }
                }
            }
        }
        return dp[s.length()-1];
    }

private:
    // is a == b[l..r]
    bool is_same(const string &a, const string &b, int l, int r) {
        if (a.length() != r-l+1) {
            return false;
        }
        for (int i=l; i<=r; i++) {
            if (a[i-l] != b[i]) {
                return false;
            }
        }
        return true;
    }

    bool find(const vector<string> &wordDict, const string &str, int l, int r) {
        for (auto s : wordDict) {
            if (is_same(s, str, l, r)) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution s;

    vector<string> vec = {"leet", "code"};

    cout << s.wordBreak("leetcode", vec) << endl;
    return 0;
}
