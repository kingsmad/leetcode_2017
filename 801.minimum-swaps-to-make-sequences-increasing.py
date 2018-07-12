class Solution(object):
    def minSwap(self, A, B):
        """
        :type A: List[int]
        :type B: List[int]
        :rtype: int
        """
        n = len(A)
        dp = [[n, n] for i in range(n)]

        dp[0][1] = 1
        dp[0][0] = 0
        for i in range(1, n):
            if A[i] > A[i-1] and B[i] > B[i-1]:
                dp[i][0] = dp[i-1][0]
                dp[i][1] = dp[i-1][0] + 1
            if A[i] > B[i-1] and B[i] > A[i-1]:
                dp[i][0] = min(dp[i][0], dp[i-1][1])
                dp[i][1] = min(dp[i][1], dp[i-1][0])

        return min(dp[n-1][0], dp[n-1][1])

#sol = Solution()
#A = [1, 3, 5, 4]
#B = [1, 2, 3, 7]
#ans = sol.minSwap(A, B)
