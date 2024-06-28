#include <iostream>
#include <vector>
using namespace std;

int V;
vector<vector<int>> W;
vector<bool> visited;
vector<vector<int>> cnctnode;//connected node

int dfs(int from){
    visited[from]=true;
    int to;
    int maxval=0;
    for(int i=0;i<cnctnode[from].size();i++){
        to=cnctnode[from][i];
        if(!visited[to]){
            maxval=max(maxval,W[from][to]+dfs(to));
        }
    }
    return maxval;
}
int main(){
    cin>>V;
    W.resize(V+1,vector<int>(V+1,0));
    visited.resize(V+1,false);
    cnctnode.resize(V+1);
    int from,to,weight;
    int maxweight=-1,maxfrom,maxto;
    for(int i=1;i<=V;i++){
        cin>>from;
        while(1){
            cin>>to;
            if(to==-1) break;
            cin>>weight;
            W[from][to]=weight;
            cnctnode[from].push_back(to);
            if(weight>maxweight){
                maxfrom=from;
                maxto=to;
                maxweight=weight;
            }
        }
    }

    int res=0;
    visited[maxto]=true;
    res+=dfs(maxfrom);

    fill(visited.begin(),visited.end(),false);
    visited[maxfrom]=true;
    res+=dfs(maxto);

    res+=maxweight;

    cout<<res;
    return 0;
}