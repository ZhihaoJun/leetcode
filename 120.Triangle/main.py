class Solution(object):
    def get(self, x, y):
        return self.f[y][x]
      
    def set(self, x, y, v):
        if y not in self.f:
            self.f[y] = {}
        self.f[y][x] = v

    def value(self, x, y):
        return self.triangle[y][x]

    def cal(self, x, y):
        if y == self.size-1:
            self.set(x, y, self.value(x, y))
        else:
            m = min(self.get(x, y+1), self.get(x+1, y+1))
            self.set(x, y, m+self.value(x, y))
        return self.get(x, y)

    def minimumTotal(self, triangle):
        """
        :type triangle: List[List[int]]
        :rtype: int
        """
        self.size = len(triangle)
        self.triangle = triangle
        self.f = {}

        for y in xrange(self.size-1, -1, -1):
            for x in xrange(y+1):
                self.cal(x, y)

        return self.cal(0, 0)

def main():
    triangle = [
        [2],
        [3, 4],
        [6, 5, 7],
        [4, 1, 8, 3]
    ]
    triangle = [[0]]
    print Solution().minimumTotal(triangle)

if __name__ == '__main__':
    main()
