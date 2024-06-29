#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct pair<int,int> t_mv;

struct compare{
    bool operator()(const t_mv &a,const t_mv &b){
        if(a.second==b.second) // unnecessary?
            a.first>b.first;
        return a.second<b.second;
    }
};
vector<t_mv> item;
vector<int> nsack;
priority_queue<t_mv,vector<t_mv>,compare> pq;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,K,M,V,C; 
    cin>>N>>K;
    for(int i=0;i<N;i++){
        cin>>M>>V;
        item.push_back(make_pair(M,V));
    }
    for(int i=0;i<K;i++){
        cin>>C;
        nsack.push_back(C);
    }
    sort(item.begin(),item.end(),greater<t_mv>());
    sort(nsack.begin(),nsack.end(),greater<int>());

    // for(int i=0;i<N;i++){
    //     cout<<'#'<<item[i].first<<' '<<item[i].second<<endl;
    // }
    // for(int i=0;i<K;i++){
    //     cout<<'@'<<nsack[i]<<endl;
    // }

    long long res=0;
    for(int i=0;i<K;i++){
        //cout<<'$'<<res<<endl;
        int curnsack=nsack.back(); 
        nsack.pop_back();

        while(!item.empty() && item.back().first<=curnsack ){
            pq.push(item.back()); 
            item.pop_back();
        }

        if(!pq.empty()){
            res+=pq.top().second; 
            pq.pop();
        }
    }

    cout<<res;
    return 0;
}