#include <iostream>
#include <vector>
#define VER '|'
#define HOR '-'
using namespace std;
typedef struct _crd{
    int y,x;
}crd;
vector<bool> possible(1001);
vector<vector<char>> stairs;

void btet(crd stp,int h);
void ptet(crd stp,int h);
void qtet(crd stp,int h);
void dtet(crd stp,int h);
int n;
int main(){
    cin >> n;
    stairs.resize(n+1,vector<char>(n+1,0));
    int twopow=4,h=2;
    possible[h]=true;
    while(h<=n){
        h+=twopow;
        possible[h]=true;
        possible[h+twopow/2]=true;
    }
    if(possible[n]) ;
    else printf("impossible");
    return 0;
}
void btet(crd stp,int h){
    if(h==2){
        stairs[stp.y][stp.x]='b';
        stairs[stp.y-1][stp.x]=VER;
        stairs[stp.y][stp.x+1]=HOR;
    }
    else{
        btet(stp,h/2);
        btet({stp.y-1,stp.x+1},h/2);
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
        ptet({stp.y+1,stp.x+1},h/2);
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
        qtet({stp.y+1,stp.x-1},h/2);
        ptet({stp.y,stp.x-h+1},h/2);
        dtet({stp.y+h-1,stp.x},h/2);
    }
}
void dtet(crd stp,int h){
    if(h==2){
        stairs[stp.y][stp.x]='b';
        stairs[stp.y-1][stp.x]=VER;
        stairs[stp.y][stp.x+1]=HOR;
    }
    else{
        dtet(stp,h/2);
        dtet({stp.y-1,stp.x-1},h/2);
        btet({stp.y,stp.x-h+1},h/2);
        qtet({stp.y-h+1,stp.x},h/2);
    }
}