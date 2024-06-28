#include <iostream>
#include <vector>
using namespace std;

typedef struct _node{
    int num;
    int weight;
    struct _node* link;
}node;
vector<node*> header;
vector<bool> visited;
int stp,maxdist;

node* createNode(int to,int weight){
    node* newnode=(node*)malloc(sizeof(node));
    newnode->num=to;
    newnode->weight=weight;
    newnode->link=NULL;
    return newnode;
}

void dfs(int from,int dist){
    visited[from]=true;
    node* to_node=header[from];
    if(maxdist<dist){
        maxdist=dist;
        stp=from;
    }
    while(to_node){
        if(!visited[to_node->num])
            dfs(to_node->num,dist+to_node->weight);
        to_node=to_node->link;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int V;
    cin>>V;
    header.resize(V+1);
    int from,to,weight;
    for(int i=0;i<V;i++){
        cin>>from;
        while(1){
            cin>>to;
            if(to==-1) break;
            cin>>weight;

            if(header[from]==NULL){
                header[from]=createNode(to,weight);
            }else{
                node* cur=header[from];
                while(cur->link)
                    cur=cur->link;
                cur->link=createNode(to,weight);
            }
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