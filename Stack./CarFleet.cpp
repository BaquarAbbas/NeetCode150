/*
There are n cars going to the same destination along a one-lane road. The destination is target miles away.
You are given two integer array position and speed, both of length n,where position[i] is the position of the ith car
and speed[i] is the speed of the ith car (in miles per hour).A car can never pass another car ahead of it,
but it can catch up to it and drive bumper to bumper at the same speed.
The faster car will slow down to match the slower car's speed.
The distance between these two cars is ignored (i.e., they are assumed to have the same position).
A car fleet is some non-empty set of cars driving at the same position and same speed. Note that a single car is also a car fleet.
If a car catches up to a car fleet right at the destination point, it will still be considered as one car fleet.
Return the number of car fleets that will arrive at the destination.
*/
//Time:O(NlogN) where N is the size of positions vector.
//Space:O(N)
//Solution1

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> cars;
        int n = speed.size();
        for(int i = 0; i < n;i++){
            cars.push_back({position[i],speed[i]});
        }
        sort(cars.begin(),cars.end());
        stack<float> st;
        float x = (target - cars[n-1].first) / (float)cars[n-1].second;
        st.push(x);
        for(int i = n - 2; i >= 0;i--){
            x = (target - cars[i].first) / (float) cars[i].second;
            if(x > st.top()){
                st.push(x);
            }
        }
        return st.size();
    }
};

//Solution2 
//It has same time and space complexeties as above solution.
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,float>> pairs;
        int n = position.size();
        for(int i = 0; i < n;i++){
            float time = (float)(target - position[i]) / speed[i];
            pairs.push_back({position[i],time});
        }
        sort(pairs.begin(),pairs.end());
        float maxTime = 0.0,res = 0;
        for(int i = n - 1; i >= 0; i--){
            float time = pairs[i].second;
            if(time > maxTime){
                maxTime = time;
                res++;
            }
        }
        return res;
    }
};
