class Solution {
public:
   void reverse(vector<int>& v,int l,int r)
{
    while(l<r)
    {
        swap(v[l++],v[r--]);
    }
}

void nextPermutation(vector<int>& nums) {
        int i,jg,lss=-1; //js=just greater,lss=left side smaller
        for(i=nums.size()-1;i>0;--i) //finding the point where left side element is smaller
        {
            if(nums[i-1]<nums[i]) 
            {
                lss=i-1;
                break;
            }
        }
        
        if(lss==-1) //if no smaller found so this is our last permutation case so directly reverse whole vector (in ascending form it will get after reverse)
        {
            reverse(nums,0,nums.size()-1);
            return;
        }

        //cout<<lss<<endl;
        
        for(jg=nums.size()-1;jg>0;--jg) //now find the element which is just greater to our lss
        {
            if(nums[lss]<nums[jg])
            {
                break;
            }
        }
 
        //cout<<jg<<endl;

        swap(nums[lss],nums[jg]); //swap just greater with our lss and then reverse the remaining vector and we will get next permutation
        
        ++lss;
        reverse(nums,lss,nums.size()-1);       
    }

};