import pdb
class Solution(object):
    def boldWords(self, words, S):
        """
        :type words: List[str]
        :type S: str
        :rtype: str
        """
        n = len(S)
        bold = [0] * n
        for word in words:
            st = 0
            while st < n:
                p = S[st:].find(word)
                if (p < 0) : break
                for x in range(st+p, st+p+len(word)):
                    bold[x] = 1
                st += p + 1
        ans = ''
        p = 0
        while p < n:
            if bold[p] == 0:
                ans += S[p]
                p += 1
                continue
            q = p + 1
            while q<n and bold[q] == 1: q = q+1
            ans += ('<b>')
            ans += S[p:q]
            ans += ('</b>')
            p = q
        return ans
