#include <iostream>
#include <vector>
using namespace std;
// - {invalidSquare, validSquare, occupiedSquare}
typedef enum{sqrInv,sqrV,sqrOcp}SquareStatus;
bool promising(vector<vector<int>>& board,int n,int row,int col){
    //invalid chk
    if(board[row][col]==sqrInv) return false;
    //diagonal occupied chk 
    for(int irow=row,icol=col;irow<n && icol<n;irow++,icol++)
        if(board[irow][icol]==sqrOcp)
            return false;
    for(int irow=row,icol=col;irow>=0&&icol>=0;irow--,icol--)
        if(board[irow][icol]==sqrOcp)
            return false;
    return true;
}
int dfs(vector<vector<int>>& board,int n,int row,int col,int bisnum){
    int ret=-1;
    if(promising(board,n,row,col)){
        board[row][col]=sqrOcp;
        if(col!=n-1){
            col++;
            for(int irow=row,icol=col; irow<n && icol>=0 ;irow++,icol--)
                ret=max(ret,dfs(board,n,irow,icol,bisnum+1));
            col--;
        }
        else{
            row++;
            for(int irow=row,icol=col; irow<n && icol>=0 ;irow++,icol--)
                ret=max(ret,dfs(board,n,irow,icol,bisnum+1));
            row--;
        }
        board[row][col]=sqrV;
    }
    return ret;
}
int main(){
    int n;
    vector<vector<int>> board;
    
    cin>>n;
    board.resize(n+1,vector<int>(n+1));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>board[i][j];
    
    cout<<dfs(board,n,0,0,0);
    return 0;
}