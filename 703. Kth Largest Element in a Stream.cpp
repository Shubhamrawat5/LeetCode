class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq; //creating min heap 
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        for(int value:nums) pq.push(value); //adding values in min heap
    }
    
    int add(int val) {
        pq.push(val); //adding current val in heap
            
        //LOGIC: if we see the values in larger to smaller order, then the values which are not in top k are never gonna come in top k, even if we insert thousand of values, they wili go more down.. 
        //so keeping them is of no use.. now if we see this larger to smaller order values in descending order then we can see that if we are keeping only k values in heap then the smallest value in those is the kth largest value, so thats why using a min heap here
        while(pq.size() > k) pq.pop(); //making total values in pg equal to k
        
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */