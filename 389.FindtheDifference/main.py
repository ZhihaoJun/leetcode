import random

class Solution(object):
    def findTheDifference(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        slen = len(s)
        sorted_s = sorted(s)
        sorted_t = sorted(t)
        for i, c in enumerate(sorted_t):
            if i < slen and c != sorted_s[i]:
                return c
        return sorted_t[i]

def main():
    s = ''
    t = ''.join(random.sample(s, len(s))) + 'u'
    print(Solution().findTheDifference(s, t))

if __name__ == '__main__':
    main()
