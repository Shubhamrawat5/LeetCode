class Solution {
public:
    /*Here we are breaking the problem into smaller smaller problems using recursion
    in first, we will get the first position number of the sequence, then calling function again with n-1 (as we have used one number in first position already), now k will change here to a new position! 
        now next we will get the number which will be in 2nd position then again recursion and on..
        to know if we have a number before or not, using a boolean vector named used
        */
    string find(vector<bool> used,int n,int k,string& ans)
    {
        if(n==0) return ans; 
        
        //calculating factorial to know total possible permutations with n
        int fact=1;
        for(int i=2;i<=n;++i) fact*=i;
        
        //tnig will get the total number of numbers that start with same number
        // like for n=3 => 123,132,213,231,312,321 here fact is 6, and tnig will be 2 (as from number 1 begins 2 numbers i.e 123,132)
        //now kBelongsToGroup will know that our k belong to which of the group, like in
        // n=3 => 123,132,213,231,312,321 there are 3 groups (one with start with 1, one with start with 2, one with start with 3). now getting to know k belong to which of these groups by the formula below..
        int tnig=fact/n; //total number in a group
        int kBelongsToGroup=((k-1)/tnig)+1;
        
        int curGroupNo=1; //current group number
        //using curGroupNo so that we will not use the used numbers, and if we have not used any number then increment curGroupNo till we get to same groupNo as kBelongsTo..
        for(int i=0;i<used.size();++i)
        {
            if(curGroupNo==kBelongsToGroup && used[i]==0)
            {
                
                k=(((k-1)%tnig)+1)%tnig; //new k value (a bit complex formula)
                if(k==0) k=tnig;
                /*
                K is calculated as..
                for n=3 (3 groups will be there) and each group having 2 numbers, so if k=3 then our k would belong to 2nd group then new k will be 1 (new k will be from the beginning from kbelongsto group)
                1st group->  123 (k=1 will get here)  (new k=1) 
                             132 (k=2) (new k=2)
                2nd group->  213 (k=3) (new k=1)
                             231 (k=4) (new k=2)
                3rd group->  312 (k=5) (new k=1)
                             321 (k=6) (new k=2)
                
                */
                used[i]=1; 
                ans+=to_string(i+1); //adding number
                find(used,n-1,k,ans);
                break;
            }
            if(used[i]==0)
            {
                ++curGroupNo;    
            }
        }
        return ans;
    }
    
    
    string getPermutation(int n, int k) {
        vector<bool> used(n,0); //craeting a boolean vector to know if any number is used before or not
        string ans;
        find(used,n,k,ans);
        return ans;
    }
};