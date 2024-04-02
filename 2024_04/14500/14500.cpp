#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,m,maxnum=-1;
vector<vector<int>> board;
int retval(int y,int x){
    if(y<0 || x<0 || y>=n || x>=m) return -1;
    else return board[y][x];
}
void solve(){
    int i,j;
    int val1,val2,val3,val4;

    // ㅁㅁㅁㅁ(가로)
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            val1=retval(i,j);
            val2=retval(i,j+1);
            val3=retval(i,j+2);
            val4=retval(i,j+3);
            if(val1!=-1 && val2!=-1 && val3!=-1 && val4!=-1) maxnum=max(maxnum,val1+val2+val3+val4);
        }
    }

    // ㅁㅁㅁㅁ(세로)
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            val1=retval(i,j);
            val2=retval(i+1,j);
            val3=retval(i+2,j);
            val4=retval(i+3,j);
            if(val1!=-1 && val2!=-1 && val3!=-1 && val4!=-1) maxnum=max(maxnum,val1+val2+val3+val4);
        }
    }

    /*
    ㅁㅁ
    ㅁㅁ
    */
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            val1=retval(i,j);
            val2=retval(i,j+1);
            val3=retval(i+1,j);
            val4=retval(i+1,j+1);
            if(val1!=-1 && val2!=-1 && val3!=-1 && val4!=-1) maxnum=max(maxnum,val1+val2+val3+val4);
        }
    }

    /*
    ㅁ
    ㅁ
    ㅁㅁ
    */
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            val1=retval(i,j);
            val2=retval(i+1,j);
            val3=retval(i+2,j);
            val4=retval(i+2,j+1);
            if(val1!=-1 && val2!=-1 && val3!=-1 && val4!=-1) maxnum=max(maxnum,val1+val2+val3+val4);
        }
    }

    /*
        ㅁ
    ㅁㅁㅁ
    */
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            val1=retval(i,j);
            val2=retval(i,j+1);
            val3=retval(i,j+2);
            val4=retval(i-1,j+2);
            if(val1!=-1 && val2!=-1 && val3!=-1 && val4!=-1) maxnum=max(maxnum,val1+val2+val3+val4);
        }
    }

    /*
    ㅁㅁ
      ㅁ
      ㅁ
    */
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            val1=retval(i,j);
            val2=retval(i,j+1);
            val3=retval(i+1,j+1);
            val4=retval(i+2,j+1);
            if(val1!=-1 && val2!=-1 && val3!=-1 && val4!=-1) maxnum=max(maxnum,val1+val2+val3+val4);
        }
    }

    /*
    ㅁㅁㅁ
    ㅁ
    */
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            val1=retval(i,j);
            val2=retval(i+1,j);
            val3=retval(i,j+1);
            val4=retval(i,j+2);
            if(val1!=-1 && val2!=-1 && val3!=-1 && val4!=-1) maxnum=max(maxnum,val1+val2+val3+val4);
        }
    }

    /*
      ㅁ
      ㅁ
    ㅁㅁ
    */
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            val1=retval(i,j);
            val2=retval(i+1,j);
            val3=retval(i+2,j);
            val4=retval(i+2,j-1);
            if(val1!=-1 && val2!=-1 && val3!=-1 && val4!=-1) maxnum=max(maxnum,val1+val2+val3+val4);
        }
    }

    /*
    ㅁ
    ㅁㅁㅁ
    */
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            val1=retval(i,j);
            val2=retval(i+1,j);
            val3=retval(i+1,j+1);
            val4=retval(i+1,j+2);
            if(val1!=-1 && val2!=-1 && val3!=-1 && val4!=-1) maxnum=max(maxnum,val1+val2+val3+val4);
        }
    }

    /*
    ㅁㅁ
    ㅁ
    ㅁ
    */
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            val1=retval(i,j);
            val2=retval(i+1,j);
            val3=retval(i+2,j);
            val4=retval(i,j+1);
            if(val1!=-1 && val2!=-1 && val3!=-1 && val4!=-1) maxnum=max(maxnum,val1+val2+val3+val4);
        }
    }
    /*
    ㅁㅁㅁ
        ㅁ
    */
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            val1=retval(i,j);
            val2=retval(i,j+1);
            val3=retval(i,j+2);
            val4=retval(i+1,j+2);
            if(val1!=-1 && val2!=-1 && val3!=-1 && val4!=-1) maxnum=max(maxnum,val1+val2+val3+val4);
        }
    }

    /*
    ㅁ
    ㅁㅁ
      ㅁ
    */
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            val1=retval(i,j);
            val2=retval(i+1,j);
            val3=retval(i+1,j+1);
            val4=retval(i+2,j+1);
            if(val1!=-1 && val2!=-1 && val3!=-1 && val4!=-1) maxnum=max(maxnum,val1+val2+val3+val4);
        }
    }

    /*
      ㅁㅁ
    ㅁㅁ
    */
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            val1=retval(i,j);
            val2=retval(i,j+1);
            val3=retval(i-1,j+1);
            val4=retval(i-1,j+2);
            if(val1!=-1 && val2!=-1 && val3!=-1 && val4!=-1) maxnum=max(maxnum,val1+val2+val3+val4);
        }
    }
    /*
      ㅁ
    ㅁㅁ
    ㅁ
    */
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            val1=retval(i,j);
            val2=retval(i+1,j);
            val3=retval(i+1,j-1);
            val4=retval(i+2,j-1);
            if(val1!=-1 && val2!=-1 && val3!=-1 && val4!=-1) maxnum=max(maxnum,val1+val2+val3+val4);
        }
    }
    /*
    ㅁㅁ
      ㅁㅁ
    */
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            val1=retval(i,j);
            val2=retval(i,j+1);
            val3=retval(i+1,j+1);
            val4=retval(i+1,j+2);
            if(val1!=-1 && val2!=-1 && val3!=-1 && val4!=-1) maxnum=max(maxnum,val1+val2+val3+val4);
        }
    }
    /*
      ㅁ
    ㅁㅁㅁ
    */
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            val1=retval(i,j);
            val2=retval(i,j+1);
            val3=retval(i,j+2);
            val4=retval(i-1,j+1);
            if(val1!=-1 && val2!=-1 && val3!=-1 && val4!=-1) maxnum=max(maxnum,val1+val2+val3+val4);
        }
    }
    /*
    ㅁㅁㅁ
      ㅁ
    */
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            val1=retval(i,j);
            val2=retval(i,j+1);
            val3=retval(i,j+2);
            val4=retval(i+1,j+1);
            if(val1!=-1 && val2!=-1 && val3!=-1 && val4!=-1) maxnum=max(maxnum,val1+val2+val3+val4);
        }
    }
    /*
    ㅁ
    ㅁㅁ
    ㅁ
    */
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            val1=retval(i,j);
            val2=retval(i+1,j);
            val3=retval(i+2,j);
            val4=retval(i+1,j+1);
            if(val1!=-1 && val2!=-1 && val3!=-1 && val4!=-1) maxnum=max(maxnum,val1+val2+val3+val4);
        }
    }
    /*
      ㅁ
    ㅁㅁ
      ㅁ
    */
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            val1=retval(i,j);
            val2=retval(i+1,j);
            val3=retval(i+2,j);
            val4=retval(i+1,j-1);
            if(val1!=-1 && val2!=-1 && val3!=-1 && val4!=-1) maxnum=max(maxnum,val1+val2+val3+val4);
        }
    }
}
int main(){
    cin>>n>>m;
    board.resize(n,vector<int>(m));
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            cin>>board[i][j];
    solve();
    cout<<maxnum;
    return 0;
}