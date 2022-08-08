/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.
Valid operators are +, -, *, and /. Each operand may be an integer or another expression.
Note that division between two integers should truncate toward zero.
It is guaranteed that the given RPN expression is always valid.That means the expression would always evaluate to a result,
and there will not be any division by zero operation.
*/
//Time:O(N) where N is the size of the tokens vector.
//Space:O(N)
//solution1

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>result;
        for(int i = 0; i < tokens.size();i++){
            string token = tokens[i];
            if(token.size() > 1 || isdigit(token[0])){
                result.push(stoi(token));
                continue;
            }
            int num2 = result.top();
            result.pop();
            int num1 = result.top();
            result.pop();
            int res = 0;
            if(token == "+"){
                res = num1 + num2;
            }
            else if(token == "-"){
                res = num1 - num2;
            }
            else if(token == "*"){
                res = num1 * num2;
            }
            else{
                res = num1 / num2;
            }
            result.push(res);
        }
        return result.top();
    }
};
