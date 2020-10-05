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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1 && !l2) return l1;
        if(!l1) return l2; //list 1 is empty
        if(!l2) return l1; //list 2 is empty
        
        ListNode* head,*iter;
        if(l1->val < l2->val) //assigning head and iterator pointer to the smaller first value list
        {
            iter=l1;
            l1=l1->next;
        }
        else
        {
            iter=l2;
            l2=l2->next;
        }
        
        head=iter;
        
        while(l1 || l2) //iterating thought both list
        {
            if(!l1) //list 1 become empty
            {
                iter->next=l2;
                break;
            }
            if(!l2) //list 2 become empty
            {
                iter->next=l1;
                break;
            }
            
            if(l1->val > l2->val) 
            {
                iter->next=l2;
                l2=l2->next;
            }
            else
            {
                iter->next=l1;
                l1=l1->next;
            }
            iter=iter->next;
        }
        return head;
    }
};