/*
Given an array of integers temperatures represents the daily temperatures,
return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature.
If there is no future day for which this is possible, keep answer[i] == 0 instead.
*/
//Time:O(N) where N is the size of temperatures vector.
//Space:O(N)
//Solution1

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int>result(n,0);
        stack<pair<int,int>> st;
        for(int i = 0; i < n;i++){
            int currDay = i;
            int currTemp = temperatures[i];
            while(!st.empty() && st.top().second < currTemp){
                int prevDay = st.top().first;
                st.pop();
                result[prevDay] = currDay - prevDay;
            }
            st.push({currDay,currTemp});
        }
        return result;
    }
};
