class Solution(object):
    def solveSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        

if __name__ == '__main__':
    sudoku = [['53..7....'],
              ['6..195...'],
              ['.98....6.'],
              ['8...6...3'],
              ['4..8.3..1'],
              ['7...2...6'],
              ['.6....28.'],
              ['...419..5'],
              ['....8..79']]
    Solution().solveSudoku(sudoku)
    import pprint
    pprint.pprint(sudoku)
