class Solution(object):
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """

        left = 1
        right = x 

        while left <= right:

            mid = (left + right) // 2

            if mid < x / mid:
                left = mid + 1
            elif mid > x / mid:
                right = mid - 1
            else:
                return mid
        
        return left - 1
