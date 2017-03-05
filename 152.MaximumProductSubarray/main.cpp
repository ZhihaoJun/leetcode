#include <iostream>
#include <vector>

using namespace std;

#define max(a, b) ((a) > (b)?(a) : (b))
#define min(a, b) ((a) < (b)?(a) : (b))

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curr_max, curr_min;
        vector<int>::size_type i = 1;
        curr_max = nums[0];
        curr_min = nums[0];
        int max_ret = nums[0];
        int tmp_curr_max = curr_max;
        for (; i<nums.size(); i++) {
            tmp_curr_max = curr_max; // save the curr_max before modify it
            curr_max = max(max(curr_max*nums[i], curr_min*nums[i]), nums[i]);
            curr_min = min(min(tmp_curr_max*nums[i], curr_min*nums[i]), nums[i]);
            max_ret = max(curr_max, max_ret);
        }
        return max_ret;
    }
};

int main() {
    vector<int> vec{2,3,-2,4};
    Solution s;
    cout << s.maxProduct(vec) << endl;
    return 0;
}
