class Solution(object):
    def similarRGB(self, color):
        """
        :type color: str
        :rtype: str
        """
        ir, ig, ib = (int(color[x:x+2], 16) for x in (1, 3, 5))

        ans = ()
        delta = 0x7FFFFFFF
        for r in range(16):
            for g in range(16):
                for b in range(16):
                    dif = sum((i - c * 17) ** 2 for i, c in zip((ir, ig, ib), (r, g, b)))
                    if dif < delta:
                        delta = dif
                        ans = r, g, b
        return '#' + ''.join(hex(c)[2] * 2 for c in ans)

