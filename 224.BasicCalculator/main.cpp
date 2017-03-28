#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/*
int -> - digits
int -> + digits
int -> digits
digits -> [0-9] digits
operand -> spaces int spaces
expr -> operand expr1
expr -> ( expr ) expr1
expr1 -> + expr
expr1 -> - expr
spaces -> 
spaces -> space spaces
*/

#define MINUES_OPERATOR 1
#define ADD_OPERATOR 2
#define LEFT_BRACKET_OPERATOR 3

class Solution {
public:
    int calculate(string s) {
        it = s.begin();
        begin = s.begin();
        end = s.end();
        pExpr();
        eval();
        return operands.back();
    }

private:
    int pInt() {
        bool negative = false;
        // -
        if (*it == '-') {
            negative = true;
            it++;
        } else if (*it == '+') {
            it++;
        }
        if (negative) {
            return -pDigits(0);
        }
        return pDigits(0);
    }

    int pDigits(int last) {
        if (it > end || *it > '9' || *it < '0') {
            return last;
        }
        int v = *it - '0';
        it ++;
        return pDigits(last*10 + v);
    }

    void pExpr1() {
        // force to end
        if (it > end) {
            return;
        }

        if (*it == '+') {
            it ++;
            if (!operators.empty() && (
                    operators.back() == ADD_OPERATOR ||
                    operators.back() == MINUES_OPERATOR)
                ) {
                eval1();
            }
            // push into operator stack
            operators.push_back(ADD_OPERATOR);

            pExpr();
        } else if (*it == '-') {
            it ++;
            
            // same level operator must eval immediately
            if (!operators.empty() && (
                    operators.back() == ADD_OPERATOR ||
                    operators.back() == MINUES_OPERATOR)
                ) {
                eval1();
            }
            // push into operator stack
            operators.push_back(MINUES_OPERATOR);

            pExpr();
        }
    }

    void pExpr() {
        // force to end
        if (it > end) {
            return;
        }
        if (*it == '(') {
            // push left bracket into operator stack
            operators.push_back(LEFT_BRACKET_OPERATOR);
            it ++;
            pSpaces();
            pExpr();
            pSpaces();
            it ++; // right bracket

            // calculate right away and push back into operand stack
            eval();
            pExpr1();
            return;
        }

        int operand = pOperand();
        // push into operand stack
        operands.push_back(operand);
        pExpr1();
    }

    int pOperand() {
        int result;
        pSpaces();
        result = pInt();
        pSpaces();
        return result;
    }

    void pSpaces() {
        if (*it != ' ') {
            return;
        }
        it ++;
        pSpaces();
    }

    // eval to right bracket
    // eval to stack end
    void eval() {
        while (operators.size() > 0) {
            eval1();

            if (!operators.empty() && operators.back() == LEFT_BRACKET_OPERATOR) {
                operators.pop_back();
                break;
            }
        }
    }

    void eval1() {
        int ope = operators.back();
        int add1, add2, minues1, minues2;
        operators.pop_back();
        switch (ope) {
        case ADD_OPERATOR:
            add1 = operands.back();
            operands.pop_back();
            add2 = operands.back();
            operands.pop_back();
            operands.push_back(add1 + add2);
            break;
        case MINUES_OPERATOR:
            minues1 = operands.back();
            operands.pop_back();
            minues2 = operands.back();
            operands.pop_back();
            operands.push_back(minues2 - minues1);
            break;
        }
    }

    inline int digitsCount(int v) {
        return v > 0 ? (int) log10 ((double) v) + 1 : 1;
    }

    string::iterator it;
    string::iterator end;
    string::iterator begin;

    vector<int> operands;
    vector<int> operators;
};

Solution s;

int main() {
    cout << s.calculate("1+2") << endl;
    return 0;
}
