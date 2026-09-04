class Solution {
public:
   vector<int>dp;
   int ways(string &s ,int i)
   {  if (i<0)
       return 1;
      if (dp[i+1]!=-1)
        return dp[i+1];
       int take1=0;
          if (s[i]!='0')
             take1=ways(s,i-1);
       int take2=0;
        if (i>=1)
          {  int a= (s[i-1]-'0')*10+(s[i]-'0');
            if (a>9 && a<27)
              take2=ways(s,i-2);
          }
     return  dp[i+1]=take1+take2;
   }

    int numDecodings(string s) {
        dp.resize(s.size()+1,-1);
        return ways(s,s.size()-1);
    
    }
};