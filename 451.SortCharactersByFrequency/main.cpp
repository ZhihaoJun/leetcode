#include <iostream>
#include <string>
#include <sstream>
#include <map>

using namespace std;

class Solution {
public:
  multimap<int, char> sort(map<char, int> freq) {
    multimap<int, char> dst;
    for (auto it = freq.begin(); it != freq.end(); it ++) {
      dst.insert(pair<int, char>(it->second, it->first));
    }
    return dst;
  }

  string frequencySort(string s) {
    map<char, int> freq;
    for (int i=0; i<s.length(); i++) {
      if (freq.find(s[i]) != freq.end()) { // found
        freq[s[i]] ++;
      } else {
        freq[s[i]] = 1;
      }
    }
    auto sorted = sort(freq);
    stringstream ss;
    for (auto it = sorted.crbegin(); it != sorted.crend(); it ++) {
      for (int i=0; i<it->first; i++) {
        ss << it->second;
      }
    }
    return ss.str();
  }
};

int main() {
  cout << "Hello World" << endl;
  cout << Solution().frequencySort("") << endl;
  return 0;
}
