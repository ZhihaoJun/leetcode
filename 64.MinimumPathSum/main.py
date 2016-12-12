class Solution(object):
    def init(self, grid):
        self.grid = grid
        self.m = len(grid[0])
        self.n = len(grid)
        self.dp = [[0 for i in xrange(self.m)] for j in xrange(self.n)]

    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        self.init(grid)

        # border cases
        self.dp[0][0] = self.grid[0][0]
        for i in xrange(1, self.m):
            self.dp[0][i] = self.dp[0][i-1] + self.grid[0][i]
        
        for j in xrange(1, self.n):
            self.dp[j][0] = self.dp[j-1][0] + self.grid[j][0]
        
        for i in xrange(1, self.n):
            for j in xrange(1, self.m):
                self.dp[i][j] = min(self.dp[i-1][j], self.dp[i][j-1]) + self.grid[i][j]

        return self.dp[self.n-1][self.m-1]

def main():
    grid = [
      [0, 1, 2, 100],
      [1, 4, 1, 5],
      [0, 0, 0, 1]
    ]
    print Solution().minPathSum(grid)

if __name__ == '__main__':
    main()
