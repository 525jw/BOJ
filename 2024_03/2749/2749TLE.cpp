#include <iostream>
#define MODSIZE 1000000
using namespace std;
long long fibo(long long n){
    //cout << n << endl;
    if(n<=1) return n;
    else if(n==2) return 1;
    long long fhalfm=fibo(n/2-1)%MODSIZE;
    long long fhalf=fibo(n/2)%MODSIZE;
    long long fhalfp=(fhalfm+fhalf)%MODSIZE;
    return ( (n%2==0) ? ((fhalfp*fhalf)%MODSIZE + (fhalf*fhalfm)%MODSIZE) : (fhalfp*fhalfp)%MODSIZE+(fhalf*fhalf)%MODSIZE ) %MODSIZE;
}
int main(){
    long long n;
    cin >> n;
    cout << fibo(n);
    return 0;
}