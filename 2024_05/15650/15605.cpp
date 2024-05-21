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
            included.push_back(i+1);
            chknode(i+1);
            included.pop_back();
            chknode(i+1);
        }
    }
}
int main(){
    cin>>N>>M;
    chknode(0);
    for(int i=0;i<answer.size();i++){
        for(int j=0;j<answer[i].size();j++)
            cout<<answer[i][j]<<' ';
        cout<<endl;
    }
    return 0;
}