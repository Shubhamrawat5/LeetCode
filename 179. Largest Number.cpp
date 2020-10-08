//custom comparator function for sort function for vector
//it combine both the int and check which is forming bigger number like
// 5 and 54 :- 554 and 545 will form now 554 is bigger that means 5 should come first then 54
bool findlarg(int a,int b){
        string x = to_string(a);
        string y = to_string(b);
        long first=stol(x+y);
        long second=stol(y+x);
        return first>second?1:0;
    }    
    
class Solution {
public:

    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),findlarg);
        string ans;
        int noOfZero=0; //for the case if all number in vector are 0 so it will form like "00000..." which is "0" actually
        for(auto i:nums)
        {
            if(i==0) ++noOfZero;
            ans=ans+to_string(i);
        }
        return noOfZero==nums.size()?"0":ans;
    }
};