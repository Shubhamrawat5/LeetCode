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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k==0) return head;
        
        ListNode* newHead,*iter;
        newHead=iter=head;
        int size=0;
        int i=0;
        while(iter)  //calculating size of list
        {
            ++size;
            iter=iter->next;
        }
        
        k=k%size; //if k is greater than size then we will be doing 1 extra full rotation so removing it here
        if(k==0) return head; //if number of rotation becomes 0 so direct return, this can also happen when size is like 5 and k is also 5 so performing 5 rotation on size 5 list will result in same list before so handling it with these 2 lines
        
        iter=head; //now moving iter ahead k nodes then moving iter & newHead ahead simultaneously so that we can get last kth+1 node
        while(i<k && iter)
        {
            iter=iter->next;
            ++i;
        }
        
        while(iter->next)
        {
            newHead=newHead->next;
            iter=iter->next;
        }
        
        //now iter will point to last node so joining it to original head node 
        iter->next=head;
        iter=newHead;
        newHead=newHead->next; //now newHead is in the end of new list, we initially found last kth+1 node so to get kth node from end, moving newHead to 1 node ahead
        iter->next=NULL;
        
        return newHead;
    }
};