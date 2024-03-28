/*
#include <iostream>
#include <vector>
#define VER '|'
#define HOR '-'
#define RMDONE 0 // n%3=1 impossible
#define RMDTWO 1 // n%3=2 possible
#define RMDZRO 2 // n%3=0 possible
#define NUMNINE 3 // no general rule
using namespace std;
typedef struct _crd{
    int y,x;
}crd;
int i,j;
vector<string> stairs;
void btet(crd stp,int h);
void ptet(crd stp,int h);
void qtet(crd stp,int h);
void dtet(crd stp,int h);
void tromino(vector<int> possible,int n,crd stp);
int main(){
    int n;
    cin>>n;
    vector<int> possible(n+1,false);
    stairs.resize(n+5);
    possible={false,false,RMDTWO,false,false,false,RMDZRO,false,RMDTWO,NUMNINE,};
    for(i=10;i<=n;i++){
        if(n%3==2&&possible[n-2]) possible[n]=RMDTWO;
        else if(n%3==0&&possible[n-6]) possible[n]=RMDZRO;
    }
    if(possible[n]) tromino(possible,n,{n,1});
    else cout << "impossible";
    return 0;
}
void tromino(vector<int> possible,int n,crd stp){
    if(n<2) return;
    int cnt=0;
    switch (possible[n])
    {
    case RMDTWO :
        tromino(possible,n-2,{stp.y-2,stp.x});
        btet({stp.y,stp.x+n-2},2);
        cnt=stp.x;
        while(cnt<=stp.x+n-2){
            btet({stp.y,cnt},2);
            qtet({stp.y-1,cnt+2},2);
            cnt+=3;
        }
        break;    
    case RMDZRO :
        tromino(possible,n-6,{stp.y-6,stp.x});
        btet({stp.y,stp.x+n})
        break;
    case NUMNINE :
        
        break;
    }
}
void btet(crd stp,int n){
    if(n==2){
        stairs[stp.y][stp.x]='b';
        stairs[stp.y-1][stp.x]=VER;
        stairs[stp.y][stp.x+1]=HOR;
    }
    else{
        btet(stp,n/2);
        btet({stp.y-n/4,stp.x+n/4},n/2);
        dtet({stp.y,stp.x+n-1},n/2);
        ptet({stp.y-n+1,stp.x},n/2);
    }
}
void ptet(crd stp,int n){
    if(n==2){
        stairs[stp.y][stp.x]='p';
        stairs[stp.y+1][stp.x]=VER;
        stairs[stp.y][stp.x+1]=HOR;
    }
    else{
        ptet(stp,n/2);
        ptet({stp.y+n/4,stp.x+n/4},n/2);
        qtet({stp.y,stp.x+n-1},n/2);
        btet({stp.y+n-1,stp.x},n/2);
    }
}
void qtet(crd stp,int n){
    if(n==2){
        stairs[stp.y][stp.x]='q';
        stairs[stp.y+1][stp.x]=VER;
        stairs[stp.y][stp.x-1]=HOR;
    }
    else{
        qtet(stp,n/2);
        qtet({stp.y+n/4,stp.x-n/4},n/2);
        ptet({stp.y,stp.x-n+1},n/2);
        dtet({stp.y+n-1,stp.x},n/2);
    }
}
void dtet(crd stp,int n){
    if(n==2){
        stairs[stp.y][stp.x]='d';
        stairs[stp.y-1][stp.x]=VER;
        stairs[stp.y][stp.x-1]=HOR;
    }
    else{
        dtet(stp,n/2);
        dtet({stp.y-n/4,stp.x-n/4},n/2);
        btet({stp.y,stp.x-n+1},n/2);
        qtet({stp.y-n+1,stp.x},n/2);
    }
}
*/