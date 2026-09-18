class Solution(object):
    def maxArea(self, hi):
        l=0
        h=len(hi)-1
        ans=0
        while l<h:
            ans=max(ans,min(hi[l],hi[h])*(h-l))
            if (hi[l]>hi[h]):
               h-=1
            else:
                l+=1
        return ans