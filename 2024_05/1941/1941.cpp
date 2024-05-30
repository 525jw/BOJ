#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef struct pair<int,int> crd;
vector<string> board(5);
vector<vector<bool>> visited(5,vector<bool>(5,false));

int cnt=0;

bool promising(int y,int x,int doyeon){
    if(y<0 || y>=5 || x<0 || x>=5) 
        return false;
    //!caution! check the boundaries (y,x) to prevent indexing error
    if(visited[y][x])
        return false;
    if(doyeon>=4)
        return false;
    return true;
}

int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

void chknode(int y,int x,int doyeon){
    if(promising(y,x,doyeon)){
        cout<<y<<' '<<x<<endl;
        if(included.size()==7)
            cnt++;
        else{
            for(int i=0;i<4;i++){
                int ny=y+dy[i];
                int nx=x+dx[i];
                included.insert({y,x});
                chknode(ny,nx,doyeon + (board[y][x]=='Y') );
                included.erase({y,x});
                chknode(ny,nx,doyeon);
            }
        }
    }
}


int main(){
    for(int i=0;i<5;i++)
        cin>>board[i];
    
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++){
            visited[i][j]=true;
            chknode(i,j,0);
        }

    cout<<cnt;
    return 0;
}