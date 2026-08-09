class Solution {
public:
    vector<vector<vector<int>>> dp;

    int helper(vector<int>& piles, int m, int i, bool p) {
        int n = piles.size();
        if (i >= n) return 0;
        if (dp[m][i][p] != -1) return dp[m][i][p];
        int result = (p ? INT_MIN : INT_MAX);
        int stone = 0;
        for (int x = 1; x <= min(2 * m, n - i); x++) {
            stone += piles[i + x - 1];
            if (p) result = max(result,stone + helper(piles, max(m, x), i + x, 0));
            else result = min(result,helper(piles, max(m, x), i + x, 1));   
        }
        return dp[m][i][p] = result;
    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        dp.resize(n + 1,vector<vector<int>>(n + 1,vector<int>(2, -1)));
        return helper(piles, 1, 0, 1);
    }
};