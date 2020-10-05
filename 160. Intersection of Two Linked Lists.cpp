/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return NULL;
        ListNode *iter1,*iter2;
        iter1=headA,iter2=headB;
        
        //Logic: using two pointers and  moving both by node by node and when any pointer reach NULL then assign it to head of other list.
        //By this both pointer will traverse equal number of nodes and will definetly meet if there is any intersection
        int n1=2,n2=2;
        while(n1 && n2)
        {
            if(iter1==iter2) return iter1;
            
            iter1=iter1->next;
            iter2=iter2->next;
            
            if(!iter1) 
            {
                iter1=headB;
                --n1;
            }
            if(!iter2)
            {
                iter2=headA;
                --n2;
            }
        }
        return NULL;
    }
};