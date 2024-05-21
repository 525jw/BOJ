#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N,M;
vector<int> inp;
vector<vector<int>> answerlist;
vector<int> included;
vector<bool> visited;
void chknode(int i){
    if(i==M){
        answerlist.push_back(included);
    }
    else{
        for(int j=0;j<N;j++){
            if(!visited[j]){
                included.push_back(inp[j]);
                visited[j]=true;
                chknode(i+1);
                included.pop_back();
                visited[j]=false;
            }
        }
    }
}
int main(){
    scanf("%d %d",&N,&M);
    inp.resize(N);
    for(int i=0;i<N;i++)
        scanf("%d",&inp[i]);
    sort(inp.begin(),inp.end());

    visited.resize(N,false);
    chknode(0);

    for(int i=0;i<answerlist.size();i++){
        for(int j=0;j<answerlist[i].size();j++)
            printf("%d ",answerlist[i][j]);
        printf("\n");
    }
    return 0;
}   