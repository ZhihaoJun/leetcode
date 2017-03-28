#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

/*
start:
    spaces int spaces $
    spaces float spaces $
digit:
    0-9
digits:
    digit
    digit digits
int:
    sign digits
    digits
float-part:
    sign digits . digits
    sign . digits
    sign digits .
    digits . digits
    . digits
    digits .
float:
    float-part
    int e int
    int E int
    float-part e int
    float-part E int
sign:
    +
    -
spaces:
    space
    space spaces
*/

class Solution {
public:
    bool isNumber(string s) {
        it = s.begin();
        end = s.end();
        bool result = pSpaces();
        result &= pInt();
        result &= pSpaces();
        if (it != end) {
            result &= false;
        }
        if (result) {
            return result;
        }

        it = s.begin();
        result = pSpaces();
        result &= pFloat();
        result &= pSpaces();
        if (it != end) {
            return false;
        }
        return result;
    }

private:
    bool pDigit() {    
        if (it < end && isDigit(*it)) {
            ++it;
            return true;
        }
        return false;
    }

    bool pDigits() {
        bool result = pDigit();
        if (result) {
            if (isDigit(*it)) {
                pDigits();
            }
        }
        return result;
    }

    bool pInt() {
        if (isSign(*it)) {
            // sign digits
            bool result = pSign();
            result &= pDigits();
            return result;
        } else {
            // digits
            bool result = pDigits();
            return result;
        }
    }

    bool pFloatPart() {
        bool result = true;
        if (isSign(*it)) {
            result = pSign();
            if (*it == '.') {
                ++it;
                result &= pDigits();
                return result;
            } else {
                result &= pDigits();
                if (*it != '.') {
                    return false;
                }
                ++it;
                if (isDigit(*it)) {
                    result &= pDigits();
                }
                return result;
            }
        } else {
            if (*it == '.') {
                ++it;
                result = true;
                result &= pDigits();
                return result;
            } else {
                result = pDigits();
                if (*it != '.') {
                    return false;
                }
                ++it;
                pDigits();
                return result;
            }
        }
    }

    bool pFloat() {
        string::iterator anchor = it;
        bool result = pFloatPart();
        if (!result) {
            it = anchor;
            result = pInt();
        }
        if (*it == 'e' || *it == 'E') {
            ++it;
            result &= pInt();
        }
        return result;
    }

    bool pSign() {
        ++it;
        return true;
    }

    bool pSpaces() {
        if (*it == ' ') {
            ++it;
            pSpaces();
        }
        return true;
    }

    inline bool isSign(char c) {
        return c == '-' || c == '+';
    }

    inline bool isDigit(char c) {
        return c >= '0' && c <= '9';
    }

    string::iterator it;
    string::iterator end;
};

int main() {
    Solution s;
    cout << "10 " << s.isNumber("10") << endl;
    cout << "+10 " << s.isNumber("+10") << endl;
    cout << "1e10 " << s.isNumber("1e10") << endl;
    cout << ".01e10 " << s.isNumber(".01e10") << endl;
    cout << "-1e-10 " << s.isNumber("-1e-10") << endl;
    cout << "+1e+10 " << s.isNumber("+1e+10") << endl;
    cout << "0.0001 " << s.isNumber("0.0001") << endl;
    cout << "-0.0001 " << s.isNumber("-0.0001") << endl;
    cout << "-.0001 " << s.isNumber("-.0001") << endl;
    cout << "+.0001 " << s.isNumber("+.0001") << endl;
    cout << "  0.0001   " << s.isNumber("  0.0001  ") << endl;
    cout << "3.  " << s.isNumber("3. ") << endl;
    cout << " .3  " << s.isNumber(" .3 ") << endl;

    stringstream ss;
    ss << ".";
    for (int i=0; i<10000; i++) {
        ss << "0";
    }
    ss << "1";
    cout << "long valid number " << s.isNumber(ss.str()) << endl;

    ss << "a";

    cout << "long invalid number " << s.isNumber(ss.str()) << endl;

    cout << "+.   0001 " << s.isNumber("+.   0001") << endl;
    cout << "e10 " << s.isNumber("e10") << endl;
    cout << "  e  " << s.isNumber("  e ") << endl;
    cout << "e-10 " << s.isNumber("e-10") << endl;
    cout << "1 a " << s.isNumber("1 a") << endl;
    cout << "abc " << s.isNumber("abc") << endl;
    cout << ". " << s.isNumber(".") << endl;
    cout << ".. " << s.isNumber("..") << endl;
}
