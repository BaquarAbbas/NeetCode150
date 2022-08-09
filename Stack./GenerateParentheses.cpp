/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
*/
//Time:O(2^n)
//Space:O(2^n)
//Solution1
class Solution {
private:
    void generate(int n,int open,int close,string s,vector<string>&res){
        if(open == n && close == n){
            res.push_back(s);
            return;
        }
        if(open < n){
            generate(n,open + 1,close,s+'(',res);
        }
        if(open > close){
            generate(n,open,close + 1,s+')',res);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate(n,0,0,"",res);
        return res;
    }
};
