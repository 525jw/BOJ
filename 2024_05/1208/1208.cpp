#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int N,S;
vector<int> W;
map<int,int> subsum;
long long cnt;

void sum_of_left(int i,int sum){
    if(i==N/2)
        subsum[sum]++;
    else{
        sum_of_left(i+1,sum+W[i]);
        sum_of_left(i+1,sum);
    }
}
void sum_of_right(int i,int sum){
    if(i==N)
        cnt+=subsum[S-sum];
    else{
        sum_of_right(i+1,sum+W[i]);
        sum_of_right(i+1,sum);
    }
}
int main(){
    cin>>N>>S;
    W.resize(N);
    for(int i=0;i<N;i++)    
        cin>>W[i];
    sum_of_left(0,0);
    // for(auto it=subsum.begin();it!=subsum.end();it++)
    //     cout<<it->first<<' '<<it->second<<endl;
    sum_of_right(N/2,0);

    if(S==0) cnt--;
    cout<<cnt;
    return 0;
}