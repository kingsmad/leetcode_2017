class Solution(object):
    def numMagicSquaresInside(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        row = len(grid)
        if row == 0:  return 0
        col = len(grid[0])

        def check(x, y):
            if x+2 >= row or y+2 >= col:
                return 0

            v = grid[x][y] + grid[x+2][y+2]
            if v != grid[x][y+2] + grid[x+2][y] or v != grid[x][y+1] + \
                    grid[x+2][y+1] or v != grid[x+1][y] + grid[x+1][y+2]:
                        return 0

            ms = set()
            for i in range(0, 3):
                for j in range(0, 3):
                    v = grid[x+i][y+j]
                    if v >= 10 or v < 1 or v in ms:
                        return 0
                    ms.add(v)
            return 1

        cnt = 0
        for i in range(0, row):
            for j in range(0, col):
                cnt += check(i, j)

        return cnt
