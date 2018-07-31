class Solution(object):
    def shortestToChar(self, S, C):
        """
        :type S: str
        :type C: str
        :rtype: List[int]
        """
        n = len(S)
        dis = [n] * n
        if S[0] == C:
            dis[0] = 0
        if S[n-1] == C:
            dis[n-1] = 0

        for i in range(1, n):
            dis[i] = min(dis[i-1] + 1, dis[i]) if S[i] != C else 0
        for i in range(0, n-1)[::-1]:
            dis[i] = min(dis[i+1] + 1, dis[i]) if S[i] != C else 0

        return dis

