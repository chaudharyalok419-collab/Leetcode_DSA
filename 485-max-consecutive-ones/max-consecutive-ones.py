class Solution(object):
    def findMaxConsecutiveOnes(self, nums):
       sum=0
       mx=0
       for x in nums:
           if x==1:
               sum+=1
               mx=max(sum,mx)
           else:
               sum=0
       return mx   