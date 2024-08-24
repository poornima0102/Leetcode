class Solution {
public:
unordered_map<int,bool> leftRow;
unordered_map<int,bool> upperleftdiag;
unordered_map<int,bool> bottomleftdiag;
bool isSafe(vector<vector<char>> &board,int row,int col,int n){
    // int i=row;
    // int j=col;
    // //left row
    // while(j>=0){
    //     if(board[i][j]=='Q'){
    //         return false;
    //     }
    //     j--;
    // }
    // i=row;
    // j=col;
    // //left upper diag
    // while(i>=0 && j>=0){
    //     if(board[i][j]=='Q'){
    //         return false;
    //     }
    //     i--;
    //     j--;
    // }
    // i=row;
    // j=col;
    // //bootom left diag
    // while(i<n && j>=0){
    //     if(board[i][j]=='Q'){
    //         return false;
    //     }
    //     i++;
    //     j--;
    // }
    // return true;
    if(leftRow[row]==true){
        return false;
    }
    if(upperleftdiag[n-1+col-row]==true){
        return false;
    }
    if(bottomleftdiag[row+col]==true){
        return false;
    }
    return true;
}
void storeSolution(vector<vector<char>> &board,int col,int n,vector<vector<string>> &ans){
    vector<string>temp;
    for(int i=0;i<n;i++){
        string output="";
        for(int j=0;j<n;j++){
            output.push_back(board[i][j]);
        }
        temp.push_back(output);
    }
    ans.push_back(temp);
    

}
void solve(vector<vector<char>> &board,int col,int n,vector<vector<string>> &ans){
    //bc
    if(col>=n){
        storeSolution(board,col,n,ans);
        return;
    }
    //place q1 in every row
    for(int row=0;row<n;row++){
        if(isSafe(board,row,col,n)){
            board[row][col]='Q';
            leftRow[row]=true;
            upperleftdiag[n-1+col-row]=true;
            bottomleftdiag[row+col]=true;
            solve(board,col+1,n,ans);
            //BT
            leftRow[row]=false;
            upperleftdiag[n-1+col-row]=false;
            bottomleftdiag[row+col]=false;
            board[row][col]='.';

        }
    }

}

vector<vector<string>> solveNQueens(int n) {
    
    vector<vector<char>> board(n,vector<char>(n,'.'));
    int col=0;
    vector<vector<string>> ans;
    solve(board,col,n,ans);
    return ans;
    }
};