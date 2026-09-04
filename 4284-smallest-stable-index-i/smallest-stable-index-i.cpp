class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
      int n=nums.size();
      vector<int>ans(n,0);
      int mx=INT_MIN;
      for (int i=0;i<n;i++)
      {
         mx=max(mx,nums[i]);
         ans[i]=mx;
      }
      int mn=INT_MAX;
      int t=-1;
      for (int i=n-1;i>=0;i--)
      {mn=min(mn,nums[i]);
       if (ans[i]-mn <=k)
           t=i;
      }
     return t;   
    }
};