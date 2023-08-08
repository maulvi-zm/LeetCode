class Solution(object):
    def asteroidCollision(self, asteroids):
        """
        :type asteroids: List[int]
        :rtype: List[int]
        """
        
        stack = []

        i = 0 

        while i < len(asteroids):
            if asteroids[i] > 0:
                stack.append(asteroids[i])
            else:
                while stack and -1 * asteroids[i] > stack[-1] and stack[-1] > 0:
                    stack.pop()
                
                if not stack:
                    stack.append(asteroids[i])
                elif stack[-1] == -1 * asteroids[i]:
                    stack.pop()
                elif stack[-1] < 0:
                    stack.append(asteroids[i])

            i += 1
        
        return stack