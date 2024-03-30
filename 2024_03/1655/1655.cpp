#include <iostream>
#include <vector>
#define swap(x,y,tmp) (tmp)=(x),(x)=(y),(y)=(tmp)
using namespace std;
typedef struct _node{
    int left,data,right;
}node;
vector<node> tree;
int push(int num,int inp){//num of node, pushed data
    if
}
int main(){
    int n;
    cin>>n;
    tree.resize(n+1,{0,0,0});
    for(int i=1;i<=n;i++){
        int inp;
        cin>>inp;
        push(i,inp);
    }
}