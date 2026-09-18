class Solution(object):
    def isAnagram(self, s, t):
        map={}
        for c in s :
            if c not in map:
               map[c]=1
            else:
                map[c]+=1
        for c in t:
            if c not in map:
                return False
            else:
                 map[c]-=1
        for x in map:
          if map[x]!=0:
             return False
        return True
        