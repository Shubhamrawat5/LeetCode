class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> p; //{value : index}
        //as max heap will be created with the first value so top of the heap denote largest value availabe
        //so to avoid using the index value which are not in current k window, using pair (by index as 2nd value,we can know if that index value is under current k size window or not, if not the kicked it out till we get a index which is in k window  
        vector<int> maxink;
        int i=0;
        
        for(i=0;i<k;++i) p.push({nums[i],i}); //adding first k values & indexes
        maxink.push_back(p.top().first); //pushing first largest value
        
        for(;i<nums.size();++i)
        {
            while(p.size() && p.top().second <= i-k) p.pop(); //here checking if the largest value in max heap is under k window or not, if not kicked it out
            
            p.push({nums[i],i}); //now we have in top a largest value which is also in k window so push it
            maxink.push_back(p.top().first); //..now simply add it to ans vector
        }
        return maxink;
    }
};