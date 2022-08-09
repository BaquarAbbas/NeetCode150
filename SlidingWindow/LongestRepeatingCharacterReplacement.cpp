/*
You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character.
You can perform this operation at most k times.
Return the length of the longest substring containing the same letter you can get after performing the above operations.
*/
//Time:O(N) where N is the length of string.
//Space:O(26) due to constraint i.e..string consists of uppercase english letters.
//Solution1
//Hint: check for this condition(window_len - maxFreq < k)

class Solution {
public:
    int characterReplacement(string s, int k) {
        int charMap[26] = {0};
        int i = 0, j = 0;
        int res = 0,maxFreq = 0;
        while(j < s.length()){
            charMap[s[j]-'A']++;
            maxFreq = max(maxFreq,charMap[s[j] - 'A']);
            if(j - i + 1 - maxFreq > k){
                charMap[s[i]-'A']--;
                i++;
            }
            res = max(res,j - i + 1);
            j++;
        }
        return res;
    }
};
