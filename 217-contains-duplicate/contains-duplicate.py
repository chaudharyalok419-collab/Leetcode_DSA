class Solution(object):
    def containsDuplicate(self, nums):
        s=set()
        for x in nums:
           s.add(x)
        return len(s)!=len(nums)
        