class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {

        vector<pair<int, int>> arr;
        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        sort(arr.begin(), arr.end());

        vector<int> position(n);
        for (int i = 0; i < n; i++) {
            position[arr[i].second] = i;
        }

        vector<int> farthest(n);

        int right = 0;
        for (int left = 0; left < n; left++) {
            while (right + 1 < n &&
                   arr[right + 1].first - arr[left].first <= maxDiff) {
                right++;
            }
            farthest[left] = right;
        }

        vector<int> component(n);
        int comp = 0;
        component[0] = 0;

        for (int i = 1; i < n; i++) {
            if (arr[i].first - arr[i - 1].first > maxDiff) {
                comp++;
            }
            component[i] = comp;
        }

        const int LOG = 18;
        vector<vector<int>> jump(LOG, vector<int>(n));

        for (int i = 0; i < n; i++) {
            jump[0][i] = farthest[i];
        }

        for (int k = 1; k < LOG; k++) {
            for (int i = 0; i < n; i++) {
                jump[k][i] = jump[k - 1][jump[k - 1][i]];
            }
        }

        vector<int> answer;

        for (auto &query : queries) {
            int u = position[query[0]];
            int v = position[query[1]];

            if (u > v) {
                swap(u, v);
            }

            if (component[u] != component[v]) {
                answer.push_back(-1);
                continue;
            }

            if (u == v) {
                answer.push_back(0);
                continue;
            }

            int current = u;
            int edges = 0;

            for (int k = LOG - 1; k >= 0; k--) {
                if (jump[k][current] < v) {
                    current = jump[k][current];
                    edges += (1 << k);
                }
            }

            answer.push_back(edges + 1);
        }

        return answer;
    }
};