class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>map(101,0);
        for (int i: nums)
         map[i]++;
        vector<int>ans;
        while (ans.size()!=nums.size())
        {
            for (int i =1;i<101;i++)
              {
                if (map[i]>0)
                  { ans.push_back(i);
                    map[i]--;
                  }
              }
        }
        return ans;
    }
};