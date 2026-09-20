class Solution(object):
    def reverseDegree(self, s):
        """
        :type s: str
        :rtype: int
        """
        ans=0
        for i in range(len(s)):
            ans+=(26+ord('a')-ord(s[i]))*(i+1)
        return ans

        