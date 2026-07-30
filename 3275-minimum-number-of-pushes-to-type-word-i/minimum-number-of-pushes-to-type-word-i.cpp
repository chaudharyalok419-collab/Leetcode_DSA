class Solution {
public:

    int minimumPushes(string word) {
        int n= word.size();
        int count=0;
        int a=1;
        while (n)
        {
            if (n>8)   
            {
                n=n-8;
                count+=a*8;
                a++;
            }
            else {
               count+=a*n;
               n=0;
            }
        }
        return count;
    }
};