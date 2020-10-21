/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q; //using queue for level order traversal
        string s="";
        
        if(root==NULL) return s;
        
        //level order traversal
        q.push(root);
        while(q.size())
        {
            if(q.front()==NULL)
                s+="N,"; //marking NULL as N in string
            else
            {
                q.push(q.front()->left); //adding left right children
                q.push(q.front()->right);
                s+=to_string(q.front()->val)+',';   //adding parent node value in string
            }
            q.pop();
        }
        //cout<<s; //looks something like "1,2,3,n,n,4,n,"
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="") return NULL; //string is empty
        
        queue<TreeNode *> q; //using queue for again level order traversal
        int LR=-1; //LEFT-RIGHT, -1 means left, +1 means right (this variable it to know current value is which child)
        TreeNode* root=NULL;
        int value=0,i=0;
        while(i<data.length())
        {
            LR=LR*-1; //changing child value in every iteration
            if(data[i]=='N') //null node is there so just ignore the calculation
            {
                i=i+1;
            }
            else //there is some value
            {
                value=0; //to store the value
                bool negative=false; //to indicate if value is a negative value or not
                if(data[i]=='-') //if its negative then mark is as negative
                {
                    negative=true;
                    ++i;
                }
                while(data[i]!=',') //finding number till we hit a comma (as number can be of any length, not just 1 char long so...)
                {
                 value=value*10+data[i]-'0';
                 ++i;
                }
                
                value=negative?value*-1:value; //if the number is negative so make it negative
                TreeNode* temp=new TreeNode(value); //creating new node
            
            
                if(root==NULL) //only first time execute and mark the root as first node
                {
                    root=temp;                 
                }
                else 
                {
                    if(LR==-1) q.front()->left=temp; //LR is -1 and -1 is for left child
                     else  q.front()->right=temp; //LR is +1 for right child
                }
                q.push(temp); //pushing current node to queue
            }
            if(LR==1 && q.size()>1) q.pop(); //when LR become +1 means right child is filled (means front of queue both left right are filled so it time to say bye bye to parent node) , using q.size()>1 to avoid for 1st node in the tree
            ++i;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));