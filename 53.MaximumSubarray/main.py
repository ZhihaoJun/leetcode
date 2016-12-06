class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        dp = 0
        maxSum = 0
        if len(nums) == 0:
            return 0
        dp = nums[0]
        maxSum = nums[0]

        for i in xrange(1, len(nums)):
            dp = max(nums[i], dp+nums[i])
            maxSum = max(maxSum, dp)
        
        return maxSum

def main():
    l = [-2,1,-3,4,-1,2,1,-5,4]
    l = [-1]
    print Solution().maxSubArray(l)

if __name__ == '__main__':
    main()
