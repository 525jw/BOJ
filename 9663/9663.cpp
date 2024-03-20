#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int n,res;
void pruning(int y,int x,vector<vector<bool>>& visited){
    int i,j;
    for(i=0;i<n;i++)
        visited[y][i]=true;
    for(i=0;i<n;i++)
        visited[i][x]=true;
    for(i=y,j=x;i<n&&j<n;i++,j++)
        visited[i][j]=true;
    for(i=y,j=x;i>=0&&j>=0;i--,j--)
        visited[i][j]=true;
    for(i=y,j=x;i<n&&j>=0;i++,j--)
        visited[i][j]=true;
    for(i=y,j=x;i>=0&&j<n;i--,j++)
        visited[i][j]=true;
}
int dfs(vector<vector<bool>> visited,int lvl){
    int i,j,ret=0;
    bool allvisited=true;
    cout<<"###############lvl"<<lvl<<endl;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cout<<visited[i][j];
        }
        cout<<endl;
    }
    cout<<"###############res"<<res<<endl;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(!visited[i][j]){
                allvisited=false;
                vector<vector<bool>> next_visited(visited);
                pruning(i,j,next_visited);
                cout<<"put queen "<<i<<j<<endl;
                dfs(next_visited,lvl+1);
            }
    if(allvisited) res++;
}

int main(){
    cin >> n;
    vector<vector<bool>> visited(n,vector<bool>(n,false));
    dfs(visited,0);
    cout << res;
    return 0;
}

//행 하나에 하나밖에 안들어가니까 쓸 수 있는 행을 넘겨줘버리면 안되나?
//위에서부터 행 차례대로하나씩
//결국 경우의 수 트리의 높이는 8
//퀸은 무조건 n개