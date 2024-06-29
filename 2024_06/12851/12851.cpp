#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#define LIM 100000
using namespace std;
int N,K,
    X,lvl,Xsub,Xadd,Xmul
    ,res1=INT_MAX,res2=0;
queue<pair<int,int>> que;
vector<bool> visited;
void bfs(){
    while(!que.empty()){
        X=que.front().first;
        lvl=que.front().second;
        //cout<<X<<' '<<lvl<<endl;
        visited[X]=true;
        if(lvl<=res1){
            if(X==K){
                res1=lvl;
                res2++;
            }else{
                Xadd=X+1;
                Xsub=X-1;
                Xmul=X*2;
                if(Xadd<=LIM && !visited[Xadd])
                    que.push({Xadd,lvl+1});
                if(Xsub>=0 && !visited[Xsub])
                    que.push({Xsub,lvl+1});
                if(Xmul<=LIM && !visited[Xmul])
                    que.push({Xmul,lvl+1});
            }
        }
        que.pop();
    }
}
int main(){
    cin>>N>>K;
    visited.resize(LIM+1,false);
    visited[N]=true;
    que.push({N,0});
    bfs();
    cout<<res1<<endl<<res2;
    return 0;
}