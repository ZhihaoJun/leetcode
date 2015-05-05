class Solution:
    # @param {integer} m
    # @param {integer} n
    # @return {integer}
    def rangeBitwiseAnd(self, m, n):
        mid = m + (n-m)/2
        if m == n:
            return m
        return self.rangeBitwiseAnd(m, mid)&self.rangeBitwiseAnd(mid+1, n)

print Solution().rangeBitwiseAnd(600000000, 2147483645)
