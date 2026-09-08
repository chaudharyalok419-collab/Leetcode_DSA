class Solution {
public:
  vector<vector<int>>dp;
   int helper( string &s,string &t , int i, int j )
     {
        if (j<0)
            return 1;
             if (i<0)
               return 0;
               if (dp[i+1][j+1]!=-1)
                 return dp[i+1][j+1];
                  

           int skip=helper (s ,t ,i-1,j);
           int take=0;
           if (s[i]==t[j])
              take = helper(s,t,i-1,j-1);
             return dp[i+1][j+1]=take+skip;
     }
    int numDistinct(string s, string t) {
         dp.resize(s.size()+1,vector<int>(t.size()+1,-1));
        return helper(s,t,s.size()-1,t.size()-1);
        
    }
};