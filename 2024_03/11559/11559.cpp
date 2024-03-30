#include <iostream>
using namespace std;

int chain;
char map[12][7];
static int bx[4]={0,1,0,-1};
static int by[4]={-1,0,1,0};

int bfs(int visited[][6],int vidx,int y,int x,int* alreadychain){
    int que[100][2]={0};// ([0]=y,[1]=x) 큐
    int front=0,rear=0,i,j;

    que[rear][0]=y;
    que[rear++][1]=x;
    
    /*
    printf("\n\n");
    for(i=0;i<12;i++){
    	for(j=0;j<6;j++){
    		printf("%d ",visited[i][j]);
		}
		printf("\n");
	}
	*/

    while(front<rear){
        visited[que[front][0]][que[front][1]]=vidx;

        for(i=0;i<4;i++){
            int ny=que[front][0]+by[i];
            int nx=que[front][1]+bx[i];

            if(ny<0 || ny>=12) continue;
            if(nx<0 || nx>=6) continue;
            if(!visited[ny][nx] && map[ny][nx]==map[que[front][0]][que[front][1]]){
                que[rear][0]=ny;
                que[rear++][1]=nx;
            }
        }
        front++;
    }

    int cnt=0;
    for(i=0;i<12;i++){
        for(j=0;j<6;j++){
            if(visited[i][j]==vidx) cnt++;
            if(cnt>=4) break;
        }
    }
    
    if(cnt>=4){
        for(i=0;i<12;i++){
            for(j=0;j<6;j++){
                if(visited[i][j]==vidx) map[i][j]='X';
            }
        }
        if(*alreadychain) return 0;
        else{
        	*alreadychain=1;
        	return 1;
		}
    }
    else return 0;
}

int main(){
    int i,j,k,res=0;

    for(i=0;i<12;i++)
        for(j=0;j<6;j++)
            scanf(" %c",&map[i][j]);
    
    while(1){
    	/*
		printf("\n\n");
    	for(i=0;i<12;i++){
    		for(j=0;j<6;j++){
    			printf("%c",map[i][j]);
			}
			printf("\n");
		}
		*/
        int visited[12][6]={0};
        int vidx=0;
        int alreadychain=0;
        //터뜨리기 
        for(i=11;i>=0;i--){
            for(j=5;j>=0;j--){
                if(map[i][j]=='.') continue;
                else if(!visited[i][j]) res+=bfs(visited,++vidx,i,j,&alreadychain);
            }
        }
        //떨어지기, 아무것도 떨어지지 않았다면 while 종료
        int endchk=0;
        for(i=11;i>=0;i--){
            for(j=5;j>=0;j--){
                if(map[i][j]=='.') continue;
                if(map[i][j]=='X'){
                    endchk=1;
                    while(map[i][j]=='X'){
                    	for(k=i;k>0;k--){
                        	map[k][j]=map[k-1][j];
                        	map[k-1][j]='.';
                		}
					}
                }
            }
        }
        
        //printf("%d",res);
        if(!endchk) break;
    }

    printf("%d",res);
    return 0;
}