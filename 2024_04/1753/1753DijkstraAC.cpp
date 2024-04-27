/*
#Difference between dijkstra of joonion lec. and this one
- adj matrix -> adj list
    > adj matrix  
        W[i][j]; // weight from node i to node j
    > adj list  
        W[i]; // vector with elements {node connected to node i,weight to the node} 
    > space complexity : O(V^2) -> O(V+E)
- using a priority queue(Min Heap)
    > priority queue
         // min heap with elements <distance, node index connected to set of visited nodes>
    > repeat E times for heapifing V nodes
    > time complexity : O(V^2) -> O(ElogV)
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 987654321

//- needs starting index, number of vertex, adjacency list
vector<int> dijkstra(int st_idx,int V,vector<pair<int,int>> W[]){
    priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> dist(V+1,INF);

    pq.push({0,st_idx});
    dist[st_idx]=0;

    while(!pq.empty()){
        int cur_dist=pq.top().first;
        int cur_node=pq.top().second;
        pq.pop();
        
        for(int i=1;i<W[cur_node].size();i++){
            int next_dist=W[cur_node][i].second+cur_dist;
            int next_node=W[cur_node][i].first;
            if(dist[next_node]>=next_dist){
                dist[next_node]=next_dist;
                pq.push({next_dist,next_node});
            }
        }
    }
    return dist;
}   

int main(){
    int V,E,K;
    scanf("%d%d%d",&V,&E,&K);
    vector<pair<int,int>> W[V+1];
    int u,v,w;
    //to make W start from index 1
    for(int i=0;i<=V;i++)
        W[i].push_back({INF,INF});
    for(int i=1;i<=E;i++){
        scanf("%d%d%d",&u,&v,&w);
        W[u].push_back({v,w});
    }


    vector<int> dist=dijkstra(K,V,W);
    
    for(int i=1;i<dist.size();i++){
        if(dist[i]==INF) printf("INF\n");
        else printf("%d\n",dist[i]);
    }
}