class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        
        if(strs.size()==0) return ans;
        int i=0;
        int flag=1;
        while(flag)
        {
            //reading first index string character, if its null then no need to check further
            if(strs[0][i]=='\0') break;
            char curr=strs[0][i]; //take 1st string current char and will compare with other index string's char
            for(int j=0;j<strs.size();++j)
            {
                if(strs[j][i]!=curr || strs[j][i]=='\0') //checking if same or not and also if any string in its end or not
                {
                    return ans;
                }
            }
            ans=ans+curr;
            ++i;
        }
        
        return ans;
    }
};