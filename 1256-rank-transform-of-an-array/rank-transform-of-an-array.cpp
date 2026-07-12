class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
       vector<int>arr1= arr;
       sort(arr1.begin(),arr1.end());

       unordered_map<int,int>mpp;
         int t=1;
         arr1.push_back(1e9+7);
       for (int i=0;i<arr1.size()-1;i++)
         {
            mpp[arr1[i]]=t;
            if (arr1[i]!=arr1[i+1])
                t++;

         }


        vector<int>ans;
        for (int & i:  arr)
        {
            ans.push_back(mpp[i]);
        }

     return ans;   
    }
};