#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void push(char c) {
    stack.push_back(c);
  }

  char pop() {
    char c = stack.back();
    stack.pop_back();
    return c;
  }

  char top() {
    return stack.back();
  }

  bool empty() {
    return stack.empty();
  }

  bool isValid(string s) {
    char c = 0;
    char l = 0;

    for (auto it = s.cbegin(); it != s.cend(); it++) {
      c = *it;
      switch(c) {
        case '{':
          push(c);
          break;
        case '}':
          if (empty()) {
            return false;
          }
          l = pop();
          if (l != '{') {
            return false;
          }
          break;
        case '[':
          push(c);
          break;
        case ']':
          if (empty()) {
            return false;
          }
          l = pop();
          if (l != '[') {
            return false;
          }
          break;
        case '(':
          push(c);
          break;
        case ')':
          if (empty()) {
            return false;
          }
          l = pop();
          if (l != '(') {
            return false;
          }
          break;
      }
    }
    return empty();
  }
private:
  vector<char> stack;
};

int main() {
  Solution s;
  cout << s.isValid(")") << endl;
  return 0;
}