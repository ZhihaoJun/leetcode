#include <iostream>

using namespace std;

class Solution {
public:
  bool canMeasureWater(int x, int y, int z) {
    if (z == 0) {
      return true;
    }
    if (z - x > y) {
      return false;
    }
    return z % gcd(x, y) == 0;
  }

  int gcd(int x, int y) {
    return y == 0 ? x : gcd(y, x % y);
  }
};

int main() {
  Solution s;
  cout << s.canMeasureWater(3, 5, 4) << endl;
  return 0;
}
