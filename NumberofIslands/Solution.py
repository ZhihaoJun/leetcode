# Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

# Example 1:

# 11110
# 11010
# 11000
# 00000
# Answer: 1

# Example 2:

# 11000
# 11000
# 00100
# 00011
# Answer: 3

# Credits:
# Special thanks to @mithmatt for adding this problem and creating all test cases.
from pprint import pprint

class Solution:
    # @param {character[][]} grid
    # @return {integer}
    def numIslands(self, grid):
        self.height = len(grid)
        try:
            self.width = len(grid[0])
        except IndexError:
            return 0
        if self.width == 0 or self.height == 0:
            return 0
        self.visit = [[False for x in xrange(self.width)] for x in xrange(self.height)]
        islands = 0
        # print self.width, self.height
        # pprint(self.visit)
        for x in xrange(self.width):
            for y in xrange(self.height):
                if not self.visit[y][x] and grid[y][x] == 1:
                    self.dfs(grid, x, y)
                    islands += 1
        # pprint(self.visit)

        return islands

    def dfs(self, grid, x, y):
        if self.visit[y][x] or grid[y][x] == 0:
            return
        # print 'visit', x, y
        self.visit[y][x] = True
        if x-1 > 0:
            self.dfs(grid, x-1, y)
        if y-1 > 0:
            self.dfs(grid, x, y-1)
        if x+1 < self.width:
            self.dfs(grid, x+1, y)
        if y+1 < self.height:
            self.dfs(grid, x, y+1)

grid = [
    [1, 1, 0, 0, 0],
    [1, 1, 0, 0, 0],
    [0, 0, 1, 0, 0],
    [0, 0, 0, 1, 1]
]

print Solution().numIslands(grid)
