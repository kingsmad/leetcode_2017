class Solution(object):
    def backspaceCompare(self, S, T):
        """
        :type S: str
        :type T: str
        :rtype: bool
        """
        def proc(s):
            ans = []
            for c in s:
                if c == '#':
                    if len(ans) > 0:
                        ans.pop()
                else:
                    ans.append(c)
            return ''.join(ans)

        return proc(S) == proc(T)

