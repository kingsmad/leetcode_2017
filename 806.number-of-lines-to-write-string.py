class Solution(object):
    def numberOfLines(self, widths, S):
        """
        :type widths: List[int]
        :type S: str
        :rtype: List[int]
        """
        tot = 0
        line = 0
        for c in S:
            w = widths[ord(c) - ord('a')]
            tot += w
            if tot > 100:
                tot = w
                line += 1
        return [line+1, tot]



