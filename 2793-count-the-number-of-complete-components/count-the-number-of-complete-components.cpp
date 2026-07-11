class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<bool>visited(n,0);
        unordered_map<int,vector<int>>mpp;
        for (auto & it: edges )
        {
            int u =it[0];
            int v= it[1];
            mpp[u].push_back(v);
            mpp[v].push_back(u);
        }
        queue<int>q;
        int ans=0;
        for (int i=0;i<n;i++)
        {
            if (!visited[i])
              {  
                q.push(i);
                  visited[i]=1;
                 int nodes=0;
                 int edges=0;
                while (!q.empty())
                {
                    int a= q.front();
                       q.pop();
                      nodes++;
                      edges+=mpp[a].size();
                     for (auto & it :mpp[a])
                     {    if (!visited[it])
                            {
                            visited[it]=1;
                            q.push(it);
                             }

                     }
                }   edges/=2;
                if (edges==(nodes*(nodes-1)/2))
                   ans++;
              }
        }
        return ans;
        
    }
};