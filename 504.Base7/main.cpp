#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

class Solution {
public:
    string convertToBase7(int num) {
        int tmp = num;
        stringstream ss;
        if (0 == num) {
          return "0";
        }
        if (num < 0) {
          tmp = -tmp;
        }
        while (tmp > 0) {
          ss << (char)((tmp % 7) + '0');
          tmp /= 7;
        }
        if (num < 0) {
          ss << '-';
        }
        string result(ss.str());
        string reversed(result.rbegin(), result.rend());
        return reversed;
    }
};

int main() {
  Solution s;

  cout << s.convertToBase7(100) << endl;
  cout << s.convertToBase7(-7) << endl;
  cout << s.convertToBase7(1) << endl;
  cout << s.convertToBase7(-1) << endl;
  cout << s.convertToBase7(0) << endl;
  cout << int(1e7) << " " << s.convertToBase7(int(1e7)) << endl;

  return 0;
}
