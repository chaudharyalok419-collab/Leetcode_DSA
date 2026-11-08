class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
          int ans=0;
       for (auto & i : arr1)
         {  bool f=0;
            for (auto & j : arr2)
             {
                if (abs(i-j)<=d)
                    f=1;
             }
             if (!f)ans++;
         }
         return ans;
    }
};