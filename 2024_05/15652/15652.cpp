#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N,M;
vector<int> inp;
vector<vector<int>> answer;
vector<int> included;
void chknode(int i){

}
int main(){
    cin>>N>>M;
    inp.resize(N);
    for(int i=0;i<N;i++)
        cin>>inp[i];
    sort(inp.begin(),inp.end());








    for(int i=0;i<answer.size();i++){
        for(int j=0;j<answer[i].size();j++)
            cout<<answer[i][j]<<' ';
        cout<<endl;
    }
    return 0;
}   