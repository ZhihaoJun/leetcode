class Solution:
    # @return a tuple, (index1, index2)
    def twoSum(self, num, target):
        pair = {}
        for k, v in enumerate(num):
            other = pair.get(v, 0)
            if num[other] + v == target and other != k:
                if k > other:
                    return (other+1, k+1)
                else:
                    return (k+1, other+1)
            else:
                pair[target-v] = k

print(Solution().twoSum([3,2,4],6))
