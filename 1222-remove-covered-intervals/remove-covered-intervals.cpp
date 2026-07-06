class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end(), [](vector<int> &a, vector<int> &b) {
      if ( a[0]== b[0])
        return a[1]>b[1];
        else return 
           a[0]<b[0];
});
     int count=1;
     for (int i=0;i<arr.size()-1;i++)
       {
          if (arr[i][1]<arr[i+1][1])
               count++;
           else 
           {
             arr[i+1]=arr[i];
           }

       }


     return count;   
    }
};