#include <iostream>
#include <vector>
#include <cmath>
#define VER '|'
#define HOR '-'
#define CASEA 1 //h=2
#define CASEB 2 //h=2^(i+1)-2  ++ i is bigger than one
#define CASEC 3 //h=2^(i+1)+2^(i-1)-2
using namespace std;
typedef struct _crd{
    int y,x;
}crd;
vector<int> possible(1050);
vector<string> stairs;
void btet(crd stp,int h);
void ptet(crd stp,int h);
void qtet(crd stp,int h);
void dtet(crd stp,int h);
void tet();
void Rtet(crd stp,int h);
void Ttet(crd stp,int h);
int n;
int main(){
    cin >> n;
    int i;
    char str[1050];
    for(i=0;i<=n+1;i++)
        str[i]='0';
    for(i=0;i<=n+1;i++)
        stairs.push_back(str);
    possible[2]=CASEA;
    int b=0,c=0;
    for(i=2;b<=n||c<=n;i++){
        b=pow(2,i+1)-2,c=5*pow(2,i)/2-2;
        possible[b]=CASEB;
        possible[c]=CASEC;
    }
    if(possible[n]) tet();
    else cout << "impossible";
    return 0;
}
void tet(){
    int h;
    switch (possible[n]){
        case CASEA:
            btet({n,1},2);
            break;
        case CASEB:
            h=(n+2)/2;
            Ttet({n,1},h);
            break;
        case CASEC:
            h=(n+2)/5*2;
            btet({n,1},h/2);
            qtet({n-h/2-h/4+1,h/2},h/2);
            btet({n-h/2-h/4,1},h/2);
            qtet({n-h-h/2+1,h/2},h/2);
            Rtet({n-h-h/2,1},h/2);
            Ttet({n,1+h/2},h);      
            break;
    }
    
    int i,j;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(stairs[i][j]!='0') cout<<stairs[i][j];
            //cout<<stairs[i][j] << ' ';
        }
        cout<<'\n';
    }
}
void Ttet(crd stp,int h){
    if(h==2) btet(stp,h);
    else{
        btet({stp.y,stp.x},h);
        Ttet({stp.y,stp.x+h},h/2);
        Ttet({stp.y-h/2,stp.x+h/2},h/2);
        Ttet({stp.y-h,stp.x},h/2);
    }
}
void Rtet(crd stp,int h){
    if(h==2) btet(stp,h);
    else{
        btet(stp,h);
        Rtet({stp.y-h,stp.x},h/2);
        Rtet({stp.y-h/2,stp.x+h/2},h/2);
    }
}
void btet(crd stp,int h){
    if(h==2){
        stairs[stp.y][stp.x]='b';
        stairs[stp.y-1][stp.x]=VER;
        stairs[stp.y][stp.x+1]=HOR;
    }
    else{
        btet(stp,h/2);
        btet({stp.y-h/4,stp.x+h/4},h/2);
        dtet({stp.y,stp.x+h-1},h/2);
        ptet({stp.y-h+1,stp.x},h/2);
    }
}
void ptet(crd stp,int h){
    if(h==2){
        stairs[stp.y][stp.x]='p';
        stairs[stp.y+1][stp.x]=VER;
        stairs[stp.y][stp.x+1]=HOR;
    }
    else{
        ptet(stp,h/2);
        ptet({stp.y+h/4,stp.x+h/4},h/2);
        qtet({stp.y,stp.x+h-1},h/2);
        btet({stp.y+h-1,stp.x},h/2);
    }
}
void qtet(crd stp,int h){
    if(h==2){
        stairs[stp.y][stp.x]='q';
        stairs[stp.y+1][stp.x]=VER;
        stairs[stp.y][stp.x-1]=HOR;
    }
    else{
        qtet(stp,h/2);
        qtet({stp.y+h/4,stp.x-h/4},h/2);
        ptet({stp.y,stp.x-h+1},h/2);
        dtet({stp.y+h-1,stp.x},h/2);
    }
}
void dtet(crd stp,int h){
    if(h==2){
        stairs[stp.y][stp.x]='d';
        stairs[stp.y-1][stp.x]=VER;
        stairs[stp.y][stp.x-1]=HOR;
    }
    else{
        dtet(stp,h/2);
        dtet({stp.y-h/4,stp.x-h/4},h/2);
        btet({stp.y,stp.x-h+1},h/2);
        qtet({stp.y-h+1,stp.x},h/2);
    }
}