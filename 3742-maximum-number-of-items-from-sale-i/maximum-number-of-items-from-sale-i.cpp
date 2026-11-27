class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n=items.size();
        int minp=items[0][1]; 
        int sum=0;
        vector<int>val(n,1);
        vector<int>wei(n,0);
        
        for (int i=0;i<items.size();++i)
            {wei[i]=items[i][1];
                minp=min(minp,wei[i]);
                sum+=wei[i];
             for (int j=0;j<n;++j)
                 {
                     if (i!=j && items[j][0]%items[i][0]==0)
                         val[i]++;
                         
                 }

            }
        int maw=min(budget,sum);
        vector<int>dp(maw+1,-1);
        dp[0]=0;
        for (int i=0;i<n;++i)
            {
                int w=wei[i];
                int v=val[i];
            for (int j=maw;j>=w;--j)
                {
                    if (dp[j-w]!=-1)
                        dp[j]=max(dp[j],dp[j-w]+v);
                }
            }
        int maxitem=0;
        for (int w=0;w<=maw;++w)
            {
                if (dp[w]!=-1)
                {
                    int extra=(budget-w)/minp;
                    maxitem=max(maxitem,dp[w]+extra);
                }
            }
        return maxitem;
    }
};