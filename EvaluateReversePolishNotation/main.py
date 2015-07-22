class Solution:
    # @param {string[]} tokens
    # @return {integer}
    def evalRPN(self, tokens):
        if not tokens:
            return 0
        stack = []
        for t in tokens:
            try:
                val = int(t)
                stack.append(val)
            except ValueError:
                if t == '+':
                    adder = stack.pop()
                    added = stack.pop()
                    stack.append(added + adder)
                elif t == '-':
                    substracter = stack.pop()
                    substracted = stack.pop()
                    stack.append(substracted - substracter)
                elif t == '*':
                    multiplier = stack.pop()
                    multiplied = stack.pop()
                    stack.append(multiplied * multiplier)
                elif t == '/':
                    divider = stack.pop()
                    divided = stack.pop()
                    if divider == 0:
                        raise ValueError('divider can not be zero')
                    # because python division is floor division
                    # 1/-10 = -1 actually we need 1/-10 = 0
                    stack.append(int(float(divided) / divider))
        return stack[0]


def main():
    tokens = ["4", "13", "5", "/", "+"]
    print(Solution().evalRPN(tokens))

if __name__ == '__main__':
    main()
