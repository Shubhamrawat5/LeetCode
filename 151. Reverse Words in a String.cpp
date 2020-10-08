class Solution {
public:
    string reverseWords(string s) {
        string ans;
        
        int i=0;
        while(s[i])
        {
            if(s[i]==' ') //to avoid useless spaces
            {
                ++i;
                continue;
            }
            
            string substr="";
            
            while(s[i]!=' ' && s[i]!='\0') //making a word and storing it in substr
            {
                substr+=s[i];
                ++i; 
            }
            if(ans=="") //first time first word
                ans=substr;
            else //other time add previous ans text and also add space between
                ans=substr+" "+ans; 
        }
        return ans;
    }
};