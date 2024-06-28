#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<pair<int,int>>> adjlist; // adjlist[from]=list of (to,weight)
vector<bool> visited;
int stp,maxdist;

void dfs(int from,int dist){
    visited[from]=true;
    if(maxdist<dist){
        maxdist=dist;
        stp=from;
    }
    for(int i=0;i<adjlist[from].size();i++)
        if(!visited[adjlist[from][i].first])
            dfs(adjlist[from][i].first , dist+adjlist[from][i].second);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int V;
    cin>>V;
    adjlist.resize(V+1);
    int from,to,weight;
    for(int i=0;i<V;i++){
        cin>>from;
        while(1){
            cin>>to;
            if(to==-1) break;
            cin>>weight;

            adjlist[from].push_back(make_pair(to,weight));
        }
    }

    visited.resize(V+1,false);
    dfs(1,0);
    fill(visited.begin(),visited.end(),false);
    maxdist=0;
    dfs(stp,0);

    cout<<maxdist;   
    return 0;
}