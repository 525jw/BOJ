#include <iostream>
using namespace std;
long long c;
long long pow(long long a,long long b){
    if(b<=1) return a%c;
    else{
        long long d=pow(a,b/2)%c;
        if(b%2==0) return (d%c*d%c)%c;
        else return ((d%c*d%c)%c*a)%c;
    }
}
int main(){
    long long a,b;
    cin>>a>>b>>c;
    cout<<pow(a,b)%c;
    return 0;
}