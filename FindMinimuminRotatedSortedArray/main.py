class Solution:
    # @param {integer[]} nums
    # @return {integer}
    def findMin(self, nums):
        nlen = len(nums)
        if nlen == 1:
            return nums[0]
        split_pos = 0
        for i in xrange(nlen-1):
            if nums[i+1] < nums[i]:
                split_pos = i
        if nums[split_pos+1] < nums[0]:
            return nums[split_pos+1]
        return nums[0]


def main():
    nums = [4, 5, 6, 7, 0, 1, 2]
    nums = [1, 2]
    print(Solution().findMin(nums))

if __name__ == '__main__':
    main()
