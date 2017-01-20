#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        static int pow10[] = {
            1,
            10,
            100,
            1000,
            10000,

            100000,
            1000000,
            10000000,
            100000000,
            1000000000
        };

        if (x < 0) {
            return false;
        }

        int size = (int)(log10(x) + 1);
        int i;
        for (i=0; i<size; i++) {
            if ( (x/pow10[i])%10 != (x/pow10[size-i-1])%10 ) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    int n = 121;
    cout << s.isPalindrome(n) << endl;
    return 0;
}