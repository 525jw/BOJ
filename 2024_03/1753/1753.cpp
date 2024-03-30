#include <iostream>
#include <vector>
#define VERTEXMAX 20001
using namespace std;
int v,e,k,i,j;
int map[VERTEXMAX][VERTEXMAX];
int main(){
    cin >> v >> e;
    cin >> k;
    for(i=0;i<e;i++){
        int u,vv,w;
        cin >> u >> vv >>w;
        map[u][vv]=w;
    }
    vector<int> weight(v);
    vector<int> visit(v);

    return 0;
}