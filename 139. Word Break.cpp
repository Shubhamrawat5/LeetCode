class Solution {
public:
    bool check(string substr,string s) //checking if string substr is a prefix of string s or not
    {
        if(substr.length()>s.length()) return false;
        int i=0;
        while(i<substr.length() && i<s.length())
        {
            if(substr[i]!=s[i]) return false;
            ++i;
        }
        return true;
    }
    
    bool can(string s,vector<string>& wordDict,vector<bool>& dp,int curIndex) //using curIndex to know of which index of main string s we are at. so that we can mark it as true or false in bool vector
    {
        if(dp[curIndex]==false) return false; //problem has already checked before and having false value means program cant be solved further
        
        if(s.length()==0) return true; //found answer
        bool canMake=false; //to know if ans is found or not

        //Logic: checking for each index that if any wordDict string is same as the prefix of current string.. using check function for this (created above)
        for(int i=0;i<wordDict.size();++i)
        {
            if(canMake==true) break; //if ans was found before this will not evaluate further
            if(check(wordDict[i],s)) //yes, current string prefix is same as a wordDict string of index i
            {
                canMake=can(&s[0]+wordDict[i].length(),wordDict,dp,curIndex+wordDict[i].length()); //checking for right side string then. passing address of string which will be O(1) not like substr O(n). 
            }
        }
        dp[curIndex]=false; //we have checked all possible combinations for current index of main string and current string so marking it as false
        return canMake;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        if(s.length()==0) return true;
        vector<bool> dp(s.length(),1); //a dynamic programming array to avoid checking same problem more than once, filling it value true(1) 
        return can(s,wordDict,dp,0);
    }
};