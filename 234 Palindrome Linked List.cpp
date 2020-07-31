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

	void reverseLL(ListNode* &p) //To reverse LL
	{
		if(!p || !p->next) return; 
	
		ListNode* prev,*curr,*ahead;
		prev=p;
		ahead=p->next;
		while(ahead)
		{
			curr=ahead;
			ahead=curr->next;
			curr->next=prev;
			prev=curr;
		}
		p->next=NULL;
		p=curr;
	}

    bool isPalindrome(ListNode* head) {
    	ListNode *p,*q;
    	p=q=head;
    	
    	//dividing LL into 2 equal parts
    	while(q && q->next)
    	{
    		p=p->next;
    		q=q->next->next;
    	}
    	
    	//now reversing the 2nd part
    	if(q==NULL)//even nodes = p to end reverse 
    	{
    		reverseLL(p);
    	}
  	else  //odd nodes = p+1 to end reverse
  	 {
  	 	p=p->next;
  	 	reverseLL(p);
  	 }
  
  	 //now checking both parts
  	 while(p)
  	 {
  	 	if(p->val!=head->val)
  	 		return 0;
  	 	p=p->next;
  	 	head=head->next;
  	 }
  	 return 1;
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
	ListNode *temp=new ListNode(1);
	ListNode *temp2=new ListNode(2,temp);
	temp=new ListNode(3,temp2);
	temp2=new ListNode(2,temp);
	temp=new ListNode(1,temp2);
	ListNode *head=temp;
	s.display(head);
	cout<<"\n\n";
	cout<<s.isPalindrome(head);
	//s.reverseLL(head);
	//s.display(head);
	
}