class Solution:
    # @param {integer} n
    # @return {boolean}
    def isPowerOfTwo(self, n):
        if n <= 0:
            return False
        while n > 1:
            if n % 2 == 1:
                return False
            n /= 2
        return True


def main():
    print(Solution().isPowerOfTwo(-16))

if __name__ == '__main__':
    main()
