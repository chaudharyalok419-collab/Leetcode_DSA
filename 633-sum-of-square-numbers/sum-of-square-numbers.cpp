class Solution {
public:
    bool judgeSquareSum(int c) {
          if (c==1)
           return true;
        for (int i=0;i<=sqrt(c);i++)
         {
            int a=c-(i*i);
            int b= sqrt(a);
            if (b*b==a)
               return true;
         }
        return false;
    }
};