class Solution(object):
    def anagramMappings(self, A, B):
        """
        :type A: List[int]
        :type B: List[int]
        :rtype: List[int]
        """
        ms = collections.defaultdict(list)
        for i, x in enumerate(B):
            ms[x].append(i)
        return [ms[x].pop() for x in A]
