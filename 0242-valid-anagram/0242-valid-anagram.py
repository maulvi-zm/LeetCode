class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """

        if len(s) != len(t):
            return False
        
        CountS = {}
        CountT = {}

        for i in range(len(s)):
            if s[i] in CountS:
                CountS[s[i]] += 1
            else:
                CountS[s[i]] = 1
                
            if t[i] in CountT:
                CountT[t[i]] += 1
            else:
                CountT[t[i]] = 1
        
        return CountS == CountT