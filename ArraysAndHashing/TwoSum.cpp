/*Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.*/
//Time:O(N)
//Space:O(N) Where N is the size of nums vector.
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //using hasmap to compute the idx of another number such that it sums upto given target.
        unordered_map<int,int>mp;
        for(int i = 0; i < nums.size();i++){
            if(mp.find(nums[i]) != mp.end()){
                return {mp[nums[i]],i};
            }
            else{
                int diff = target - nums[i];
                mp[diff] = i;
            }
        }
        return {};
    }
};
