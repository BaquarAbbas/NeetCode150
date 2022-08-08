/*Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]]
such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.*/
//Time:O(NlogN) Where N is the size of nums vector.
//Space:O(1)
//Solution1

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i = 0; i < n;i++){
            int a = nums[i];
            if(i > 0 && a == nums[i-1]){
                continue;
            }
            int left = i + 1;
            int right = n - 1;
            while(left < right){
                int sum = a + nums[left] + nums[right];
                if(sum > 0){
                    right--;
                }
                else if(sum < 0){
                    left++;
                }
                else{
                    result.push_back({a,nums[left],nums[right]});
                    left++;
                    while(nums[left] == nums[left - 1] && left < right){
                        left++;
                    }
                }
            }
        }
        return result;
    }
};
