class Solution {
public:
    const int MOD = 1e9 + 7;

    int dp[205][201][201];

    int solve(vector<int>& nums, int idx, int gcd1, int gcd2) {

        if (idx == nums.size()) {
            return (gcd1 == gcd2 && gcd1 != 0);
        }

        if (dp[idx][gcd1][gcd2] != -1)
            return dp[idx][gcd1][gcd2];

        long long ans = 0;

        
        ans += solve(nums, idx + 1, gcd1, gcd2);

       
        ans += solve(nums,idx + 1,gcd1 == 0 ? nums[idx] : gcd(gcd1, nums[idx]),gcd2);

       
        ans += solve(nums,idx + 1,gcd1,gcd2 == 0 ? nums[idx] : gcd(gcd2, nums[idx]));

        return dp[idx][gcd1][gcd2] = ans % MOD;
    }

    int subsequencePairCount(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0, 0, 0);
    }
};