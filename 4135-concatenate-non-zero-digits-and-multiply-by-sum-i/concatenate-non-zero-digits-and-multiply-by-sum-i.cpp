class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum=0;
        long long num=0;
        long long ans=0;
        while (n)
         {
            if (n%10 !=0)
            { num= num*10+n%10;}

            n/=10;
         }
        while (num)
        {
            ans= ans*10+num%10;
            sum+=num%10;
            num/=10;
        }
        return 1LL*ans*sum;
    }
};