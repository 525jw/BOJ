#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
int n;
vector<vector<bool>> queen_pos;
vector<bool> visited_col;
bool diagEmpty(int y,int x){
    int i,j;
    for(i=y,j=x;i<n&&j<n;i++,j++)
        if(queen_pos[i][j]) return false;
    for(i=y,j=x;i<n&&j>=0;i++,j--)
        if(queen_pos[i][j]) return false;
    for(i=y,j=x;i>=0&&j<n;i--,j++)
        if(queen_pos[i][j]) return false;
    for(i=y,j=x;i>=0&&j>=0;i--,j--)
        if(queen_pos[i][j]) return false;
    return true;
}
int nqueen(int lvl){
    if(lvl>=n) return 1;
    int i,ret=0;
    for(i=0;i<n;i++){
        if(!visited_col[i] && diagEmpty(lvl,i)){
            queen_pos[lvl][i]=true;
            visited_col[i]=true;
            ret+=nqueen(lvl+1);
            queen_pos[lvl][i]=false;
            visited_col[i]=false;
        }
    }
    return ret;
}
int main(){
    cin >> n;
    queen_pos.resize(n, vector<bool>(n,false));
    visited_col.resize(n,false);
    cout << nqueen(0);
    return 0;
}

//행 하나에 하나밖에 안들어가니까 쓸 수 있는 행을 넘겨줘버리면 안되나?
//위에서부터 행 차례대로하나씩
//결국 경우의 수 트리의 높이는 n
//퀸은 무조건 n개