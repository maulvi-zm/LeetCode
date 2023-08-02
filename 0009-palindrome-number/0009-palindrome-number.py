class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """

        if x < 0:
            return False
        
        a, y = x, 0 

        while a > 0:
            y = y * 10 + a % 10
            a = a // 10

        return x == y  