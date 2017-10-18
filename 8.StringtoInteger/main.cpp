#include <iostream>
#include <climits>
#include <string>

using namespace std;

#define INT_MAX_10 (INT_MAX/10)

class Solution {
public:
  int myAtoi(string str) {
    res = 0;
    isNegative = false;
    large = false;
    s = str;
    i = 0;

    pAll();

    if (large) {
      if (isNegative) {
        return INT_MIN;
      } else {
        return INT_MAX;
      }
    }

    if (isNegative) {
      return -res;
    }
    return res;
  }

private:
  unsigned int res;
  bool isNegative;
  bool large;
  int i;
  string s;

  void pAll() {
    pSpaces();
    pSign();
    pDigits();
  }

  void pSpaces() {
    pSpace();
    if (s[i] == ' ') {
      pSpaces();
    }
  }

  void pSpace() {
    if (s[i] == ' ') {
      ++i;
    }
  }

  void pSign() {
    if (s[i] == '+') {
      ++i;
      isNegative = false;
    } else if (s[i] == '-') {
      ++i;
      isNegative = true;
    }
  }

  void pDigits() {
    pDigit();
    if (isDigit(s[i])) {
      pDigits();
    }
  }

  void pDigit() {
    unsigned int tmp;
    if (isDigit(s[i])) {
      tmp = res * 10 + s[i] - '0';
      // multiply overflow handle
      // addition overflow handle
      if (tmp > INT_MAX) {
        large = true;
      } else if (isNegative && tmp > -INT_MIN) {
        large = true;
      }
      res = tmp;
      ++i;
    }
  }

  inline bool isDigit(char c) {
    if (s[i] >= '0' && s[i] <= '9') {
      return true;
    }
    return false;
  }

  bool isAddingOverflow(unsigned int max, unsigned int a, unsigned int b) {

  }

  bool isMultiplyingOverflow(unsigned int max, unsigned int a, unsigned int b) {
    
  }
};

int main() {
  Solution s;
  cout << "1e10 " << (s.myAtoi("1e10") == 1) << endl;
  cout << "122e10 " << (s.myAtoi("122e10") == 122) << endl;
  cout << "  1 " << (s.myAtoi("  1") == 1) << endl;
  cout << "123.12 " << (s.myAtoi("123.12") == 123) << endl;
  cout << "  -1 " << (s.myAtoi("  -1") == -1) << endl;
  cout << "  -  1 " << (s.myAtoi("  -  1") == 0) << endl;
  cout << "+123 " << (s.myAtoi("+123") == 123) << endl;
  cout << "abc123 " << (s.myAtoi("abc123") == 0) << endl;
  cout << "  abc123 " << (s.myAtoi("  abc123") == 0) << endl;
  cout << "  --123 " << (s.myAtoi("  --123") == 0) << endl;
  cout << "+-123 " << (s.myAtoi("+-123") == 0) << endl;
  cout << "-+123 " << (s.myAtoi("-+123") == 0) << endl;
  cout << "12345678 " << (s.myAtoi("12345678") == 12345678) << endl;
  cout << "1234567890123456789 " << s.myAtoi("1234567890123456789") << " " << (s.myAtoi("1234567890123456789") == 2147483647) << endl;
  cout << "-1234567890123456789 " << (s.myAtoi("-1234567890123456789") == -2147483648) << endl;
  cout << "2147483647 " << (s.myAtoi("2147483647") == 2147483647) << endl;
  cout << "2147483648 " << s.myAtoi("2147483648") << " " << (s.myAtoi("2147483648") == 2147483647) << endl;
  cout << "-2147483648 " << (s.myAtoi("-2147483648") == -2147483648) << endl;
  cout << "-2147483647 " << (s.myAtoi("-2147483647") == -2147483647) << endl;
  cout << "-2147483646 " << (s.myAtoi("-2147483646") == -2147483646) << endl;
  cout << "    10522545459 " << (s.myAtoi("    10522545459") == 2147483647) << endl;
  cout << " " << (s.myAtoi("") == 0) << endl;
  return 0;
}
