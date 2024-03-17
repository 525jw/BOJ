#include <iostream>
#define QUESIZE 100000
using namespace std;

int mat[16][16],n,maxv=-1;
int dp[(1<<16)-1][16][10]={0};
typedef struct _queue{
    int visited; int seller; int nowprice; int owned;
} queue;
queue que[QUESIZE];
/*
solution : dp[visited][seller]+[nowprice]
visited bitmask 16bit integer num 0~2^16-1(65535)
*/

void bfs(){
    int front=0,rear=0;

    que[rear]={1,1,0,1};
    rear=(rear+1)%QUESIZE;
    while(front!=rear){
        cout << "# " << front << ' ' << rear << " #" << endl;
        if(dp[que[front].visited][que[front].seller][que[front].nowprice] > que[front].owned){front++;continue;}
        dp[que[front].visited][que[front].seller][que[front].nowprice]=que[front].owned;
        if(maxv<que[front].owned) maxv=que[front].owned;
        //if(maxv==n) break;
        for(int i=1;i<=n;i++){
            if(i==que[front].seller || que[front].nowprice>mat[que[front].seller][i] || que[front].visited & (1<<(i-1))) continue;

            //cout << que[front].seller << " to " << i << " for " << mat[que[front].seller][i]<<endl;
            que[rear] = {que[front].visited | (1<<i-1) , i , mat[que[front].seller][i] , que[front].owned+1};
            rear=(rear+1)%QUESIZE;
        }
        front=(front+1)%QUESIZE;
    }
}

int main(){
    cin >> n;
    int i,j;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%1d",&mat[i][j]);
        }
    }
    bfs();
    cout<<maxv;
    return 0;
}