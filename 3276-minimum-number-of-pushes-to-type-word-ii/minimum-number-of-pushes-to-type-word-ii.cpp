class Solution {
public:
    int minimumPushes(string word) {
      vector<int>map(26,0);
      for (char c: word)
      {
           
       
        map[c-'a']++;

      }
      sort(map.begin(),map.end(),greater<int>());
      int count=0;
     int ans=0;
     int a=1;
      for (int i=0 ;i<26 && map[i]>0;i++)
      {    count++;
           ans+=map[i]*a;
           if (count==8)
           {
            count=0;
             a++;
           }
         
      }
      return ans;
    }
};