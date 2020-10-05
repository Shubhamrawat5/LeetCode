class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        unordered_set<int> set;
        int i;
        int cc,mc; //current count and max count
        cc=0,mc=INT_MIN;
        for(i=0;i<nums.size();++i) //putting all element in hash set
                set.insert(nums[i]);
        
        //if element - 1 is present in set that means our current element cannot be the starting element of a series as one before element is already present in array
        for(i=0;i<nums.size();++i)
        { 
            cc=0;
            if(!set.count(nums[i]-1)) //if our current element - 1 number is not present in set that means our current element can be the starting element of a upcoming series so checking below that with while loop
            {
                long long iter=nums[i];
                while(set.count(iter++)) ++cc;
                mc=max(cc,mc);
            }
        }
        return mc;
    }
};