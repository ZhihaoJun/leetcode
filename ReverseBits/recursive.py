class Solution(object):
    def _reverse(self, n, bits):
        if bits == 1:
            return n
        halfbits = bits >> 1
        return (self._reverse(n & ((1 << halfbits) - 1), halfbits) << halfbits) | self._reverse(n >> halfbits, halfbits)

    def reverseBits(self, n):
        return self._reverse(n, 32)


def main():
    print(Solution().reverseBits(43261596) == 964176192)
    print(Solution().reverseBits(964176192) == 43261596)
    print(Solution().reverseBits(0) == 0)
    print(Solution().reverseBits(1) == 2147483648)
    print(Solution().reverseBits(4294967295) == 4294967295)

if __name__ == '__main__':
    main()
