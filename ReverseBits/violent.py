class Solution(object):
    def reverseBits(self, n):
        """
        :type n: int
        :rtype: int
        """
        result = 0
        for i in xrange(32):
            if n & 1 << i > 0:
                result |= 1 << (31 - i)
        return result


def main():
    print(Solution().reverseBits(43261596) == 964176192)
    print(Solution().reverseBits(964176192) == 43261596)
    print(Solution().reverseBits(0) == 0)
    print(Solution().reverseBits(1) == 2147483648)
    print(Solution().reverseBits(4294967295) == 4294967295)

if __name__ == '__main__':
    main()
