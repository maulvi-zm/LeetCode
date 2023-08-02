class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """

        numberMap = {}

        for i in range(len(nums)):
            diff = target - nums[i]

            if diff in numberMap:
                return [numberMap[diff], i]
            
            numberMap[nums[i]] = i 
