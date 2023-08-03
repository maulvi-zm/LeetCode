class Solution(object):
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """

        left = 0 
        right = 0 

        # Sliding Window
        while left < len(haystack):
            if haystack[left] == needle[right]:
                right += 1
            else:
                left -= right
                right = 0 

            if right == len(needle):
                return left - right + 1
            
            left += 1
                        
        return -1
            