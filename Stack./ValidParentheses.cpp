/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:
1.Open brackets must be closed by the same type of brackets.
2.Open brackets must be closed in the correct order.
*/
//Time:O(N)
//Space:O(N)
//Solution1

class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        const unordered_map<char,char> mp = {{')','('},{'}','{'},{']','['}};
        for(auto ch: s){
            if(ch == '(' || ch == '[' || ch == '{'){
                st.push(ch);
            }
            else{
                if(st.empty()){
                    return false;
                }
                else if(mp.at(ch) == st.top()){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
        return st.empty();
    }
};
