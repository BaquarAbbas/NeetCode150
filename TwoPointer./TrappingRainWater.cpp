/*Given n non-negative integers representing an elevation map where the width of each bar is 1,
compute how much water it can trap after raining.*/
//Time:O(N) where N is the size of height vector.
//Space:O(1)
//Solution1

class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0,right = height.size() - 1;
        int leftMax = height[left],rightMax = height[right];
        int res = 0;
        while(left < right){
            if(leftMax <= rightMax){
                left++;
                leftMax = max(leftMax,height[left]);
                res += leftMax - height[left];
            }
            else{
                right--;
                rightMax = max(rightMax,height[right]);
                res += rightMax - height[right];
            }
        }
        return res;
    }
};
