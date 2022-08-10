/*
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1,
return the area of the largest rectangle in the histogram.
*/
//Time:O(N) where N is the size of heights vector.
//Space:O(N)
//Solution1

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> st;
        int maxArea = 0;
        for(int i = 0; i < heights.size();i++){
            int start = i;
            while(!st.empty() && st.top().second > heights[i]){
                int idx = st.top().first;
                int width = i - idx;
                int height = st.top().second;
                st.pop();
                maxArea = max(maxArea,height * width);
                start = idx;
            }
            st.push({start,heights[i]});
        }
        while(!st.empty()){
            int width = heights.size() - st.top().first;
            int height = st.top().second;
            st.pop();
            maxArea = max(maxArea,height * width);
        }
        return maxArea;
    }
};
