#include <iostream>
#include <vector>
#include <algorithm>
#define INF 9999999
using namespace std;
int makeone(int x,vector<int>& cache){
    //cout<<'#'<<x<<endl;
    if(cache[x]) return cache[x];
    else if(x==1) return cache[x]=0;
    else{
        int minval=INF;
        if(x%3==0) minval=min(minval,1+makeone(x/3,cache));
        if(x%2==0) minval=min(minval,1+makeone(x/2,cache));
        minval=min(minval,1+makeone(x-1,cache));
        return cache[x]=minval;
    }
}
int main(){
    int x;
    cin>>x;
    vector<int> cache(x+1,0);
    cout<<makeone(x,cache);
    return 0;
}