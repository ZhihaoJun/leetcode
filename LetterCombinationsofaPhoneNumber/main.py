class Solution:
    numbers = {
        '1': '',
        '2': 'abc',
        '3': 'def',
        '4': 'ghi',
        '5': 'jkl',
        '6': 'mno',
        '7': 'pqrs',
        '8': 'tuv',
        '9': 'wxyz',
        '0': ' '
    }

    # @return a list of strings, [s1, s2]
    def letterCombinations(self, digits):
        result = []
        for digit in digits:
            if digit == '1':
                continue
            tmp = []
            for c in self.numbers[digit]:
                if len(result) != 0:
                    for item in result:
                        tmp.append(item + c)
                else:
                    tmp.append(c)
            result = tmp
        return result

print(Solution().letterCombinations('032'))
