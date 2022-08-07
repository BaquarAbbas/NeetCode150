/*iven an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.*/
//hint: use the concept of prefix and postfix product computations but without using any extra space.
//Time:O(N)
//Space:O(N) Where N is the size of the nums vector.
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>products(nums.size(),1);
        int leftRunning = 1;
        for(int i = 0; i < nums.size();i++){
            products[i] = leftRunning;
            leftRunning *= nums[i];
        }
        int rightRunning = 1;
        for(int i = nums.size() - 1; i >= 0;i--){
            products[i] *= rightRunning;
            rightRunning *= nums[i];
        }
        return products;
    }
};
