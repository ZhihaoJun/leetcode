class Solution:
    characters = {
        1: 'I',
        5: 'V',
        10: 'X',
        50: 'L',
        100: 'C',
        500: 'D',
        1000: 'M'
    }

    # @return a string
    def intToRoman(self, num):
        num_str = str(num)
        str_len = len(num_str)
        for i, n in enumerate(num_str):
            if n != '0':
                10**(str_len-i)