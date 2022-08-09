/*
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
In other words, return true if one of s1's permutations is the substring of s2.
*/
//Time:O(N + M) where N is the length of s1 and M is the length of s2.
//Space:O(26)
//Solution1
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()){
            return false;
        }
        int s1count[26] = {0};
        int s2count[26] = {0};
        for(int i = 0; i < s1.length();i++){
            s1count[s1[i]-'a']++;
            s2count[s2[i]-'a']++;
        }
        int matches = 0;
        for(int i = 0; i < 26;i++){
            if(s1count[i] == s2count[i]){
                matches++;
            }
            else{
                matches += 0;
            }
        }
        int left = 0;
        for(int right = s1.length(); right < s2.length();right++){
            if(matches == 26)return true;
            int idx = s2[right] - 'a';
            s2count[idx]++;
            if(s1count[idx] == s2count[idx]){
                matches++;
            }
            else if(s1count[idx] + 1 == s2count[idx]){
                matches--;
            }
            idx = s2[left]-'a';
            s2count[idx]--;
            if(s1count[idx] == s2count[idx]){
                matches++;
            }
            else if(s1count[idx] - 1 == s2count[idx]){
                matches--;
            }
            left++;
        }
        return matches == 26;
    }
};
