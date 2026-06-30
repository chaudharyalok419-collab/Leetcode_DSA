class Solution {
public:
    int numberOfSubstrings(string s) {
         vector<int>hash(3,-1);
          int l=0;
          int rt=0;
          int count=0;
          while (rt<s.size())
           {
             hash[s[rt]-'a']++;
              rt++;
             while (hash[0]>=0 && hash[1]>=0 && hash[2]>=0)
               {  count+=s.size()-rt+1;
                  hash[s[l]-'a']--;
                  l++;
               }

           }

   
     return count ;
    }
};