class Solution(object):
    def loudAndRich(self, richer, quiet):
        """
        :type richer: List[List[int]]
        :type quiet: List[int]
        :rtype: List[int]
        """

        n = len(quiet)
        G = [[] for i in range(n)]
        for [u, v] in richer:
            G[v].append(u)

        ans = [-1 for i in range(n)]

        def dfs(u):
            if not G[u]:
                ans[u] = u
                return
            if ans[u] != -1:
                return

            x = u
            for v in G[u]:
                dfs(v)
                if quiet[ans[v]] < quiet[x]:
                    x = ans[v]
            ans[u] = x


        for i in range(n): dfs(i)
        return ans
