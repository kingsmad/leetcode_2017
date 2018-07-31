class Solution(object):
    def shiftingLetters(self, S, shifts):
        """
        :type S: str
        :type shifts: List[int]
        :rtype: str
        """
        n = len(S)
        s = list(S)
        tot = 0
        for i in reversed(range(n)):
            tot += shifts[i]
            c = chr((ord(s[i]) - ord('a') + tot) % 26 + ord('a'))
            s[i] = c

        return ''.join(s)
