#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#define NODEMAX 1000001
using namespace std;

vector<set<int>> sns;
int n,u,v;
int cache[NODEMAX];

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> u >> v;
        sns[u].insert(v);
        sns[v].insert(u);
    }
    return 0;
}