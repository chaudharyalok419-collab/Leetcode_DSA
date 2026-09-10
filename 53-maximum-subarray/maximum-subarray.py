class Solution(object):
    def maxSubArray(self, nums):
        sum=0
        maxsum=-1e9
        for x in nums:
            sum+=x
            maxsum=max(sum,maxsum)
            if sum<0:
                sum=0
        return maxsum