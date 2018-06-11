class Solution(object):
    def countPrimeSetBits(self, L, R):
        """
        :type L: int
        :type R: int
        :rtype: int
        """
        pr = [0] * 40
        tlist = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37]
        for d in tlist: pr[d] = 1

        cnt = 0
        for i in range(L, R+1):
            if pr[self.count_one(i)] == 1:
                cnt += 1
        return cnt

    def count_one(self, d):
        cnt = 0
        while d > 0:
            d -= (d & (-d))
            cnt += 1
        return cnt
