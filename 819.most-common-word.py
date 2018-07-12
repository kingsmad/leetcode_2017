class Solution(object):
    def mostCommonWord(self, paragraph, banned):
        """
        :type paragraph: str
        :type banned: List[str]
        :rtype: str
        """
        banned = set(banned)
        para = [s.strip("!?',;.") for s in paragraph.lower().split(' ')]
        strs = [w for w in para if w not in banned]
        wcnt = {w : 0 for w in strs}
        for w in strs:
            wcnt[w] += 1
        return max(wcnt, key=lambda k: wcnt[k])
