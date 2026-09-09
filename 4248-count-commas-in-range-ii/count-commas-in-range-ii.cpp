class Solution {
public:
    long long countCommas(long long n) {
        if (n<=999)return 0;
        long long ans=0;
        long long a=999;
        n-=a;
        int t=1;
        while(true)
        {
          a=a*1000;
          if (n<a)
           {  
             ans+=n*t;
             return ans;

           }
           n-=a;
           ans+=a*t;
           t++;
        }
return ans;
    }
};