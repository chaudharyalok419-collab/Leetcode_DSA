class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
      vector<int>grp(n,0);
      int cg =0;
       for (int i=1;i<n;i++)
         {
            if (nums[i]-nums[i-1]>maxDiff)
              {
                cg++;
              }
              grp[i]=cg;
         }
          vector<bool>ans;
           for (auto it: queries )
           {
            int u= it[0];
            int v= it[1];
            if (grp[v]==grp[u])
            ans.push_back(1);
            else 
            ans.push_back(0);

           }
           return ans;
    }
};