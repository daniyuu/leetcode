#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool used[9];
        
        for (int i = 0; i < 9; ++i) {
            fill(used, used + 9, false);
            
            for (int j = 0; j < 9 ; ++j) {
                if (!check(board[i][j], used)) {
                    return false;
                }
            }
            
            fill(used, used + 9, false);
            
            for (int j = 0; j < 9 ; ++j) {
                if (!check(board[j][i], used)) {
                    return false;
                }
            }
            
        }
        
        for (int p = 0; p < 3; ++p) {
            for (int q = 0; q < 3; ++q) {
                fill(used, used + 9, false);
                
                for (int i = p * 3; i < p * 3 + 3; ++i) {
                    for (int j = q * 3; j < q * 3 + 3; ++j) {
                        if (!check(board[i][j], used)) {
                            return false;
                        }
                    }
                }
            }
            
            
        }
        
        return true;
    }
private:
    bool check(char ch, bool used[9]){
        if (ch == '.') {
            return true;
        }
        
        if (used[ch - '1']) {
            return false;
        }
        
        return used[ch - '1'] = true;
    }
};


//int main(){
//
//}