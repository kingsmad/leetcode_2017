class Solution(object):
    def isNStraightHand(self, hand, W):
        """
        :type hand: List[int]
        :type W: int
        :rtype: bool
        """
        c = collections.Counter(hand)
        for i in sorted(c):
            if c[i] > 0:
                for j in reversed(range(W)):
                    c[i+j] -= c[i]
                    if c[i+j] < 0:
                        return False
        return True
