class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
     unordered_map<int,int> mpp;
       mpp[0]=1;
       int sum=0;
       int count=0;
     for(int i: nums)
     {
        sum+=i;
         count+=mpp[sum-k];
         mpp[sum]++;
     }
       return count;
        
    }
};