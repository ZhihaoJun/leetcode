#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        int cnt = 0;
        for (auto c : word) {
            if (c >= 'A' && c <= 'Z') {
                cnt ++;
            }
        }
        // first letter captical
        if (word[0] >= 'A' && word[0] <= 'Z' && cnt == 1) {
            return true;
        }
        // all captical
        if (cnt == word.size()) {
            return true;
        }
        // no captical
        if (cnt == 0) {
            return true;
        }
        return false;
    }
};

int main() {
    Solution s;

    cout << s.detectCapitalUse("USA") << endl;
    cout << s.detectCapitalUse("FlaG") << endl;
    cout << s.detectCapitalUse("Google") << endl;
    cout << s.detectCapitalUse("leetcode") << endl;
    return 0;
}