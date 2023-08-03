class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        hashset = set()

        left = right = 0 
        
        while right < len(nums):
            if nums[right] not in hashset:
                hashset.add(nums[right])
                nums[left], nums[right] = nums[right], nums[left]
                left += 1
            right += 1           
        
        return left