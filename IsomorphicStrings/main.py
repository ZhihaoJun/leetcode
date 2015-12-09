class Solution:
    # @param {string} s
    # @param {string} t
    # @return {boolean}
    def isIsomorphic(self, s, t):
        replaces = {}
        for i, c in enumerate(s):
            if c not in replaces:
                if t[i] in replaces.values():
                    return False
                replaces[c] = t[i]
            else:
                if replaces[c] != t[i]:
                    return False
        return True

if __name__ == '__main__':
    print(Solution().isIsomorphic('ab', 'aa'))
    print(Solution().isIsomorphic('ab', 'ca'))
