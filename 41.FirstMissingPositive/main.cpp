#include <iostream>
#include <vector>

using namespace std;

void printInts(const vector<int> &nums) {
  for (auto i : nums) {
    cout << i << " ";
  }
}

class Solution {
public:
  int firstMissingPositive(vector<int>& nums) {
    int i, target, n = nums.size(), t;
    for (i=0; i<n; ++i) {
      target = nums[i];
      // move target to nums[target-1]
      while (target > 0 && target <= n && target != nums[target-1]) {
        t = nums[target-1];
        nums[target-1] = target;
        target = t;
      }
    }

    for (i=0; i<n; ++i) {
      if (nums[i]-1 != i) {
        return i+1;
      }
    }
    return n+1;
  }
};

int main() {
  Solution s;
  vector<int> vec{2,1};
  cout << s.firstMissingPositive(vec) << endl;
  return 0;
}
