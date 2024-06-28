#include <iostream>
#include <vector>
using namespace std;

int V;
vector<vector<int>> W;
vector<bool> visited;
vector<vector<int>> cnctnode;

void dfs(int from){
    visited[from]=true;
    for(int to=1;to<=V;to++){

    }
}
int main(){
    cin>>V;
    W.resize(V+1,vector<int>(V+1,0));
    visited.resize(V+1,false);
    int to,weight;
    int maxweight=-1,maxfrom,maxto;
    for(int from=1;from<=V;from++){
        while(1){
            cin>>to;
            if(to==-1) break;
            cin>>weight;
            W[from][to]=weight;
            if(weight>maxweight){
                maxfrom=from;
                maxto=to;
                maxweight=weight;
            }
        }
    }

    visited[maxto]=true;
    dfs(maxfrom);

    visited.clear();
    visited[maxfrom]=true;
    dfs(maxto);


    return 0;
}