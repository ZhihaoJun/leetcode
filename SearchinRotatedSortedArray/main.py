class Solution:
    def binarySearch(self, l, target, start_low, start_high):
        low = start_low
        high = start_high-1
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
    # @return an integer
    def search(self, A, target):
        A_len = len(A)
        if A_len == 1:
            if A[0] == target:
                return 0
            else:
                return -1
        rotated = False
        for i in xrange(0, A_len-1):
            if A[i] > A[i+1]:
                rotated = True
                index = self.binarySearch(A, target, 0, i)
                if index != -1:
                    return index
                index = self.binarySearch(A, target, i+1, A_len)
                if index != -1:
                    return index
        if not rotated:
            return self.binarySearch(A, target, 0, A_len)
        return -1

print(Solution().search([3, 1], 3))