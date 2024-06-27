#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct _element{
    int num;
    int time;
    int inDegree;
    vector<int> outLink;
}element;

int T,N,K,X,Y,W;
vector<int> D;
vector<element> nodelist;

struct cmp{
    bool operator()(element a, element b){
        return a.time > b.time;
    }
};
priority_queue<element,vector<element>,cmp> pq,temp;

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&N,&K);
        D.clear();
        D.resize(N+1);
        nodelist.clear();
        nodelist.resize(N+1);
        for(int i=1;i<=N;i++){
            scanf("%d",&D[i]);
            nodelist[i].num=i;
            nodelist[i].time=D[i];
            nodelist[i].inDegree=0;
            nodelist[i].outLink.clear();
        }
        for(int i=1;i<=K;i++){
            scanf("%d %d",&X,&Y);
            nodelist[X].outLink.push_back(Y);
            nodelist[Y].inDegree++;
        }
        scanf("%d",&W);

        while(!pq.empty()) pq.pop();
        while(!temp.empty()) temp.pop();
        vector<bool> visited(N+1,false);
        element curjob;
        bool flag=true;

        while(flag){
            // for(int i=1;i<=N;i++){
            //     cout<<nodelist[i].time<<' ';
            // }
            // cout<<endl;
            while(!pq.empty()){
                curjob=pq.top();
                visited[curjob.num]=true;
                for(int i=0;i<curjob.outLink.size();i++){
                    nodelist[curjob.outLink[i]].inDegree--;
                    nodelist[curjob.outLink[i]].time=max(D[curjob.outLink[i]]+curjob.time,nodelist[curjob.outLink[i]].time);
                }
                pq.pop();
            }

            for(int i=1;i<=N;i++){
                if(nodelist[i].inDegree==0 && !visited[i]){
                    if(i==W){
                        curjob=nodelist[i];
                        flag=false;
                    }else{
                        pq.push(nodelist[i]);
                    }
                }
            }
        }
        printf("%d\n",curjob.time);
    }
    return 0;
}