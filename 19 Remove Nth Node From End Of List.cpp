#include<iostream>
using namespace std;

struct ListNode {
int val;
ListNode *next;
ListNode() : val(0), next(nullptr) {}
ListNode(int x) : val(x), next(nullptr) {}
ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL) return head;
        if(head->next==NULL) //if only 1 node is there then direct remove it
        {
        	ListNode*temp=head;
        	head=NULL;
        	delete(temp);
        	return head;
        }
        
        ListNode *ahead,*behind; 
        ahead=behind=head;
        
        for(int i=0;i<n;++i) //moving ahead n pos
        ahead=ahead->next;
        
        if(ahead==NULL) //if reached last node then remove head node directly
        {
            ListNode *temp=behind;
   	     head=head->next;
	        delete(temp);
	        return head;
        }
        
        while(ahead->next) //otherwise now move ahead and behind pointer by one-one and when ahead reached NULL then behind pointer would be in the just previous node of the node which we want to delete
        {
        	ahead=ahead->next;
        	behind=behind->next;
        }
        
        //now delete the node
        ListNode *temp=behind->next;
        behind->next=behind->next->next;
        delete(temp);
        
        return head;
    }
    
    void display(ListNode *head) //to display LL
    {
    	cout<<endl;
    	while(head)
    	{
    		cout<<head->val<<" ";
    		head=head->next;
    	}
    }
};


int main()
{
	Solution s;
	int k=2;
	ListNode *temp=new ListNode(5);
	ListNode *temp2=new ListNode(4,temp);
	//temp=new ListNode(3,temp2);
	//temp2=new ListNode(2,temp);
	//temp=new ListNode(1,temp2);
	ListNode *head=temp2;
	s.display(head);
	head=s.removeNthFromEnd(head,k);
	s.display(head);
	
}