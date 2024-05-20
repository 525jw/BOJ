#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> board;
int n;
int maxval=-1;

bool promising(int y,int x){
    
    return true;
}
void chknode(int y,int x,int bisnum){
    if(promising(y,x)){
        if(y>=n-1 && x>=n-1)
            maxval=bisnum>maxval?bisnum:maxval;
        else{
            if(board[y][x]==invalid)
        }
    }
}

int main(){
    cin>>n;
    board.resize(n,vector<int>(n,0));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) 
            cin>>board[i][j];
    
    chknode(0,0);
    
    return 0;
}