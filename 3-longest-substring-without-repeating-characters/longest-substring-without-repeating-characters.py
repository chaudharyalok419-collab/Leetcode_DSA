class Solution(object):
    def lengthOfLongestSubstring(self, s):
        map={}
        l=0
        mxlen=0
        for i in range (len(s)):
            if s[i] in map :
                l=max(l,map[s[i]]+1)
            map[s[i]] =i
            mxlen=max(mxlen,i-l+1)
        return mxlen
        