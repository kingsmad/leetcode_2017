class Solution(object):
    def largeGroupPositions(self, S):
        """
        :type S: str
        :rtype: List[List[int]]
        """
        ans = []
        n = len(S)
        i = 0
        while i < n:
            q = i + 1
            while q < n and S[q] == S[i]:
                q += 1
            if q - i >= 3:
                ans.append([i, q-1])
            i = q
        return ans


