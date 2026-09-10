class Solution(object):
    def containsDuplicate(self, nums):
        map={}
        count=0
        for x in nums:
            if x not in map:
              count+=1
            map[x]=1
        return count!=len(nums)
        