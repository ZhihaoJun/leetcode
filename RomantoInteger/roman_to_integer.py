class Solution:
    characters = {
        'I': 1,
        'V': 5,
        'X': 10,
        'L': 50,
        'C': 100,
        'D': 500,
        'M': 1000
    }

    # @return an integer
    def romanToInt(self, s):
        ret = 0
        s_len = len(s)
        for i in xrange(s_len-1):
            c = s[i]
            if self.characters[c] < self.characters[s[i+1]]:
                ret -= self.characters[c]
            else:
                ret += self.characters[c]
        ret += self.characters[s[s_len-1]]
        return ret

s = Solution()
print(s.romanToInt('I'))
print(s.romanToInt('II'))
print(s.romanToInt('III'))
print(s.romanToInt('IV'))
print(s.romanToInt('VI'))
print(s.romanToInt('MCMIV'))
print(s.romanToInt('IMMMM'))
