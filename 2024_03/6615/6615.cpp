#include <iostream>
#include <vector>
using namespace std;
void colatz(long long n,vector<long long>& vn){
    while(n!=1){
        vn.push_back((n%2)?(n*3+1):(n/2));
        n=vn.back();
    }
}
vector<long long> va,vb;
long long a,b,sa,sb,c;
int main(){
    while(1){
        va.clear();vb.clear();
        cin>>a>>b;
        if(a==0 || b==0) break;
        va.push_back(a); vb.push_back(b);
        colatz(a,va); colatz(b,vb);
        bool chk=false;
        for(sa=0;sa<va.size() && !chk;sa++)
            for(sb=0;sb<vb.size() && !chk;sb++)
                if(va[sa]==vb[sb]) chk=true;
        sa--;sb--; 
        c=vb[sb];
        printf("%lld needs %lld steps, %lld needs %lld steps, they meet at %lld\n",a,sa,b,sb,c);
    }
    return 0;
}