class Solution(object):
    def allPathsSourceTarget(self, graph):
        """
        :type graph: List[List[int]]
        :rtype: List[List[int]]
        """
        n = len(graph)
        ans = []
        def dfs(u, path):
            path.append(u)
            if u == n-1:
                ans.append(copy.deepcopy(path))
            else:
                for v in graph[u]:
                    dfs(v, path)
            path.pop()

        dfs(0, [])
        return ans

