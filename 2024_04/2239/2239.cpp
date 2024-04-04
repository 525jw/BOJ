#include <iostream>
using namespace std;

int map[9][9];
int list[81][2];//([0]=y,[1]=x), saving (y,x)index of blankspace
int blanknum;//total number of blankspace

void rowchk(int row,bool unv[]){
    int i;
    for(i=0;i<9;i++){
        unv[map[row][i]]=1;
    }
}
void culchk(int cul,bool unv[]){
    int i;
    for(i=0;i<9;i++){
        unv[map[i][cul]]=1;
    }
}
void sqr(int srow,int scul,bool unv[]){
    int i,j;
    for(i=srow;i<srow+3;i++){
        for(j=scul;j<scul+3;j++){
            unv[map[i][j]]=1;
        }
    }
}
void sqrchk(int row,int cul,bool unv[]){
    if(row<3){
        if(cul<3) sqr(0,0,unv);
        else if(cul<6) sqr(0,3,unv);
        else sqr(0,6,unv);
    }
    else if(row<6){
        if(cul<3) sqr(3,0,unv);
        else if(cul<6) sqr(3,3,unv);
        else sqr(3,6,unv);
    }
    else{
        if(cul<3) sqr(6,0,unv);
        else if(cul<6) sqr(6,3,unv);
        else sqr(6,6,unv);
    }

}
void btk(int nowtrack){//=index
    if(nowtrack>=blanknum){
    	for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				cout << map[i][j];
			}
		cout << "\n";
		}
		exit(0);
    }
    
    bool unv[10]={0};//un-usable value
    int i;
    int row=list[nowtrack][0];
    int cul=list[nowtrack][1];
    for(i=1;i<=9;i++){
        rowchk(row,unv);
        culchk(cul,unv);
        sqrchk(row,cul,unv);
    }

    for(i=1;i<=9;i++){
        if(!unv[i]){
            map[row][cul]=i;
            btk(nowtrack+1); 
			map[row][cul]=0;
        }
    }
}


int main(){
    int i,j;
    char inp;
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            cin >> inp;
            map[i][j]=inp-'0';
            if(!map[i][j]){
                list[blanknum][0]=i;
                list[blanknum++][1]=j;
            }
       }
    }
    btk(0);
    return 0;
}