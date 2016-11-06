# The guess API is already defined for you.
# @param num, your guess
# @return -1 if my number is lower, 1 if my number is higher, otherwise return 0

import math

n = 2
g = 1

def guess(num):
    if num > g:
        return 1
    elif num < g:
        return -1
    return 0

class Solution(object):
    def guessNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        high = n+1
        low = 1
        while 1:
            mid = int(math.floor((high+low)/2))
            r = guess(mid)
            if r == 1:
                high = mid
            elif r == -1:
                low = mid
            else:
                break
        return mid

def main():
    print(Solution().guessNumber(n))

if __name__ == '__main__':
    main()
