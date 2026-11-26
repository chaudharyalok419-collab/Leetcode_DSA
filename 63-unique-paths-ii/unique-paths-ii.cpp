class Solution {
public:
    int m, n;

    int solve(int i, int j, vector<vector<int>>& obs,
              vector<vector<int>>& dp) {

        if (i < 0 || j < 0)
            return 0;

        if (obs[i][j])
            return 0;

        if (i == 0 && j == 0)
            return 1;

        if (dp[i][j] != -1)
            return dp[i][j];

        int left = solve(i - 1, j, obs, dp);
        int right = solve(i, j - 1, obs, dp);

        return dp[i][j] = left + right;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
        m = obs.size();
        n = obs[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(m - 1, n - 1, obs, dp);
    }
};