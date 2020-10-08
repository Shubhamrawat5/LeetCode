class Solution {
public
    bool isPali(string s) to check if string is palindrome or not
    {
      int i=0,j=s.length()-1;
        while(ij)
        {
            if(s[i]!=s[j]) return 0;
            ++i;
            --j;
        }
        return true;
    }
    vectorvectorstring ans;

    void pp(string s,vectorstring curr)
    {
        if(s.length()==0) string is empty that means until now curr vector string is a palindrome vector as this pp function is called recursively for right substring
        {
            ans.push_back(curr);
            return;
        }
        
        if(s.length()==1) only single character is there which is itelf a palindrome string
        {
            curr.push_back(s);
            ans.push_back(curr);
            return;
        }
        
        breaking the string into two parts, one is left substring and second in right substring
        if left substring is a palindrome then checking for right substring recursively
        int i=0;
        for(;is.length();++i)
        {
            string left=s.substr(0,i+1); substr(starting index,number of chars to take)
            if(!isPali(left)) continue; left substring is not a palindrome so no need to check for left substring
            
            curr.push_back(left);
            pp(s.substr(i+1,s.length()-i),curr); calling recursively with right substring
            curr.pop_back();
        }
    }
    
    vectorvectorstring partition(string s) {
        vectorstring curr;
        pp(s,curr);
        return ans;
    }
};