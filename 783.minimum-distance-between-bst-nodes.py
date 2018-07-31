import sys
# Definition for a binary tree node.
class TreeNode(object):
     def __init__(self, x):
         self.val = x
         self.left = None
         self.right = None

class Solution(object):
    def minDiffInBST(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        vals = []
        self.dfs(root, vals)
        diff = []
        for i in range(0, len(vals)-1):
            diff.append(vals[i+1] - vals[i])
        return min(diff)

    def dfs(self, root, vals):
        if root == None: return
        self.dfs(root.left, vals)
        vals.append(root.val)
        self.dfs(root.right, vals)
        return




