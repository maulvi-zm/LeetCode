class Solution(object):
    def findDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        hashset = set()

        for i in range(len(nums)):
            if nums[i] in hashset:
                return nums[i]
            else:
                hashset.add(nums[i])
        