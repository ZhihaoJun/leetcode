class Solution:
    # @param {integer[][]} matrix
    # @return {void} Do not return anything, modify matrix in-place instead.
    def setZeroes(self, matrix):
        # matrix[row][column]
        rows_num = len(matrix)
        columns_num = len(matrix[0])
        # True if the row or column contains 0
        rows = [False]*rows_num
        columns = [False]*columns_num

        for r in xrange(rows_num):
            for c in xrange(columns_num):
                if matrix[r][c] == 0:
                    rows[r] = True
                    columns[c] = True

        for r in xrange(rows_num):
            if rows[r]:
                matrix[r] = [0]*columns_num
        for c in xrange(columns_num):
            if columns[c]:
                for r in xrange(rows_num):
                    matrix[r][c] = 0


def main():
    matrix = [[1], [1]]
    Solution().setZeroes(matrix)
    print(matrix)

if __name__ == '__main__':
    main()
