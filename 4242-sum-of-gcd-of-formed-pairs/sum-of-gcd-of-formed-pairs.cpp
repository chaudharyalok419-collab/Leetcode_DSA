class Solution {
public:
    long long gcdSum(vector<int>& nums) {
      int maxEle=INT_MIN;
        for (int i=0;i<nums.size();i++)
          {
               maxEle=max(maxEle,nums[i]);
                nums[i]=gcd(maxEle,nums[i]);
          }
          sort(nums.begin(),nums.end());
          int low=0;
          int high=nums.size()-1;
          long long ans=0;
          while (low<high)
          {
              ans+=gcd(nums[low],nums[high]);
              low++;
              high--;
          }
          return ans;
    }
};