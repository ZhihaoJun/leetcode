class Solution:
    def __init__(self):
        self.pow_n = {
            0: 1
        }

    # @param x, a float
    # @param n, a integer
    # @return a float
    def pow(self, x, n):
        if n == 1:
            self.pow_n[1] = x
            return x
        if n in self.pow_n:
            return self.pow_n[n]
        self.pow_n[n] = self.pow(x, n/2) * self.pow(x, n/2)
        if n & 1:
            self.pow_n[n] *= x
        return self.pow_n[n]

print(Solution().pow(25, -3))
