class Solution:
    # @param s, a string
    # @return a string
    def reverseWords(self, s):
        return (''.join([word + ' ' for word in reversed(s.split())])).rstrip()

print(Solution().reverseWords('   the sky is blue   ds'))
