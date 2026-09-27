class Solution {
public:
    string reverseParentheses(string s) {
        stack<char>st;
        for (char &c : s )
        {
            if (c!=')')
              st.push(c);
            else 
            {
              string t="";
              while (!st.empty() && st.top()!='(')
              {
                t=t+st.top();
                st.pop();
              }
              st.pop();
              for (auto i: t)
                st.push(i);
            }
        }
        string ans="";
        while (!st.empty())
       {  ans=st.top()+ans;
          st.pop();}


          return ans;
    }
};