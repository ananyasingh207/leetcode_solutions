class Solution {
public:
    bool isSafe(vector<string> board, int row, int col, int n){
        for(int i=0;i<n;i++){
            if(board[i][col]=='Q'){
                return false;
            }
        }
        int i = row;
        int j = col;
        while(i>=0 && j>=0){
            if(board[i][j]=='Q'){
                return false;
            }
            i--;
            j--;
        }
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

    void nQueens(vector<string> &board,int n, int row, int &ans){
        if(row==n){
            ans++;
        }
        for(int i=0;i<n;i++){
            if(isSafe(board,row,i,n)){
                board[row][i]='Q';
                nQueens(board,n,row+1,ans);
                board[row][i]='.';
            }
        }
    }

    int totalNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        int ans=0;
        nQueens(board,n,0,ans);
        return ans;
    }
};