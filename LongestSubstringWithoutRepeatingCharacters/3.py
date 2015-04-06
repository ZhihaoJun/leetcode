class Solution:
    # @return an integer
    def lengthOfLongestSubstring(self, s):
        exists = {}
        length = 0
        max_length = 0
        s_length = len(s)
        for i in range(0, s_length):
            exists = {}
            length = 0
            for j in range(i+1, s_length):
                if exists.get(s[j], False):
                    break
                exists[s[j]] = True
                length += 1
            if length > max_length:
                max_length = length
        return max_length+1

print Solution().lengthOfLongestSubstring('123')
