#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

typedef pair<double,double> location;

//vertex
typedef struct _vertex{
    location loc; 
    int idx; //1~n
}vertex;
vector<vertex> stars;

//edge
typedef struct _edge{
    int u;
    int v;
    double w;
}edge;
struct compare{
    bool operator()(const edge& a,const edge& b){
        return a.w>b.w;
    }
};
priority_queue<edge,vector<edge>,compare> pq;

//num of vertex
int n;

//find  distance
double dist(location loc1,location loc2){
    return sqrt( pow(loc1.first-loc2.first,2) + pow(loc1.second-loc2.second,2) );
}

//kruskal
vector<int> dset;
void dset_init(){
    dset.resize(n+1);
    for(int i=1;i<=n;i++)
        dset[i]=i;
}
int dset_find(int i){
    while(dset[i]!=i)
        i=dset[i];
    return i;
}
void dset_union(int u,int v){
    u=dset_find(u);
    dset[u]=v;
}
double kruskal(){
    double ret=0;

    dset_init();

    edge e;
    int i=0;
    while(i<n-1){
        e=pq.top(); pq.pop();
        if(dset_find(e.u)==dset_find(e.v))
            continue;
        ret+=e.w;
        i++;
        dset_union(e.u,e.v);
    }

    return ret;
}

int main(){
    cin>>n;
    stars.resize(n+1);
    for(int i=1;i<=n;i++){
        stars[i].idx=i;
        cin>>stars[i].loc.first>>stars[i].loc.second;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            pq.push({i,j,dist(stars[i].loc,stars[j].loc)});
        }
    }

    // while(!pq.empty()){
    //     cout<<pq.top().u<<' '<<pq.top().v<<' '<<pq.top().w<<endl;
    //     pq.pop();
    // }

    printf("%.2lf",kruskal());

    return 0;
}