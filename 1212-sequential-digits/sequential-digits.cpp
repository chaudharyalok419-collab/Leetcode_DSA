class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        string s = "123456789";
          for (int len=2;len<=9;len++)
           {
              for (int i=0;i+len<=9;i++)
                {   string t= string(s.begin()+i,s.begin()+i+len);
                    int num= stoi(t);
                     
                    if (num>=low && num<=high)
                       ans.push_back(num);

                }
           }

        return ans;
    }
};