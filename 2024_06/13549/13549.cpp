#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#define LIM 100000
using namespace std;
int N,K,
    X,lvl,Xsub,Xadd,Xmul
    ,res1=INT_MAX;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> que;
vector<bool> visited;
void bfs(){
    while(!que.empty()){
        lvl=que.top().first;
        X=que.top().second;
        que.pop();
        //cout<<X<<' '<<lvl<<' '<<que.size()<<endl;
        visited[X]=true;
        if(X==K){
            res1=lvl;
            return;
        }else{
            Xadd=X+1;
            Xsub=X-1;
            Xmul=X*2;
            if(Xadd<=LIM && !visited[Xadd])
                que.push(make_pair(lvl+1,Xadd));
            if(Xsub>=0 && !visited[Xsub])
                que.push(make_pair(lvl+1,Xsub));
            if(Xmul<=LIM && !visited[Xmul])
                que.push(make_pair(lvl+1,Xmul));
        }   
    }
}
int main(){
    cin>>N>>K;
    visited.resize(LIM+1,false);
    visited[N]=true;
    que.push(make_pair(0,N));
    bfs();
    cout<<res1;
    return 0;
}