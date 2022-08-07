/*Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
1.Each row must contain the digits 1-9 without repetition.
2.Each column must contain the digits 1-9 without repetition.
3.Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.*/
//Hint:use hashMaps to store every row,col and grid elements.for storing grid elements use something like row/3,col/3 logic!.
//Time:O(9x9) the size of board
//Space:O(9x9) in worst case.
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int,set<char>> row;
        unordered_map<int,set<char>> col;
        unordered_map<string,set<char>> square;
        
        for(int r = 0; r < 9;r++){
            for(int c = 0; c < 9;c++){
                if(board[r][c] == '.'){
                    continue;
                }
                string key = to_string(r/3)+":"+to_string(c/3);
                if(row[r].find(board[r][c]) != row[r].end() || col[c].find(board[r][c]) != col[c].end() || square[key].find(board[r][c]) != square[key].end()){
                    return false;
                }
                
                else{
                    row[r].insert(board[r][c]);
                    col[c].insert(board[r][c]);
                    square[key].insert(board[r][c]);
                }
            }
        }
        return true;
    }
};
