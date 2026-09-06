class Solution {
public:
    int countRotations(string s, int k) {
         int ans=0;
         for(int i=0;i<s.size();i++)
           {
              if (i!=0)
              {
                char a= s.front();
                s.push_back(a);
                s=s.substr(1);
              }
              int t=0;
              for (int j=0;j<s.size()-1;j++)
                {
                    if (s[j]==s[j+1])
                       t++;
                }
                if (t==k)ans++;
           }
           return ans;
    }
};