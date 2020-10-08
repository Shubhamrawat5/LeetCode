class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> mp; //putting all key value pair
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;
        
        int ans=0;
        int i=0;
        for(;s[i];++i) //traversing roman string
        {
            if(ans==0) //for first time
            {
                ans=mp[s[i]];
                continue;
            }
            if(mp[s[i]]<=mp[s[i-1]]) ans+=mp[s[i]]; //current roman is smaller than left so we can simply add its value
            else ans+=mp[s[i]]-2*mp[s[i-1]]; //current roman number is bigger than left so we have to add current but also need to remove last added number and subtract left side roman(doing it with - 2*mp[s[i-1]])
        }
        
        return ans;
    }
};