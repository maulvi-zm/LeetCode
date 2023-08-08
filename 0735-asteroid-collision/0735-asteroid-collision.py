class Solution(object):
    def asteroidCollision(self, asteroids):
        """
        :type asteroids: List[int]
        :rtype: List[int]
        """
        i = 0 

        while i < len(asteroids)-1:
            if asteroids[i] > 0 and asteroids[i+1] < 0:
                if abs(asteroids[i+1]) > asteroids[i]:
                    asteroids.pop(i)
                    i -= 2
                elif abs(asteroids[i+1]) == asteroids[i]:
                    asteroids.pop(i+1)
                    asteroids.pop(i)
                    i -= 2
                else:
                    asteroids.pop(i+1)
                    i -= 1
            
            i += 1

            if i < 0:
                i = 0 
        
        return asteroids