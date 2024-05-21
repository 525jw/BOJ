#include <iostream>
#include <vector>
using namespace std;
int N,M;
vector<vector<int>> answer;
vector<int> included;
void chknode(int i){
    if(i<=N){
        if(included.size()==M){
            answer.push_back(included);
        }else{
            for(int j=i;j<=N;j++){
                included.push_back(j);
                chknode(j);
                included.pop_back();
            }
        }
    }
}
int main(){
    cin>>N>>M;
    chknode(1);
    for(int i=0;i<answer.size();i++){
        for(int j=0;j<answer[i].size();j++)
            cout<<answer[i][j]<<' ';
        cout<<endl;
    }
    return 0;
}