
class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {

        sort(logs.begin(), logs.end(),
        [](auto &a, auto &b) {
            return a[1] < b[1];
        });

        vector<pair<int,int>> q;

        for(int i = 0; i < queries.size(); i++)
            q.push_back({queries[i], i});

        sort(q.begin(), q.end());

        vector<int> freq(n + 1, 0);
        vector<int> ans(queries.size());

        int l = 0, r = 0, cnt = 0;

        for(auto p : q) {

            int start = p.first - x;
            int end = p.first;

            while(r < logs.size() && logs[r][1] <= end) {
                int s = logs[r][0];

                if(freq[s] == 0) cnt++;

                freq[s]++;
                r++;
            }

            while(l < r && logs[l][1] < start) {
                int s = logs[l][0];

                freq[s]--;

                if(freq[s] == 0) cnt--;

                l++;
            }

            ans[p.second] = n - cnt;
        }

        return ans;
    }
};
