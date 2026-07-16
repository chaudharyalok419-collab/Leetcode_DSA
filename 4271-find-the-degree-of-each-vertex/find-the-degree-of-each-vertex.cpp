class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& mat) {
         int n=mat.size();
         vector<int>ans(n,0);
         for (int i=0;i<mat.size();i++)
           {
               for (int j=0;j<mat[i].size();j++)
                 {
                       if ( i!=j && mat[i][j] )
                          {
                            
                            ans[j]++;
                          }
               
                 }
           }
           return ans;

    }
};