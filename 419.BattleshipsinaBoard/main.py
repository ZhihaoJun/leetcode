class Solution(object):
    def init(self, board):
        self.board = board
        self.w = len(board[0])
        self.h = len(board)
        self.count = 0
    
    def get(self, x, y):
        return self.board[y][x]
    
    def left(self, x, y):
        if x == 0:
            return '.'
        return self.board[y][x-1]
    
    def up(self, x, y):
        if y == 0:
            return '.'
        return self.board[y-1][x]
    
    def isBattleship(self, c):
        return c == 'X'

    def countBattleships(self, board):
        """
        :type board: List[List[str]]
        :rtype: int
        """
        self.init(board)

        for y in xrange(self.h):
            for x in xrange(self.w):
                c = self.get(x, y)
                if (self.isBattleship(c) and
                    not self.isBattleship(self.left(x, y)) and
                    not self.isBattleship(self.up(x, y))):

                    self.count += 1

        return self.count

def main():
    board = ["X..X","...X","...X"]
    print Solution().countBattleships(board)

if __name__ == '__main__':
    main()
