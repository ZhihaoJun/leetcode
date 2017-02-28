#include <iostream>
#include <vector>

using namespace std;

const int READY_STATE = 0;
const int PRE0_STATE = 1;
const int PRE1_STATE = 2;
const int POST0_STATE = 3;
const int POST1_STATE = 4;
const int END_STATE = 5;

class DFA {
public:
    DFA():state(READY_STATE), len(0), cnt0(0), cnt1(0) {}

    int parse(vector<int>::iterator it, vector<int>::iterator end) {
        while (it < end) {
            transition(*it);
            it = it + postTransition();
            if (END_STATE == state) {
                break;
            }
        }
        if (it >= end) {
            state = END_STATE;
            postTransition();
        }
        return max + max;
    }

    int parsedLen() {
        return len;
    }

private:
    void transition(int i) {
        if (0 == i && READY_STATE == state) {
            state = PRE0_STATE;
        } else if (1 == i && READY_STATE == state) {
            state = PRE1_STATE;
        } else if (0 == i && PRE1_STATE == state) {
            state = POST0_STATE;
        } else if (1 == i && PRE0_STATE == state) {
            state = POST1_STATE;
        } else if (0 == i && POST1_STATE == state) {
            state = END_STATE;
        } else if (1 == i && POST0_STATE == state) {
            state = END_STATE;
        }
    }

    int postTransition() {
        if (PRE0_STATE == state) {
            len ++;
            cnt0 ++;
        } else if (POST0_STATE == state) {
            cnt0 ++;
        } else if (PRE1_STATE == state)  {
            len ++;
            cnt1 ++;
        } else if (POST1_STATE == state) {
            cnt1 ++;
        } else if (END_STATE == state) {
            max = cnt0 > cnt1 ? cnt1 : cnt0;
        }
        return 1;
    }

    int len;
    int max;
    int cnt0;
    int cnt1;
    int state;
};

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        auto it = nums.begin();
        auto end = nums.end();
        int max = 0;
        int tmp = 0;
        while (it < end) {
            DFA dfa;
            tmp = dfa.parse(it, end);
            if (tmp > max) {
                max = tmp;
            }
            it += dfa.parsedLen();
        }
        return max;
    }
};

int main() {
    Solution s;

    vector<int> vec{0, 0};

    cout << s.findMaxLength(vec) << endl;
    return 0;
}