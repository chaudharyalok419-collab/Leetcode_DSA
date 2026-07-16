class Solution {
public:
    
    bool check (int a ,int b, int c)
     {
        return (a+b>c  && b+c>a && a+c>b);
     }
     double angle (int  a,int b,int c)
     {
        double x= (1.0*a*a + 1.0 *b*b -1.0*c*c)/(2.0*a*b);
        double y= 180.0/acos(-1);
        return acos(x)*y;
     }
    vector<double> internalAngles(vector<int>& sides) {
       int a=sides[0] ;
       int b=sides[1];
       int c= sides[2];
       if (check(a,b,c)==false)
            return{};
        vector<double>ans(3,0);
        ans[0]=angle(a,b,c);
        ans[1]= angle (b,c,a);
        ans[2]=angle(c,a,b);
        sort(ans.begin(),ans.end());
         return ans;

    }
};