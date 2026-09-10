class Solution(object):
    def twoSum(self, nums, target):
        map={}
        for i in range(len(nums)):
            x=target-nums[i]
            if x in map:
               return [map[x],i]
            map[nums[i]]=i
        return [-1,-1]