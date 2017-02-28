#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(const vector<int> &vec) {
    for (auto i : vec) {
        cout << i << " ";
    }
    cout << endl;
}

class Solution {
public:
    int countArrangement(int N) {
        vector<int> vec;
        int cnt = 0;
        for (int i=1; i<=N; i++) {
            vec.push_back(i);
        }
        // print(vec);
        if (isBeautifulArrangement(vec)) {
            cnt ++;
        }
        while (next_permutation(vec.begin(), vec.end())) {
            // print(vec);
            if (isBeautifulArrangement(vec)) {
                cnt ++;
            }
        }
        return cnt;
    }

private:
    bool isBeautifulArrangement(const vector<int> &vec) {
        return true;
    }
};

int main() {
    Solution s;

    cout << s.countArrangement(15) << endl;
    return 0;
}
