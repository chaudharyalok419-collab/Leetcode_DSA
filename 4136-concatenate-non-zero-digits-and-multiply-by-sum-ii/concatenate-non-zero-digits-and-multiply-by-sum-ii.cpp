class Solution {
public:
    int MOD = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<long long> power(n + 1);
        power[0] = 1;
        for (int i = 1; i <= n; i++) {
            power[i] = (power[i - 1] * 10) % MOD;
        }
        vector<int> prefixSum(n + 1, 0);
        vector<int> nonZeroCount(n + 1, 0);
        vector<long long> prefixValue(n + 1, 0);

        for (int i = 0; i < n; i++) {
            int digit = s[i] - '0';

            prefixSum[i + 1] = prefixSum[i] + digit;
            nonZeroCount[i + 1] = nonZeroCount[i];

            if (digit != 0) {
                nonZeroCount[i + 1]++;
                prefixValue[i + 1] = (prefixValue[i] * 10 + digit) % MOD;
            } else {
                prefixValue[i + 1] = prefixValue[i];
            }
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];

            int sum = prefixSum[r + 1] - prefixSum[l];
            int cnt = nonZeroCount[r + 1] - nonZeroCount[l];

            long long num =
                (prefixValue[r + 1] -
                 (prefixValue[l] * power[cnt]) % MOD +
                 MOD) % MOD;

            ans.push_back((num * sum) % MOD);
        }

        return ans;
    }
};