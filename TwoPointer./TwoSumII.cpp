/*Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order,
find two numbers such that they add up to a specific target number.
Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.
Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.
The tests are generated such that there is exactly one solution. You may not use the same element twice.*/
//Time:O(N) where N is the size of the vector.
//space:O(1)
//solution1
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        vector<int> ans(2,0);
        while(left < right){
            int sum = numbers[left] + numbers[right];
            if(sum == target){
                ans[0] = left + 1;
                ans[1] = right + 1;
                break;
            }
            else if(sum > target){
                right--;
            }
            else{
                left++;
            }
        }
        return ans;
    }
};
