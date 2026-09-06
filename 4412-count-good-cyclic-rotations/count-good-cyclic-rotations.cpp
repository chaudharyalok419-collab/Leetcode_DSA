class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
         int n= nums.size();
         long long  sum=accumulate(nums.begin(),nums.end(),0LL);
         long long  fhalf=accumulate(nums.begin(),nums.begin()+n/2,0LL);
         int count=0;
          int a=0;
          int b=n/2;
         for (int i=0; i<n;i++)
         {
              if(i!=0)
              {
                 fhalf=fhalf-nums[a%n]+nums[b%n];
                  b++;
                  a++;
              }
              if (fhalf>sum-fhalf)
                 count++;
         }
        return count;
    }
};