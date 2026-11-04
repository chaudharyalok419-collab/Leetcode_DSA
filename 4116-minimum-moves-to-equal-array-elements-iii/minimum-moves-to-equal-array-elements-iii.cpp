class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = *max_element(nums.begin(),nums.end());
        int m = accumulate(nums.begin(),nums.end(),0);
        return nums.size()*n-m;
    }
};