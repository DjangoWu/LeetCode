class Solution(object):
    def trailingZeroes(self, n):
        """
        :type n: int
        :rtype: int
        """
        num = 0
        while n > 0:
            num = num + n / 5
            n = n / 5
        return num