/*A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters,
it reads the same forward and backward. Alphanumeric characters include letters and numbers.
Given a string s, return true if it is a palindrome, or false otherwise.*/
//Time:O(N) Where N is the length of the string.
//Space:O(1)
//solution1
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;
        while(left < right){
            if(!isalnum(s[left])){
                left++;
            }
            else if(!isalnum(s[right])){
                right--;
            }
            else{
                if(tolower(s[left]) != tolower(s[right])){
                    return false;
                }
                else{
                    left++;
                    right--;
                }
            }
        }
        return true;
    }
};
