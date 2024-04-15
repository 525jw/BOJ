#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 1LL<<31-1
typedef struct vector<vector<long long>> matrix;
long long solve(long long i,long long j,vector<long long> d,matrix& M){
    if(M[i][j]!=-1) return M[i][j];
    else if(i==j){ return M[i][j]=0; }
    else{
        long long minval=INF;
        for(long long k=i;k<j;k++){
            long long nowval=solve(i,k,d,M)+solve(k+1,j,d,M)+d[i-1]*d[j]*d[k];
            minval=(minval>nowval) ? nowval : minval;
        }
        return M[i][j]=minval;
    }
}
int main(){ 
    long long n; cin>>n;
    vector<long long> d(n+1);
    for(long long i=0;i<=n;i++){
        cin>>d[i]>>d[i+1];
    }
    //cache[i][j]=cache[i][k]+cache[k+1][j]+d[i-1]*d[k]*d[j];
    matrix M(n+1,vector<long long>(n+1,-1));

    long long res=solve(1,n,d,M);

    cout<<res<<endl; 

    return 0;
}