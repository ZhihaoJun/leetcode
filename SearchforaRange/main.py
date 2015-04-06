class Solution:
    def binarySearch(self, l, target):
        low = 0
        high = len(l)-1
        if high < 0:
            return -1
        while low < high:
            mid = (low + high) / 2
            if l[mid] > target:
                high = mid-1
            elif l[mid] < target:
                low = mid+1
            else:
                return mid
        if l[(low + high) / 2] == target:
            return (low + high) / 2
        return -1

    # @param A, a list of integers
    # @param target, an integer to be searched
    # @return a list of length 2, [index1, index2]
    def searchRange(self, A, target):
        pos = self.binarySearch(A, target)
        start = pos
        end = pos
        A_len = len(A)
        if pos == -1:
            return [-1, -1]
        breaked = False
        for i in xrange(pos-1, -1, -1):
            if A[i] != target:
                start = i + 1
                breaked = True
                break
        if not breaked:
            start = 0

        breaked = False
        for i in xrange(pos+1, A_len):
            if A[i] != target:
                end = i - 1
                breaked = True
                break
        if not breaked:
            end = A_len-1

        return [start, end]

print(Solution().searchRange([], 0))
