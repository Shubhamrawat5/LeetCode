class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //using max heap 
        priority_queue<int> pq;
        int i;
        
        //adding all elements in max heap
        for(i=0;i<nums.size();++i) pq.push(nums[i]);
        
        //removing n-1 elements
        for(i=0;i<k-1;++i) pq.pop();
        
        //now top element in max heap will be the kth largest element
        return pq.top();
    }
};