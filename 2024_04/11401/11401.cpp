#include <iostream>
#include <vector>
#define MODNUM 1000000007
using namespace std;
long long pow(long long num,long long exp){
    
}
long long bicoef(long long n,long long k){
    if(k<=0 || n<=k) return 1;
    else {
        long long part=bicoef(n-1,k);
        long long invel=pow(1/(n-k),MODNUM-2);// inverse element of 1/(n-k)
        
        return ( part%MODNUM + ((part*k)%MODNUM*invel)%MODNUM )%MODNUM;
    }
}
int main(){
    long long n,k;
    cin>>n>>k;
    cout<<bicoef(n,k);    
    return 0;
}