class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<vector<int>>>mpp;
    
      for (auto it: roads )
       {
          int u= it[0];
          int v= it[1];
          int w= it [2];
          mpp[u].push_back({v,w});
          mpp[v].push_back({u,w});

       }
        vector<bool>vis(n+1,0);
        int ans=INT_MAX;
        queue<int>q;
       q.push(1);
       while (!q.empty())
       { int a= q.front() ;
          q.pop();
          vis[a]=1;
          for (auto it: mpp[a])
            {
                int v= it[0];
                int wt= it[1];
                ans=min(ans,wt);
                 if (!vis[v])
                 q.push(v);
            }
       }
       return ans;
        
    }
};