class Solution {
public:
    int m, n;
    vector<vector<int>> dir{{1,0},{-1,0},{0,1},{0,-1}};
    vector<vector<vector<int>>>dp;
    bool issafe(vector<vector<int>>& grid, int h, int i, int j)
    {
        if (grid[i][j] == 1)
            h--;

        if (h <= 0)
            return false;

        if (i == m-1 && j == n-1)
            return true;
            if (dp[i][j][h]!=-1)
               return dp[i][j][h];

        int temp = grid[i][j];
        grid[i][j] = 2;

        for (auto it : dir)
        {
            int I = i + it[0];
            int J = j + it[1];

            if (I >= 0 && I < m && J >= 0 && J < n && grid[I][J] != 2)
            {
                if (issafe(grid, h, I, J))
                    return  dp[i][j][h]=true;
            }
        }

        grid[i][j] = temp;

        return dp[i][j][h]=false;
    }

    bool findSafeWalk(vector<vector<int>>& grid, int h)
    {   
        m = grid.size();
        n = grid[0].size();
        dp.resize(m,vector<vector<int>>(n,vector<int>(h+1,-1)));

        return issafe(grid, h, 0, 0);
    }
};