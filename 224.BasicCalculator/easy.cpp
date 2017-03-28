#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        vector<int> nums, opes;
        int num = 0, ope = 0;

        for (auto c : s) {
            // transition
            if (c >= '0' && c <= '9') {
                num = num * 10 + c - '0';
            } else if (c == '-' || c == '+') {
                if (!opes.empty()) {
                    switch (opes.back()) {
                    case '+':
                        do_add(nums, opes);
                        break;
                    case '-':
                        do_minues(nums, opes);
                        break;
                    }
                }
                opes.push_back(c);
                if (num != 0) {
                    cout << num << endl;
                    nums.push_back(num);
                }
                num = 0;
            } else if (c == '(') {
                opes.push_back(c);
            } else if (c == ')') {
                if (num != 0) {
                    cout << num << endl;
                    nums.push_back(num);
                }
                num = 0;
                ope = opes.back();
                while (ope != '(') {
                    switch (ope) {
                    case '+':
                        do_add(nums, opes);
                        break;
                    case '-':
                        do_minues(nums, opes);
                        break;
                    }
                    opes.pop_back();
                    ope = opes.back();
                }
            } else if (c == '\0') {
                if (num != 0) {
                    cout << num << endl;
                    nums.push_back(num);
                }
                num = 0;
            }
        }

        // final eval
        do {
            ope = opes.back();
            opes.pop_back();
            switch (ope) {
            case '+':
                do_add(nums, opes);
                break;
            case '-':
                do_minues(nums, opes);
                break;
            }
        } while (!opes.empty());

        return nums.back();
    }

private:
    inline void do_add(vector<int> &nums, vector<int> &opes) {
        int a1 = nums.back();
        nums.pop_back();
        int a2 = nums.back();
        nums.pop_back();
        nums.push_back(a1 + a2);
        opes.pop_back();
    }

    inline void do_minues(vector<int> &nums, vector<int> &opes) {
        int m1 = nums.back();
        nums.pop_back();
        int m2 = nums.back();
        nums.pop_back();
        nums.push_back(m2 - m1);
        opes.pop_back();
    }
};

int main() {
    Solution s;
    cout << s.calculate("1 + 22") << endl;
    return 0;
}
