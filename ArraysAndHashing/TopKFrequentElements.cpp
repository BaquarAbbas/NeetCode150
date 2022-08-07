/*Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.*/
//Time:O(N) 
//Space:O(K + N) Where K is size of output vector and N is the size of nums vector.
//Hint:use the idea of bucket sort!!.
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> freq;
        for(auto &num: nums){
            freq[num]++;
        }
        int n = nums.size();
        vector<vector<int>> bucket(n + 1);
        for(auto itr = freq.begin();itr != freq.end();itr++){
            bucket[itr->second].push_back(itr->first);
        }
        vector<int> ans;
        for(int i = n;i >= 0;i--){
            if(ans.size() >= k)break;
            if(!bucket[i].empty()){
                for(auto &ele: bucket[i]){
                    ans.push_back(ele);
                }
            }
        }
        return ans;
    }
};
