class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int active=0;
        for(char c: s)
          {
            if (c=='1')
              active++;
          }
        vector<int>ans;
       int i=0;
         while (i<s.size())
           {
                if (s[i]=='0')
                     {
                        int st=i;
                        while (i<s.size() && s[i]=='0')
                            i++;
                        int size= i-st;
                         ans.push_back(size);
                     }
                     else 
                     i++;
           }
           int mx= 0;
           for (int i=1;i<ans.size();i++)
            {
                mx= max(mx,ans[i-1]+ans[i]);
            }
            return mx+active;
        
    }
};