#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int T,N,K,X,Y,W;
vector<int> D;

vector<int> inDegree;
vector<vector<int>> outLink;
int res;

int main(){
    cin>>T;
    while(T--){
        cin>>N>>K;
        D.clear();
        D.resize(N+1);
        for(int i=1;i<=N;i++)
            cin>>D[i];
        outLink.clear();
        outLink.resize(N+1);
        inDegree.clear();
        inDegree.resize(N+1,0);
        for(int i=1;i<=K;i++){
            cin>>X>>Y;
            outLink[X].push_back(Y);
            inDegree[Y]++;
        }
        cin>>W;

        // for(int i=1;i<=N;i++){
        //     cout<<i<<"-> ";
        //     for(int j=0;j<outLink[i].size();j++){
        //         cout<<outLink[i][j]<<' ';
        //     }
        //     cout<<endl;
        // }

        queue<int> que;
        vector<bool> visited(N+1,false);
        res=0;
        bool flag=true;
        int latetime;

        while(flag){
            //cout<<" : "<<que.size()<<endl;
            // for(int i=1;i<=K;i++)
            //     cout<<inDegree[i]<<' ';
            // cout<<endl;
            latetime=0;
            while(!que.empty()){
                for(int i=0;i<outLink[que.front()].size();i++)
                    inDegree[outLink[que.front()][i]]--;
                visited[que.front()]=true;
                latetime=max(latetime,D[que.front()]);
                que.pop();
            }
            res+=latetime;
            for(int i=1;i<=N;i++){
                if(inDegree[i]==0 && !visited[i]){
                    if(i==W){
                        res+=D[i];
                        flag=false;
                        break;
                    }else{
                        que.push(i);
                    }
                }
            }
        }
        cout<<res<<endl;
    }
    return 0;
}