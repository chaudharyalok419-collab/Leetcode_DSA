class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int a=*min_element(nums.begin(),nums.end());
        int t=0;
        for (int i : nums)
        if (i&1)t=1;
    
        if (t && a%2==0)
           return false ;
        return true;
      
    }
};