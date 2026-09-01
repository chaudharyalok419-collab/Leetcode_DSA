/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  bool check(ListNode *curr,ListNode *nx,ListNode *prev)
  {
    if (curr->val>prev->val && curr->val > nx->val)
        return true ;
     if (curr->val<prev->val && curr->val < nx->val)
       return 1;
       else 
       return 0;

  }
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
         int f=0;
         int l=0;
         int mdis=INT_MAX;
         int mxdis=INT_MIN;
         ListNode * curr=head->next;
         ListNode *nx= head->next->next;
         ListNode *prev=head;
         int i=2;
         while (nx)
         {
            if (check(curr,nx,prev))
              {
                if (!f)f=i;
                 else{
                    if (l)mdis=min(mdis,i-l);
                    mxdis=max(mxdis,i-f);
                     
                 }
                 l=i;  
              }
              i++;
              prev= curr;
              curr=nx;
              nx=nx->next;
         }


      if (mxdis==INT_MIN ||mdis==INT_MAX )
         return {-1,-1};
        return {mdis,mxdis};
    }
};