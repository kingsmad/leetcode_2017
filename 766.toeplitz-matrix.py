class Solution(object):
    def isToeplitzMatrix(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: bool
        """
        row = len(matrix); col = len(matrix[0])
        for i in range(0, row):
            if not self.check(matrix, i, 0): return False
        for j in range(0, col):
            if not self.check(matrix, 0, j): return False
        return True

    def check(self, matrix, r, c):
        row = len(matrix); col = len(matrix[0])
        p = r; q = c
        while p < row and q < col:
            if matrix[p][q] != matrix[r][c]: return False
            p += 1; q += 1
        return True



