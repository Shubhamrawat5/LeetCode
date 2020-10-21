typedef unordered_map<int,int> KV;
typedef pair<int,int> P;

struct check //for custom compare in priority queue
{
    bool operator()(P a,P b) //overloading the () operator which is accepting two pair arguments
    {
         return a.second < b.second;
    }
};


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        KV mp; //using a unordered_set key:value pair for storing the frequency of elements
        int i;
        for(i=0;i<nums.size();++i)
        {
            mp[nums[i]]=mp[nums[i]]+1;
        }
        
        priority_queue<P,vector<P>,check> pq; //creating a priority_queue of pair<int,int> with custom compare
        vector<int> ans;
        
        for(auto z:mp) //pushing all the key value pairs in heap
        {
            //cout<<z.first<<","<<z.second<<endl;
            pq.push(z);
        }
        for(i=0;i<k;++i) //now accessing top k values in heap
        {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};