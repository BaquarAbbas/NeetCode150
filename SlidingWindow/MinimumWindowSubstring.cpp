/*
Given two strings s and t of lengths m and n respectively,return the minimum window substring of s such that every character in t (including duplicates) is included in the window.
If there is no such substring, return the empty string "".The testcases will be generated such that the answer is unique.
A substring is a contiguous sequence of characters within the string.
*/
//Time:O(N + M) wher N is the length of s and M is the length of t.
//Space:O(N + M)
//Solution1

class Solution {
public:
    string minWindow(string s, string t) {
        if(t.empty())return t;
        //to store frequencies of t
        unordered_map<char,int>count;
        //to store frequencies of current window
        unordered_map<char,int>window;
        for(auto ch: t){
            count[ch]++;
        }
        //stores window indexes
        vector<int>res = {-1,-1};
        //storing window length
        int resLen = INT_MAX;
        //i-->start of window j-->end of window
        int i = 0,have = 0,need = count.size();
        for(int j = 0; j < s.length();j++){
            char ch = s[j];
            if(window.find(ch) == window.end()){
                window[ch] = 1;
            }
            else{
                window[ch]++;
            }
            if(count.find(ch) != count.end() && window[ch] == count[ch]){
                have++;
            }
            while(have == need){
                //updating window length
                if(resLen > j - i + 1){
                    res[0] = i;
                    res[1] = j;
                    resLen = j - i + 1;
                }
                //minimising the window length i.e..checking for a smaller window by poping from front of the window
                window[s[i]]--;
                if(count.find(s[i]) != count.end() && window[s[i]] < count[s[i]]){
                    have--;
                }
                i++;
            }
        }
        if(resLen != INT_MAX){
            return s.substr(res[0],resLen);
        }
        else{
            return "";
        }
    }
};
