class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> quad; //for storing answer quads
        if(nums.size()<4) return quad; //quads is not possible with less than 4 numbers
        set<vector<int>> dupliChecker; //to check if same quads is not getting again
        sort(nums.begin(),nums.end()); //sorting the nums vector to reduce time complexity from O(n2) to O(nlogn) for last 2 elements
        int i,j;
        int ot=target; //original target so that it does not get lost
        for(i=0;i<nums.size()-3;++i)
        { 
            target=ot;
            target-=nums[i]; //subtracting current index element from target 

            int tfj=target;  //target for j loop so that is does not get lost
            
            for(j=i+1;j<nums.size()-2;++j)
            {
                target=tfj;
                target-=nums[j];
    
                int right=nums.size()-1;
                int left=j+1;
                while(left<right) //for last 2 elements using 2 pointer technique, one from left and second from right side
                {
                
                    if(nums[left]+nums[right]==target) //found quad
                    {
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(target-nums[left]);
                        temp.push_back(nums[left]);
                        
                        if(dupliChecker.count(temp)==0) //means this quad didnt come before
                        {             
                            quad.push_back(temp);
                        }
                        ++left;
                        --right;

                        dupliChecker.insert(temp); 
                     }
                     else if(nums[left]+nums[right]<target) ++left; 
                     else --right;
                }
                
            }
        }
    
        return quad;
    }
};