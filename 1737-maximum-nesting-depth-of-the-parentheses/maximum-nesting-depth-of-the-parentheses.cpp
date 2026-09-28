class Solution {
public:
    int maxDepth(string s) {
        int mx=0;
         int i=0;
         for (char & c: s)
           {
             if (c=='(')
              i+=1;
              else if (c==')')
              i-=1;
              mx=max(mx,i);
           }
           return mx;
    }
};