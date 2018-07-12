class Solution(object):
    def toGoatLatin(self, S):
        """
        :type S: str
        :rtype: str
        """
        ans = []
        for i, w in enumerate(S.split()):
            latin = w
            if w[0].lower() not in 'aeiou':
                latin = w[1:] + w[0]
            latin += 'ma' + 'a' * (i+1)
            ans.append(latin)
        return ' '.join(ans)

