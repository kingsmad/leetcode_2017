class Solution(object):
    def pushDominoes(self, dominoes):
        """
        :type dominoes: str
        :rtype: str
        """
        ans = [v for v in dominoes]
        n = len(dominoes)
        ms = []
        for i, v in enumerate(dominoes):
            if v != '.':
                ms.append(i)

        while ms:
            act = { }
            for i in ms:
                if ans[i] == 'R':
                    if i+1 < n and ans[i+1] == '.' and not (i+2<n and ans[i+2] == 'L'):
                        act[i+1] = 'R'
                if ans[i] == 'L':
                    if i-1 >= 0 and ans[i-1] == '.' and not (i-2>=0 and ans[i-2] == 'R'):
                        act[i-1] = 'L'
            for (i, v) in act.items():
                ans[i] = v
            ms = [i for i in act.keys()]
        return ''.join(ans)

