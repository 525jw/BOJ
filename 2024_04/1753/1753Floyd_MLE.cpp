/*
# Page
    102p / Chapter 3.(Part1) 34p
# Name 
    Floyd's Algorithm for Shortest Paths
# Description 
    플로이드 알고리즘을 사용해 최단경로 구하기
    거리만 구할 수 있음, 즉 최적값만 구할 수 있음
# Input

# Output

# TimeComplexity
    O(nk)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#define INF 0xffff
using namespace std;
typedef struct vector<vector<int>> matrix_t;
matrix_t W;
//- 각 vertex에서 다른 vertex로 가는 최단경로
matrix_t D;
void floyd(int V,matrix_t& W,matrix_t& D){
    for(int i=1;i<=V;i++)
        for(int j=1;j<=V;j++)
            D[i][j]=W[i][j];
    for(int k=1;k<=V;k++)
        for(int i=1;i<=V;i++)
            for(int j=1;j<=V;j++)
                D[i][j]=min(D[i][j],D[i][k]+D[k][j]);
}
int main(){
    int V,E,K;
    cin>>V>>E>>K;
    W.resize(V+1,vector<int>(V+1,INF));
    D.resize(V+1,vector<int>(V+1,INF));
    int u,v,w;
    for(int i=1;i<=E;i++){
        cin>>u>>v>>w;
        W[u][v]=w;
    }

    //초기화
    for(int i=1;i<=V;i++){
        W[i][i]=0;
        D[i][i]=0;
    }

    floyd(V,W,D);
    
    //D출력
    for(int i=1;i<=V;i++){
        if(D[K][i]==INF) cout<<"INF"<<endl;
        else cout<<D[K][i]<<endl;
    }
    return 0;
}