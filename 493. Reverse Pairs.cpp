class Solution {
public:
int merge(vector<int>& nums,int l,int r,int mid)
    {
    int count=0;

        int n1=mid-l+1;
        int n2=r-mid;
        vector<long long> v1(n1),v2(n2);
        int i,j;
        
        i=l,j=mid+1; //counting the reverse pairs
        while(i<=mid&&j<=r)
        {
            if(long(nums[i])>long(2*long(nums[j])))
            {
                count+=(mid-i+1);
                j++;
            }
            else
                i++;
        }
        
        //normal merge below --------->
        for(i=0;i<n1;++i) v1[i]=nums[l+i];
        for(i=0;i<n2;++i) v2[i]=nums[mid+1+i];

        i=j=0;
        while(i<n1 && j<n2)
        {
            if(v1[i]<v2[j])
            {
                nums[l+i+j]=v1[i];
                ++i;
            }
            else
            {

                nums[l+i+j]=v2[j];
                ++j;
            }
        }

        while(i<n1) 
        {
            nums[l+i+j]=v1[i];
            ++i;
        }
        while(j<n2) 
        {
            nums[l+i+j]=v2[j];
            ++j;
        }


    return count;
    }

    void mergesort(vector<int>&nums,int l,int r,int& count)
    {
        if(l<r)
        {
            int mid=l+(r-l)/2;
            mergesort(nums,l,mid,count);
            mergesort(nums,mid+1,r,count);
            //cout<<"Mid="<<mid<<" L="<<l<<" R="<<r<<endl;
            count+=merge(nums,l,r,mid);
        }
    }

    int reversePairs(vector<int>& nums) {
        int count=0;
        mergesort(nums,0,nums.size()-1,count);
        return count;    
    }
       
};