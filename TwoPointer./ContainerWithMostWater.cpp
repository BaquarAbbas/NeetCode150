/*
You are given an integer array height of length n.There are n vertical lines drawn such that the two endpoints of the ith line are 
(i, 0) and (i, height[i]).Find two lines that together with the x-axis form a container,such that the container contains the most water.
Return the maximum amount of water a container can store.
Notice that you may not slant the container.
*/
//Time:O(N) where N is the size of height vector.
//Space:O(1)
//Solution1

class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = INT_MIN;
        int left = 0, right = height.size() - 1;
        while(left < right){
            int currentArea = min(height[left],height[right])*(right - left);
            area = max(area,currentArea);
            if(height[left] <= height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return area;
    }
};
