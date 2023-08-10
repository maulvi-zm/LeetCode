class Solution(object):
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """

        def nextNumber(n):
            new = 0 
            while n != 0:
                new += (n % 10) ** 2
                n = n // 10 
            return new
        
        slow = n
        fast = nextNumber(n)

        while fast != 1:
            slow = nextNumber(slow)
            fast = nextNumber(nextNumber(fast))

            if slow == fast:
                return False
        
        return True
        

