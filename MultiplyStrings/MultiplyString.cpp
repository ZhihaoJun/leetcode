#include <iostream>

using namespace std;

class Solution {
public:
    vector<char> multiplyVector(vector<char> num1, vector<char> num2) {
        int len1 = num1.size();
        int len2 = num2.size();
        int i, j;
        vector<char> *ret = new vector<char>();

        for (i=0; i<len1; i++) {
            for (j=0; j<len2; j++) {
                
            }
        }

        return *ret;
    }

    string multiply(string num1, string num2) {
        int len1 = num1.length();
        int len2 = num2.length();
        int i, j;

        for (i=0; i<len1; i++) {
            for (j=0; j<len2; j++) {

            }
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution s = Solution();
    string num1(argv[1]);
    string num2(argv[2]);
    cout << s.multiply(num1, num2);
    return 0;
}
