class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==0) return -1;
        
        int l,r; //two pointer technique
        int sum,maxx; //sum=CurrentSum $ maxx=MaxSum
        l=r=sum=0;
        maxx=INT_MIN;
        
        //Logic: Using slinding window with 2 pointers, add current right index value to sum then check if sum become negative then remove(subtract) from left side of window till sum get positive then move window ahead
        while(r<nums.size())
        {
            sum+=nums[r++]; 
            maxx=max(maxx,sum);
            while(sum<0)
            {
                sum-=nums[l++];
            }
            
        }
    return maxx;
    }
    
};