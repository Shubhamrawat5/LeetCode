#include <iostream>
using namespace std;


//Definition for singly-linked list.
 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    int size=0;
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL) return head; //empty list
        if(k<2) return head; this means we have to reverse 0 or 1 node which is like doing nothing
        
        if(size==0) //calculating size of linked list one time in global variable size so that it will be same for all recursive functions and we can keep track of the remaning nodes 
        {
            ListNode* iter=head;
            while(iter)
            {
                ++size;
                iter=iter->next;
            }
        }
        if(size<k) 
        {
            return head; //remaining nodes are less than k
        }
        
        //reversing k nodes
        int toBeReverse=k-1;
        ListNode* prev,*curr,*ahead;
        prev=head;
        curr=head->next;
  
        while(toBeReverse>0 && curr) 
        {
            ahead=curr->next;
            curr->next=prev;
            prev=curr;
            curr=ahead;
            --toBeReverse;
        }
        
        size=size-k;
        //recursively calling for ahead linked list and changing current function head to the return and return will be the first node of next reversed k group
        head->next=reverseKGroup(ahead,k);
    
        return prev; //returning prev as prev will point to the Kth node which will be the next header for list
    }
    
    void printLL(ListNode* head)
    {
        while(head)
        {
            cout<<head->val;
            head=head->next;
        }
    }
};

int main() {
    Solution s;
    
    //making a linked list of 12345678
	ListNode* iter=new ListNode(5);
	for(int i=4;i>0;--i)
	{
	    ListNode* temp=new ListNode(i,iter);
	    iter=temp;
	}
	s.printLL(iter);
	iter=s.reverseKGroup(iter,3);
	cout<<endl;
	s.printLL(iter);
	return 0;
}
