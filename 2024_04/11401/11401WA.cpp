#include <iostream>
#include <vector>
#define MODNUM 1000000007
using namespace std;
long long bicoef(long long n,long long k){
    if(k<=0 || n<=k) return 1;
    else {
        long long part=bicoef(n-1,k);
        return ( part%MODNUM + part*k/(n-k)%MODNUM )%MODNUM;
    }
}
int main(){
    long long n,k;
    cin>>n>>k;
    cout<<bicoef(n,k);    
    return 0;
}