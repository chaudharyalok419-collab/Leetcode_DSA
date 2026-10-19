class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
      vector<int>ans;
      int less=0;
      int equal=0;
      for (auto & i : nums)
      {
        if (i==target)
           equal+=1;
        else if (i<target)
            less+=1;
      }
      for(int i=less;i<less+equal;i++)
            ans.push_back(i);
       return ans;
    }
};