/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
/
class Solution {
public:
    int n=0; //using this global variable to have control over the return statement, if n is 0 means we are in first function and we have to return head.. or if n is not 0 means we are inside a recursion function so we have to return end last node of current level list
    
    //recursively solving problem, whenever a child come.. call function again with child as new root for new function 
    Node* flatten(Node* head) {
        if(head==NULL) return head;
        
        Node* iter=head;
        
        while(iter->next || iter->child) //iterating till last node, using iter->child for a condition when there is a child node but next node is NULL, so we have to process child of last node
        {
            if(iter->child!=NULL) //child available
            {
                ++n;
                Node* end=flatten(iter->child); //recursively calling for next level list
                if(iter->next) //means current node is not the last node of current level
                {
                    iter->next->prev=end;
                    end->next=iter->next;
                }
                iter->next=iter->child;
                iter->child=NULL;
                iter->next->prev=iter;
                
                iter=end;   
                }
            
            else iter=iter->next;
        }
        
        if(n-- != 0) return iter;
        return head;
    }
};