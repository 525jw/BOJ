#include <iostream>
#include <string>
using namespace std;

int mat[16][16],n,maxv=-1;
int dp[(1<<16)-1][16][10]={0};
/*
solution : dp[visited][seller]+[nowprice]
visited bitmask 16bit integer num 0~2^16-1(65535)
*/

void dfs(int visited, int seller,int nowprice,int owned){
    owned++;
    if(dp[visited][seller][nowprice] > owned) return;
    dp[visited][seller][nowprice]=owned;
    if(maxv<owned) maxv=owned;
    if(maxv==n) {cout << maxv; exit(0);};
    for(int i=1;i<=n;i++){
        if(i==seller) continue;
        if(nowprice>mat[seller][i]) continue;
        if(visited & (1<<i-1)) continue;
        
        visited |= 1<<i-1;
        //cout << seller << " to " << i << " for " << mat[seller][i]<<endl;
        dfs(visited,i,mat[seller][i],owned);
        visited ^= 1<<i-1;
    }
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
    dfs(1,1,0,0);
    cout<<maxv;
    return 0;
}