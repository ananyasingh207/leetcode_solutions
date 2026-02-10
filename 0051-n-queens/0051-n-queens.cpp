class Solution {
public:

    bool isSafe(int n, vector<string>& board, int row, int col){
        //row
        for(int i=0;i<n;i++){
            if(board[i][col]=='Q'){
                return false;
            }
        }
        //col
        for(int j=0;j<n;j++){
            if(board[row][j]=='Q'){
                return false;
            }
        }
        //left diagonal
        int i = row;
        int j = col;
        while(i>=0 && j>=0){
            if(board[i][j]=='Q'){
                return false;
            }
            i--;
            j--;
        }
        //right diagonal
        i = row;
        j = col;
        while(i>=0 && j<n){
            if(board[i][j]=='Q'){
                return false;
            }
            i--;
            j++;
        }
        return true;
    }

    void nQueens(int n, vector<vector<string>>& ans, vector<string>& board, int row){
        if(row==n){
            ans.push_back({board});
            return;
        }
        for(int i=0;i<n;i++){
            if(isSafe(n, board, row, i)){
                board[row][i] = 'Q';
                nQueens(n,ans,board,row+1);
                board[row][i] = '.';
            }
        }
    }


    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        nQueens(n,ans,board,0);
        return ans;
    }
};