#include <iostream>
#include <queue>
#include <vector>
#define undeclared 100001
using namespace std;
int main(){
    int N; cin>>N;
    priority_queue<int,vector<int>,less<int>> pql;
    priority_queue<int,vector<int>,greater<int>> pqr;
    int root=undeclared;
    while(N--){
        int inp; scanf("%d",&inp);
        if(root==undeclared)
            root=inp;
        else{
            if(inp<root)
                pql.push(inp);
            else
                pqr.push(inp);
            
            if(pql.size()>pqr.size()){
                pqr.push(root);
                root=pql.top();
                pql.pop();
            }
            else if(pql.size()+1<pqr.size()){
                pql.push(root);
                root=pqr.top();
                pqr.pop();
            }
        }
        // if(!pql.empty()) cout<<"l:"<<pql.top()<<' ';
        // if(!pqr.empty()) cout<<"r:"<<pqr.top()<<' ';
        printf("%d\n",root);
    }
    return 0;
}