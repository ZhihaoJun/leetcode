#include <iostream>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        // calculate combination c(m+n-2, n)
        return combination(m+n-2, n-1);
    }

private:
    unsigned long combination(int n, int r) {
        unsigned long up = 1;
        unsigned long down = 1;
        for (unsigned long i=r+1; i<=n; i++) {
            up *= i;
        }
        for (unsigned long i=1; i<=n-r; i++) {
            down *= i;
        }
        return up/down;
    }
};

int main() {
    Solution s;

    cout << s.uniquePaths(36, 7) << endl;

    return 0;
}
