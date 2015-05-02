#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    static int POW10[];

    int stringToInt(const string& str) {
        int str_len = str.length();
        int i, ret = 0;
        for (i=0; i<str_len; i++) {
            ret += (str[i]-'0') * (Solution::POW10[str_len-i-1]);
        }
        return ret;
    }

    vector<string> split(const string& str, const string& sep) {
        int index, sep_len = sep.length(), left = 0;
        vector<string> ret = vector<string>();
        while ((index = str.find(sep, left)) != -1) {
            ret.push_back(str.substr(left, index-left));
            left = index + sep_len;
        }
        ret.push_back(str.substr(left));
        return ret;
    }

    vector<string> split(const string& str, char sep) {
        int index, left = 0;
        vector<string> ret = vector<string>();
        while ((index = str.find(sep, left)) != -1) {
            ret.push_back(str.substr(left, index-left));
            left = index + 1;
        }
        ret.push_back(str.substr(left));
        return ret;
    }

    void remove_tail_zero()

    int compareVersion(string version1, string version2) {
        vector<string> v1_list = this->split(version1, '.');
        vector<string> v2_list = this->split(version2, '.');

        return 0;
    }
};

int Solution::POW10[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};

void printVector(const vector<string>& v)
{
    for (vector<string>::const_iterator it=v.begin(); it!=v.end(); it++) {
        cout << *it << endl;
    }
}

int main(void)
{
    Solution s = Solution();
    int i = s.stringToInt(string("123"));
    printVector(s.split(string("1,2,3,4"), ','));
    cout << i;
    return 0;
}
