class Solution(object):
    def splitIntoFibonacci(self, S):
        """
        :type S: str
        :rtype: List[int]
        """
        n = len(S)
        for i in range(1, n):
            for j in range(i+1, n):
                v1 = int(S[0:i])
                v2 = int(S[i:j])

                if S[0:i] != str(v1) or S[i:j] != str(v2):
                    continue
                if not (0 <= v1 <= 0x7fffffff-1 and 0 <= v2 <= 0x7fffffff-1): continue

                p = j

                ok = True
                ans = [v1, v2]
                while p < n and ok:
                    tar = str(v1 + v2)
                    if not 0 <= v1+v2 <= 0x7fffffff-1: ok = False; break
                    for k, v in enumerate(tar):
                        if p+k>=n or S[p+k] != v: ok = False; break
                    if not ok:break

                    # good match, continue
                    ans.append(v1+v2)
                    p += len(tar)
                    v1, v2 = v2, v1+v2
                if ok: return ans
        return []
