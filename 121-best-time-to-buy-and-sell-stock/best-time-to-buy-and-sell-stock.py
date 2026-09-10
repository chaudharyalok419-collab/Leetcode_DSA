class Solution(object):
    def maxProfit(self, prices):
       mi=prices[0]
       ans=0
       for x in prices:
              mi=min(mi,x)
              ans=max(ans,x-mi)
       return ans
           
        