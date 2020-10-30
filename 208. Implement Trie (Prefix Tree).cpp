struct TrieNode
{
    bool isEnd;
    TrieNode* child[26]; //for 26 small alphabets only
    TrieNode()
    {
        isEnd=false;
        for(int i=0;i<26;++i)
            child[i]=NULL;
    }
};


class Trie {
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root=new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string s) 
    {
        TrieNode* curr=root;
        for(int i=0;i<s.length();++i)
        {
            int c=s[i]-'a'; //0 to 25
            if(curr->child[c]==NULL) //node is not present
            {
                curr->child[c]=new TrieNode();
            }
            curr=curr->child[c]; //moving to child node of current character
        }
        curr->isEnd=true; //marking this end node as the end of a word    
    }
    
    /** Returns if the word is in the trie. */
    bool search(string s) 
    {
        TrieNode* curr=root;
        for(int i=0;i<s.length();++i)
        {
            int c=s[i]-'a';
            if(curr->child[c]==NULL) return false; //char is not present
            curr=curr->child[c];
        }
        return curr->isEnd; 
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) 
    {
        //same like search function but if all the chars of prefix match a word then in the end return true
        TrieNode* curr=root;
        for(int i=0;i<prefix.length();++i)
        {
            int c=prefix[i]-'a';
            if(curr->child[c]==NULL) return false; //char is not present
            curr=curr->child[c];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */