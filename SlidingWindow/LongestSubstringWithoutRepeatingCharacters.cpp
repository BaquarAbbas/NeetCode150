/*
Given a string s, find the length of the longest substring without repeating characters.
*/
//Time:O(N)
//Space:O(N)
//solution1
//Hint:use the concept of sliding window and a hashMap to store the current window characters for each window.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> letters;
        int i = 0,res = 0;
        for(int j = 0; j < s.length();j++){
            while(letters.find(s[j]) != letters.end()){
                letters.erase(s[i]);
                i++;
            }
            letters.insert(s[j]);
            res = max(res,j - i + 1);
        }
        return res;
    }
};
