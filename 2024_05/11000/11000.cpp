#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct pair<long long,long long> lec;
priority_queue<long long,vector<long long>,greater<long long>> pq;
vector<lec> lecs;

int main(){
    int N;
    cin>>N;
    long long S,T;
    while(N--){
        cin>>S>>T;
        lecs.push_back({S,T});
    }
    sort(lecs.begin(),lecs.end());
    pq.push(0);
    for(int i=0;i<lecs.size();i++){
        if(pq.top()<=lecs[i].first)
            pq.pop();
        pq.push(lecs[i].second);
    }
    cout<<pq.size();
}