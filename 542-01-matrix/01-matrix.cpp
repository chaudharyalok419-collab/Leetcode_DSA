class Solution {
public:
int n;int m;
   vector<vector <int>>dir {{1,0},{-1,0},{0,1},{0,-1}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
         n=mat.size();
         m=mat[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>> res(n, vector<int>(m, 1e9));
        for (int i=0;i<n;i++) 
         { 
            for (int j=0;j<m;j++)
            {
                if (mat[i][j]==0)
                 {
                   res[i][j]=0;
                   q.push({i,j});
                 }
            }

         }
         while (!q.empty())
         {
            auto[i,j]=q.front();
            q.pop();
            for (vector<int> &v :dir)
            { int ni=i+v[0];
               int nj=j+v[1];
               if (ni>=0 && ni<n && nj>=0 && nj<m && res[ni][nj]==1e9)
                 {  
                    res[ni][nj]=min(res[i][j]+1,res[ni][nj]);
                    q.push({ni,nj});
                 }

            }

         }
       
    return res;
        
    }
};