/*
You are given an array of integers nums,there is a sliding window of size k which is moving from the very left of the array
to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
Return the max sliding window.
*/
//Time:O(N) Where N is the size of nums vector.
//Space:O(N)
//Hint:use deque to solve this problem as it stores elements in monotonic decreasing fashion!.
//Solution1

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        int i = 0, j = 0;
        vector<int> result;
        while(j < nums.size()){
            //removing smaller values from right
            while(!dq.empty() && nums[dq.back()] < nums[j]){
                dq.pop_back();
            }
            dq.push_back(j);
           //removing value from current window 
            if(i > dq.front()){
                dq.pop_front();
            }
            if(j + 1 >= k){
                result.push_back(nums[dq.front()]);
                i++;
            }
            j++;
        }
        return result;
    }
};


