class Solution {
public:
    vector<int> visited;

    void bfs(queue<int>& q, int a, unordered_map<int, vector<int>>& mp) {
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (auto &it : mp[u]) {
                if (visited[it] == -1) {
                    visited[it] = a;
                    q.push(it);
                }
            }
        }
    }

    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int mD, vector<vector<int>>& queries) {

        visited.assign(n, -1);
        unordered_map<int, vector<int>> mp;
        vector<bool> ans;

       
        vector<pair<int,int>> arr;
        for (int i = 0; i < n; i++)
            arr.push_back({nums[i], i});

        sort(arr.begin(), arr.end());

        
        for (int i = 1; i < n; i++) {
            if (arr[i].first - arr[i - 1].first <= mD) {
                int u = arr[i].second;
                int v = arr[i - 1].second;

                mp[u].push_back(v);
                mp[v].push_back(u);
            }
        }

        queue<int> q;
        int comp = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i] == -1) {
                visited[i] = comp;
                q.push(i);
                bfs(q, comp, mp);
                comp++;
            }
        }

        for (auto &it : queries) {
            ans.push_back(visited[it[0]] == visited[it[1]]);
        }

        return ans;
    }
};