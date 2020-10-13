class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int single;
        int left,right,mid;
        left=0,right=nums.size()-1;
        
        //binary search of O(logn)
        //finding mid of array then checking if mid element is same as left element or right element.. if it is different from both left & right element then it is that single element.
        //if is same of any side then check the size of remaining element
        //(1) after that if element remaining are 3,7,11... then move to that side where element is different than mid element
        //(2) if element remaining are 5,9,13... then we have to consider that side where the element is same as our mid element..
        
        //to find this 3,5,7,.. or 5,9,13... divide it by 2 then check if it is odd or even, if odd then it belong to (1), if even then (2) condition
        while(left<=right)
        {
            if(right-left == 0) return nums[left]; //only 1 element is remaining
            mid=left+(right-left)/2;
            
            int elementsRemain=right-left+1;
            int direction=elementsRemain; //to find which condition to apply (1) or (2)
            direction/=2;
            if(nums[mid]==nums[mid+1])
            {
                if(direction%2==0)  left=mid; //element remaining size is 5,9,13,..
                else right=mid-1; //element remaining size is 3,7,11,..
            }
            else if(nums[mid]==nums[mid-1])
            {
                if(direction%2==0) right=mid;
                else left=mid+1;
            }
            else return nums[mid]; //element is different from left and right both
        }
        return -1;
    }
};