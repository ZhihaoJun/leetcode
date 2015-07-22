class Solution:
    # @param {string[]} strs
    # @return {string}
    def longestCommonPrefix(self, strs):
        if len(strs) == 0:
            return ''
        i = 0
        running = True
        while running:
            c = None
            for string in strs:
                try:
                    if c is None:
                        c = string[i]
                    if c != string[i]:
                        running = False
                        break
                except IndexError:
                    running = False
                    break
            if not running:
                break
            i += 1
        return strs[0][:i]


def main():
    strs = ['123', '12', '1234', '4']
    print(Solution().longestCommonPrefix(strs))

if __name__ == '__main__':
    main()
