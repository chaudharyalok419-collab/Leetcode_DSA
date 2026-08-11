class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n=nums.size();
        int sum=nums[0];
        int prev=nums[0];
        for(int i=1;i<n;i++)
        {
           if(nums[i]==prev+1)
           {
            sum+=nums[i];
            prev=nums[i];
           }
           else
           break;
        }
       
        unordered_map<int,int>mpp;
         for(int i=0;i<n;i++)
         {
            mpp[nums[i]]++;
         }
         while(true)
         {
            if(mpp.find(sum)==mpp.end())
            break;
            else
            sum++;
         }
         return sum;
    }
};