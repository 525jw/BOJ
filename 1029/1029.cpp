#include <iostream>
using namespace std;
int map[16][16],n,i,j;
int dfs(){
    
}
int main(){
    cin >> n;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cin >> map[i][j];
        }
    }
    cout << dfs();
    return 0;
}