class Solution {
public:
    pair<int,int> sum(int n)
     {  int s1=0;
        int s2=0;
        while(n>0)
         {
            int a= n%10; 
            n/=10;
            s1+=a;
            s2+=a*a ; 
         }
         return{s1,s2};
     }
    bool checkGoodInteger(int n) {
        auto it= sum(n);
         int x= it.first;
         int y= it.second;
        return (y-x>=50);
        
    }
};