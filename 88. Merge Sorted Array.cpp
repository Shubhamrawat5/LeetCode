class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(nums2.size()==0) return; //if 2nd array empty
        
        int i;
        --m; //m show size so m-1 will show the last index
        --n;
        
        //inserting from last index to first index so that insertion can happen without any problem and without swapping
        for(i=nums1.size()-1;i>=0;--i)
        {
          if(m<0) //means array 1 elements are all used
            {
                nums1[i]=nums2[n];
                --n;
            }
            else if(n<0) break; //array 2 elements are all used so direct get out of loop
            else if(nums1[m]<nums2[n]) //2nd array element is bigger
            {
                nums1[i]=nums2[n];
                --n;
            }
            else //1st array element is bigger
            {
                nums1[i]=nums1[m];
                --m;
            }
        }
    }
};