#include <iostream>
#include <tuple>
#include <vector>

using namespace std;
/*
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() != s3.length() - s2.length()) {
            return false;
        }
        return interleave(s1, 0, s2, 0, s3, 0);
    }

private:
    bool interleave(
        const string &s1,
        string::size_type i1,
        const string &s2,
        string::size_type i2,
        const string &s3,
        string::size_type i3
    )
    {
        auto len1 = s1.length();
        auto len2 = s2.length();
        auto len3 = s3.length();
        while (1) {
            if (i1 == len1 && i2 == len2 && i3 == len3) {
                return true;
            } else if (i1 < len1 &&
                i2 < len2 &&
                i3 < len3 &&
                s1[i1] == s2[i2] &&
                s1[i1] == s3[i3]) {

                if (interleave(s1, i1+1, s2, i2, s3, i3+1)) {
                    return true;
                } else if (interleave(s1, i1, s2, i2+1, s3, i3+1)) {
                    return true;
                }
                return false;
            } else {
                if (i1 < len1 && i3 < len3 && s1[i1] == s3[i3]) {
                    ++i1;
                    ++i3;
                } else if (i2 < len2 && i3 < len3 && s2[i2] == s3[i3]) {
                    ++i2;
                    ++i3;
                } else {
                    return false;
                }
            }
        }
    }
};*/

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        string::size_type len1 = s1.length();
        string::size_type len2 = s2.length();
        string::size_type len3 = s3.length();
        if (len1 != len3 - len2) {
            return false;
        }
        vector< vector<bool> > dp(len1 + 1, vector<bool>(len2 + 1, false));
        dp[0][0] = true;
        int i, j;
        for (i=0; i<=len1; ++i) {
            for (j=0; j<=len2; ++j) {
                if (i + j > 0) {
                    if (i > 0 && s1[i-1] == s3[i+j-1] && dp[i-1][j]) {
                        dp[i][j] = true;
                    } else if (j > 0 && s2[j-1] == s3[i+j-1] && dp[i][j-1]) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = false;
                    }
                }
            }
        }
        return dp[len1][len2];
    }
};

int main() {
    Solution s;
    // string a = "bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa";
    string a = "aabcc";
    // string b = "babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab";
    string b = "dbbca";
    // string c = "babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab";
    string c = "aadbbcbcac";
    cout << s.isInterleave(a, b, c) << endl;
    return 0;
}
