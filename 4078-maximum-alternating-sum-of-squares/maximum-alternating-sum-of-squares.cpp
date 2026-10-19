class Solution {
public:
  static bool cmp(int a ,int  b ){
     return abs(a)<abs(b);}

    long long maxAlternatingSum(vector<int>& nums) {
        sort(nums.begin(),nums.end(),cmp);
        long long ans=0;
        int n= nums.size()-1;
        if (!(n&1)){ans+=nums[n]*nums[n];n-=1;}
        int l=0;
        int h=n;
        while (h>l)
        {
            ans+=nums[h]*nums[h];
            ans-=nums[l]*nums[l];
            h--;
            l++;
        }
           return ans;

    }
};