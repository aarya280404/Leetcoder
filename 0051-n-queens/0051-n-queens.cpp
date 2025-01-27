class Solution {
    bool isSafe(int row,int col,int n,vector<string> &board){
        
        if(row >= n || col >= n ) return false;
        int duprow=row,dupcol=col;

        //left
        int i=row,j=col;
        while(j>=0){
            if(board[row][j] =='Q') return false;
            j--;
        }
        //diagonal down
        i=row,j=col;
        while(i >=0 && j>=0){
            if(board[i][j]=='Q') return false;
            i--;
            j--;
        }

        //diagonal up
        i=row,j=col;
        while(i<=n-1 && j>=0){
            if(board[i][j]=='Q') return false;
            i++;
            j--;

        }

        return true;
    }


    void func(int col,int n,vector<string> &board, vector<vector<string>> &ans){
        if(col==n){
            ans.push_back(board);
            return;
        }

        for(int i=0;i<n;i++){
            if(isSafe(i,col,n,board)){
                board[i][col]='Q';
                func(col+1,n,board,ans);
                board[i][col]='.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n,string(n,'.'));
        func(0,n,board,ans);
        return ans;
    }
};