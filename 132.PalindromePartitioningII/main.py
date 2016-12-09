class Solution(object):
    def isPalindrome(self, l, r):
        return (self.s[l] == self.s[r] and (r - l < 2 or self.pali[l+1][r-1]))

    def setPalindrome(self, l, r, v):
        self.pali[l][r] = v

    def init(self, s):
        self.s = s
        self.slen = len(s)
        self.pali = [[False for i in xrange(self.slen)] for j in xrange(self.slen)]
        self.dp = [0 for i in xrange(self.slen)]

    def minCut(self, s):
        """
        :type s: str
        :rtype: int
        """
        self.init(s)

        # init
        # max cut is to cut every chars
        for i in xrange(self.slen):
            self.dp[i] = i
        
        for r in xrange(self.slen):
            for l in reversed(xrange(0, r+1)):
                if self.isPalindrome(l, r):
                    self.setPalindrome(l, r, True)
                    if l == 0:
                        self.dp[r] = 0
                    else:
                        # dp[l-1]
                        # cut is between chars
                        # cut at l is cutting after the char at position l
                        self.dp[r] = min(self.dp[r], self.dp[l-1]+1)

        return self.dp[self.slen - 1]

def main():
    s = 'cabababcbc'
    print Solution().minCut(s)

if __name__ == '__main__':
    main()
