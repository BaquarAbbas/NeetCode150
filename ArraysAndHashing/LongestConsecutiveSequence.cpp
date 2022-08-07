/*Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.*/
//Time:O(N)
//Space:O(N) Where N is the size of the vector.
//Hint:visualise the input vector by drawing a graph that consists of multiple consecutive sequences(sort the vector visually).
//solution1
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s(nums.begin(),nums.end());
        int longest = 0;
        for(int &num: nums){
            if(s.find(num - 1) == s.end()){
                int len = 0;
                while(s.find(num + len) != s.end()){
                    len++;
                }
                longest = max(longest,len);
            }
        }
        return longest;
    }
};
//solution2
//Time:O(NlogN)
//Space:O(1)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)return 0;
        sort(nums.begin(),nums.end());
        int longest = 1,currentLongest = 1;
        for(int i = 1; i < nums.size();i++){
            if(nums[i] != nums[i-1]){
                if(nums[i] == nums[i-1] + 1){
                    currentLongest++;
                }
                else{
                    longest = max(longest,currentLongest);
                    currentLongest = 1;
                }
            }
        }
        return max(longest,currentLongest);
    }
};
