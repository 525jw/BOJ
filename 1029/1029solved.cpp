#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int mat[16][16],n;
int cache[(1<<16)-1][16][10]={0};
/*
solution : dp[visited][seller]+[nowprice]
visited bitmask 16bit integer num 0~2^16-1(65535)
*/

int dfs(int visited, int seller,int nowprice){
    int& ret=cache[visited][seller][nowprice];
    if(ret!=-1) return ret;
    ret=0;
    for(int i=1;i<=n;i++){
        if(nowprice>mat[seller][i]) continue; //손해볼장사 스킵
        if(visited & (1<<i-1)) continue; //팔았던사람 스킵
        
        int arg_visited = visited | (1<<i-1);
        //cout << seller << " to " << i << " for " << mat[seller][i]<<endl;
        ret=max(ret,dfs(arg_visited,i,mat[seller][i])+1);
    }
    return ret;
}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> n;
    int i,j;
    for(i=1;i<=n;i++){
        string s;
        cin>>s;
        for(j=1;j<=n;j++){
            mat[i][j]=s[j-1]-'0';
        }
    }
    memset(cache,-1,sizeof(cache));
    cout << dfs(1,1,0)+1;
    return 0;
}