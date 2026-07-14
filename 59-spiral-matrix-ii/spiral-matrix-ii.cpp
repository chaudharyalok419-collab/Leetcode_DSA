class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int m = n;
         int left=0;
         int top=0;
         int right=n-1;
         int bot=m-1;
         int t=n*n;
          vector<vector<int>>mat;
          mat.resize(n,vector<int>(n,0));
          int val=1;
          while (left <=right && top<=bot)
            {   
                for (int i=left;i<=right;i++)
                   {  mat[top][i]=val;
                       val++;

                   }
                   top++;
                   for(int i=top;i<=bot;i++)
                    {
                        mat[i][right]=val;
                        val++;
                    }
                   right--;

                  
            if (top <= bot) {
                for (int i = right; i >= left; i--)
                      { mat[bot][i]=val++;}
                bot--;
            }

            
            if (left <= right) {
                for (int i = bot; i >= top; i--)
                    mat[i][left]=val++;
                left++;
                }
                   
            }
            return mat;
        
    }
};