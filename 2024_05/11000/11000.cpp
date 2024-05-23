#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef struct pair<long long,long long> lec;
struct compare{
    bool operator()(const lec& a,const lec& b){
        if(a.second==b.second)  
            return a.first>b.first;
        else return a.second>b.second;
    }
};
priority_queue<lec,vector<lec>,compare> pq;


int main(){
    int N;
    cin>>N;
    long long S,T;
    while(N--){
        cin>>S>>T;
        pq.push({S,T});
    }
    // while(!pq.empty()){
    //     cout<<pq.top().first<<' '<<pq.top().second<<endl;
    //     pq.pop();
    // }
    int cnt=1;
    int maxval=-1;
    long long endtime=0;
    while(!pq.empty()){
        if(endtime<=pq.top().first){
            maxval=maxval<cnt?cnt:maxval;
            endtime=pq.top().second;
            cnt=0;
        }
        pq.pop();
        cnt++;
    }
    cout<<maxval;
}