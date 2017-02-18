#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        return 0;
    }
};

int main() {
    Solution s;
    vector<string> bank = {"AACCGGTA", "AACCGCTA", "AAACGGTA"};
    cout << s.minMutation("AACCGGTT", "AAACGGTA", bank) << endl;
    return 0;
}
