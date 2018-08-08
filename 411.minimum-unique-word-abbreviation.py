# https://leetcode.com/problems/minimum-unique-word-abbreviation/discuss/89884/Python-with-bit-masks
class Solution(object):
    def minAbbreviation(self, target, dictionary):
        """
        :type target: str
        :type dictionary: List[str]
        :rtype: str
        """
        n = len(target)
        diffs = {sum(2**i for i, c in enumerate(w) if target[i] != c) \
                for w in dictionary if len(w) == n}
        if not diffs:
            return str(n)

        bits = max((i for i in range(2**n) if all(d & i for d in diffs)), \
                key = lambda bits: sum((bits >> i) & 3 == 0 for i in range(n-1)))

        s = ''.join(target[i] if bits & 2**i else '#' for i in range(n))

        return re.sub('#+', lambda m: str(len(m.group())), s)


