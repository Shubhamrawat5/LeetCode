class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length()<2) return s;
        /*there are 2 possibilities when a palindrome can be formed
        1) when 2 consecutive char come like aa , bb , zz 
        2) when there are same char and they have a char between them like aza, bhb
        
        so finding palindrome with above 2 statements.. 
        -> check for prevoius char, if same then check how big palindrome can form
        -> check for 2 behind index char, if same then check same thing 
         for these taking 2 pointer left and right, and we keep checking if both has same char, if have then move left to left-1 and right to right+1 and keep checking
        */
        int i;
        int left,right; 
        int maxL=0; //to have the index where the current longest palindrome found
        i=1;
        bool same3chars = false; //this is to handle a case when there are same 3 chars like aaa, zzz etc. as for this case we will need to check for one more time, one for left=i-1 and second for left=i-2
        int maxlength=-1; //to know the length of largest formed palindrome
        while(i<s.length())
        {
            same3chars=false;
            if(s[i]==s[i-1] || (i!=1 && s[i]==s[i-2])) //checking if last char was similar and if last 2nd char was similar with handling the case with index 1 as i-2 here will give -1 and s[-1] will give error
            {
                left=(s[i]==s[i-1])?i-1:i-2; //if previous index char is same then left is previous index otherwise i-2 index
                
                if(left==i-1 && i!=1 && s[i]==s[i-2]) //handling the case for similar 3 back to back chars, something like "aaa"
                {
                    same3chars=true;
                }
                right=i;
                
                while(left>=0 && right<s.length() && s[left]==s[right])
                {
                    --left;
                    ++right;
                }
                if(maxlength < (right-left-1))
                {
                    maxlength=right-left-1;
                    maxL=left+1;
                }
                
                if(same3chars) //handling that similar 3 chars case, we have to check for another time but here left will be different and right is same
                {
                    left=i-2;
                    right=i;
                    while(left>=0 && right<s.length() && s[left]==s[right])
                   {
                        --left;
                        ++right;
                    }
                    if(maxlength < (right-left-1))
                    {
                       maxlength=right-left-1;
                       maxL=left+1;
                    }
                }
                
            }
            
            ++i;
        }
        
        if(maxlength==-1) return s.substr(0,1); //if no palindrome was there so 1 char is also a palindrome so taking 1st char as our palindrome
        return s.substr(maxL,maxlength); //substr(first_index,length)
    }
};