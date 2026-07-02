class Solution {
public:
    int m, n;
    vector<vector<int>> dir{{1,0},{-1,0},{0,1},{0,-1}};
    bool findSafeWalk(vector<vector<int>>& grid, int h)
    {      

            n=grid.size();
            m= grid[0].size();
            vector<vector<int>>ans(n,vector<int>(m,INT_MAX)); 
            queue<pair<int,int>>q;
            ans[0][0]=grid[0][0];
            q.push({0,0});
            while (!q.empty())
            {
                auto it = q.front();
                q.pop();
                int x= it.first;
                int y= it.second;
                for (auto t: dir)
                {
                    int i= t[0]+x;
                    int j= t[1]+y;
                    if (i>=0 && i<n && j>=0 && j<m)
                    {                               
                       int a= ans[x][y]+grid[i][j];
                       if (ans[i][j]>a)
                       {
                        ans[i][j]=a;
                        q.push({i,j});
                       }
                     

                    }
                }
            }




        return (h>ans[n-1][m-1]);
        
        
    }
};