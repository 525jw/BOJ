#include <iostream>
#include <vector>
#define MODNUM 10007
using namespace std;
vector<vector<int>> cache;
int bicoef(int n,int k){
    if(cache[n][k]!=-1) return cache[n][k];
    else if(k<=0 || n<=k) return cache[n][k]=1;
    else return cache[n][k]=(bicoef(n-1,k-1)+bicoef(n-1,k))%MODNUM;
}
int main(){
    int n,k;
    cin>>n>>k;
    cache.resize(n+1,vector<int>(k+1,-1));
    cout<<bicoef(n,k);    
    return 0;
}