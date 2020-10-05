/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* newhead=NULL;
        if(head==NULL) return newhead;
        
        unordered_map<Node*,Node*> mp;
        //creating a key value pair where key is the actual node with value is its duplicate node
        Node* iter=head;
        while(iter)
        {
            mp[iter]=new Node(iter->val);
            iter=iter->next;
        }
        
        
        newhead=mp[head];
        while(head) //now setting duplicate nodes next and random pointers
        {
            iter=mp[head];
            iter->next=mp[head->next];
            iter->random=mp[head->random];
            
            iter=iter->next;
            head=head->next;
        }
        return newhead;
    }
};