#include <iostream>
#define QUESIZE 10000
using namespace std;
typedef struct _queue{
    int y,x;
    bool firemove;
}queue;
char map[1001][1001];
int row,cul,i,j;
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
int visited[1001][1001];
int firenum;
int bfs(){
    queue que[QUESIZE]; int front=0,rear=firenum;
    for(i=0;i<row;i++){
        for(j=0;j<cul;j++){
            if(map[i][j]=='F') que[--firenum]={i,j,true};
            else if(map[i][j]=='J') {
                visited[i][j]=1;
                que[rear]={i,j,false};
                rear=(rear+1)%QUESIZE;
            }
        }
    }
    int minv=1000*1000;
    while(front!=rear){
        //cout << front << ' ' << rear << endl;
        // for(i=0;i<row;i++){
        //     for(j=0;j<cul;j++){
        //         if(visited[i][j]==1000*1000) cout<<"@ ";
        //         else cout<<visited[i][j]<<' ';
        //     }
        //     cout<<endl;
        // }
        // cout<<"!!!!!!!!!!!!!!!!!!!!!"<<endl;   

        if(que[front].firemove){
            for(i=0;i<4;i++){
                int ny=que[front].y+dy[i];
                int nx=que[front].x+dx[i];
                if(map[ny][nx]!='#' && map[ny][nx]!='F' && ny>=0 && nx>=0 && ny<row && nx<cul ){
                    map[ny][nx]='F';
                    que[rear]={ny,nx,true};
                    rear=(rear+1)%QUESIZE;
                }
            }
        }
        else{
            for(i=0;i<4;i++){
                int ny=que[front].y+dy[i];
                int nx=que[front].x+dx[i];
                if(ny<0 || nx <0 || ny>=row || nx>=cul) {
                    minv=min(minv,visited[que[front].y][que[front].x]);
                }
                else if(map[ny][nx]=='.'&&!visited[ny][nx]) {
                    que[rear]={ny,nx,false};
                    rear=(rear+1)%QUESIZE;
                    visited[ny][nx]=visited[que[front].y][que[front].x]+1;
                }
            }
        }
        //if((rear+1)%QUESIZE==front){cout<<"full!";exit(1);}
        front=(front+1)%QUESIZE;
    }
    return minv;
}
int main(){
    cin >> row >> cul;
    for(i=0;i<row;i++){
        for(j=0;j<cul;j++){
            cin>>map[i][j];
            if(map[i][j]=='F') firenum++;
        }
    }
    int answer=bfs();
    if(answer==1000*1000) cout << "IMPOSSIBLE";
    else cout << answer;
    return 0;
}