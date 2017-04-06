#include <iostream>
#include <vector>

using namespace std;

#define MAX(a,b) ((a)>(b)?(a):(b))

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int>::size_type n = nums.size();
        // dp[i][j] = k
        // i [0,n)
        // j 0 or 1   0 = dont robber house i  1 = robber house i
        // 
        // init:
        // dp[0][0] = 0, dp[0][1] = nums[0]
        // 
        // iterate
        // dp[i][0] = max(dp[i-1][0],dp[i-1][1])
        // dp[i][1] = dp[i-1][0] + nums[i]
        // 
        // answer is max(dp[n-1][0], dp[n-1][1])
        if (n == 0) {
            return 0;
        }
        vector< vector<int> > dp = vector< vector<int> >(n, vector<int>(2, 0) );
        int i;
        dp[0][1] = nums[0];
        for (i=1; i<n; i++) {
            dp[i][0] = MAX(dp[i-1][0], dp[i-1][1]);
            dp[i][1] = dp[i-1][0] + nums[i];
        }
        return MAX(dp[n-1][0], dp[n-1][1]);
    }
};

int main() {
    Solution s;
    vector<int> nums{1};
    cout << s.rob(nums) << endl;
    return 0;
}
