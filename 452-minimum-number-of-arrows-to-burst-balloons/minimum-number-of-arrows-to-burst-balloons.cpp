class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
       sort(points.begin(),points.end(),[](vector<int>&a,vector<int>&b)
       {
           return a[1]<b[1];
       });
         int count=1; 
          int shoot=points[0][1];
           
        for (int idx=1;idx<points.size();idx++)
        {        
            if (shoot>=points[idx][0] &&shoot<=points[idx][1])
                continue;
            else {
                  count++;
                  shoot=points[idx][1];
            } 
        }
        return count;
    }
};