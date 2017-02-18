#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int i = 0;
        int j = 0;
        int cnt = 0;
        for (; i<nums.size(); i++) {
            for (j = i+1; j<nums.size(); j++) {
                if (nums[i] > 2*nums[j]) {
                    cnt ++;
                }
            }
        }
        return cnt;
    }
};

int main() {
    vector<int> vec(50000, 1);

    Solution s;

    cout << s.reversePairs(vec) << endl;

    return 0;
}
