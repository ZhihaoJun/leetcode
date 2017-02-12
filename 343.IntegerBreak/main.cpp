#include <iostream>
#include <map>

class Solution {
public:
    int integerBreak(int n) {
        if (1 == n) {
            return 1;
        }
        if (2 == n) {
            return 1;
        }
        std::map<int, int>::iterator it = this->saved.find(n);
        if (it != this->saved.end()) {
            // found
            return it->second;
        }
        int max = 0;
        int mul = 0;
        int breakL = 0;
        int breakR = 0;
        for (int i=1; i<n; i++) {
            // dont break just i and n-i
            breakL = this->integerBreak(i);
            breakR = this->integerBreak(n-i);
            mul = i * (n-i);
            if (mul > max) {
                max = mul;
            }

            // break i
            mul = breakL * (n-i);
            if (mul > max) {
                max = mul;
            }

            // break n-i
            mul = i * breakR;
            if (mul > max) {
                max = mul;
            }

            // break
            mul = breakL * breakR;
            if (mul > max) {
                max = mul;
            }
        }
        
        // save the max value
        this->saved.insert(std::pair<int, int>(n, max));
        return max;
    }

private:
    std::map<int, int> saved;
};

int main() {
    Solution s;

    // for (int i=2; i<=58; i++) {
    // std::cout << i << ":" << s.integerBreak(i) << std::endl;
    // }
    std::cout << s.integerBreak(8) << std::endl;
    return 0;
}
