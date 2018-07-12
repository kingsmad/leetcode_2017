class Solution(object):
    def longestMountain(self, A):
        """
        :type A: List[int]
        :rtype: int
        """

        n = len(A)
        p = 0
        ans = 0
        while p < n:
            q = p + 1
            up = False; down = False
            while q < n and A[q] > A[q-1]:
                q += 1
                up = True
            while q < n and A[q] < A[q-1]:
                q += 1
                down = True

            if up and down:
                ans = max(q - p, ans)
            if down:
                p = q - 1
            else:
                p = q

        return ans
