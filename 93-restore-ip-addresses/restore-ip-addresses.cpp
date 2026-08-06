class Solution {
public:
    bool valid(string &t)
    {
        int dots = 0;
        int c = 0;
        int size = 0;

        for (char &f : t)
        {
            if (f != '.')
            {
                size++;
                if (size > 3) return false;
                c = c * 10 + (f - '0');
            }
            else
            {
                if (size == 2 && c < 10) return false;
                if (size == 3 && (c < 100 || c > 255)) return false;

                dots++;
                c = 0;
                size = 0;
            }
        }

        
        if (size == 2 && c < 10) return false;
        if (size == 3 && (c < 100 || c > 255)) return false;
        if (size > 3) return false;

        return dots == 3;
    }

    vector<string> st;

    void help(string &s, string t, int i)
    {
        if (i >= s.size())
        {
            t.pop_back();
            if (valid(t))
                st.push_back(t);
            return;         
        }

        help(s, t + s[i] + '.', i + 1);

        if (i + 1 < s.size())
            help(s, t + s[i] + s[i + 1] + '.', i + 2);

        if (i + 2 < s.size())
            help(s, t + s[i] + s[i + 1] + s[i + 2] + '.', i + 3);
    }

    vector<string> restoreIpAddresses(string s)
    {
        help(s, "", 0);
        return st;
    }
};