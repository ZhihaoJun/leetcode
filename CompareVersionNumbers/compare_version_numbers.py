class Solution:
    def remove_tail_zero(self, v_list):
        v_list_len = len(v_list)
        for i in xrange(v_list_len-1, -1, -1):
            if v_list[i] == 0:
                v_list.pop()
            else:
                break
        if len(v_list) == 0:
            return [0]
        return v_list

    # @param version1, a string
    # @param version2, a string
    # @return an integer
    def compareVersion(self, version1, version2):
        v1_list = version1.split('.')
        v2_list = version2.split('.')
        v1_list = map(int, v1_list)
        v2_list = map(int, v2_list)
        v1_list = self.remove_tail_zero(v1_list)
        v2_list = self.remove_tail_zero(v2_list)

        for i, v in enumerate(v1_list):
            try:
                if v > v2_list[i]:
                    return 1
                elif v < v2_list[i]:
                    return -1
            except IndexError:
                return 1
        if len(v2_list) > len(v1_list):

            return -1
        return 0

s = Solution()
print(s.compareVersion('1.2', '1'))  # 1
print(s.compareVersion('1', '1.2'))  # -1
print(s.compareVersion('1.0', '1'))  # 0
print(s.compareVersion('1.2.3', '2'))  # -1
print(s.compareVersion('2', '1.2.3'))  # 1
print(s.compareVersion('1.2.3', '1.2.4'))  # -1
print(s.compareVersion('1.2.3', '1.3.4'))  # -1
print(s.compareVersion('0.0.0', '0'))  # 0
print(s.compareVersion('0', '0'))  # 0
print(s.compareVersion('0', '0.0.0.1'))  # -1
print(s.compareVersion('0.0.0.0.2', '0.0.0.1'))  # -1
print(s.compareVersion('0.2.0.0.2', '0.0.0.1'))  # 1
