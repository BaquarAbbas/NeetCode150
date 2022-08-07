/*Given two strings s and t, return true if t is an anagram of s, and false otherwise.*/
//Time:O(M + N)
//Space:O(26) where M and N are lengths of two given strings.
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }
        int charMap[26] = {0};
        for(char ch: s){
            charMap[ch-'a']++;
        }
        for(char ch: t){
            charMap[ch-'a']--;
            if(charMap[ch-'a'] < 0)return false;
        }
        return true;
    }

};
