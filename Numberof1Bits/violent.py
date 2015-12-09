class Solution(object):
    def hammingWeight(self, n):
        """
        :type n: int
        :rtype: int
        """
        result = 0
        for i in xrange(32):
            if n & 1 << i > 0:
                result += 1
        return result


def main():
    print(Solution().hammingWeight(1) == 1)
    print(Solution().hammingWeight(0) == 0)
    print(Solution().hammingWeight(3) == 2)
    print(Solution().hammingWeight(2) == 1)
    print(Solution().hammingWeight(4294967295) == 32)

if __name__ == '__main__':
    main()
