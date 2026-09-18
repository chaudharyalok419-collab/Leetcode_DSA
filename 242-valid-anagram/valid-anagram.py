class Solution(object):
    def isAnagram(self, s, t):
        map=[0]*26
        for c in s :
            map[ord(c)-ord('a')]+=1
        for c in t:
             map[ord(c)-ord('a')]-=1
               
        for x in map:
          if x!=0:
             return False
        return True
        