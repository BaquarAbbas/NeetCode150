/*Given an array of strings strs, group the anagrams together. You can return the answer in any order.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.*/
//Time:O(N) where N is the size of vector.
//Space:O(N) not exactly but in worst case.
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //use map that holds sorted string and list of similar arrangements;
        unordered_map<string,vector<string>>groupMap;
        for(int i = 0; i < strs.size();i++){
            string temp = strs[i];
            sort(temp.begin(),temp.end());
            groupMap[temp].push_back(strs[i]);
        }
        //store the answer in ans vector
        vector<vector<string>> ans;
        for(auto itr = groupMap.begin();itr != groupMap.end();itr++){
            ans.push_back(itr->second);
        }
        return ans;
    }
};
