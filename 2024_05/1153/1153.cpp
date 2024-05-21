#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
vector<bool> isPrime;
void eratos(int N){
    isPrime[0]=isPrime[1]=false;
    int i,j,sqrtN=sqrt(N);
    for(i=2;i<=sqrtN;i++)
        if(isPrime[i])
            for(j=i*i;j<=N;j+=i)
                isPrime[j]=false;
}
void partition(int N){
    int left,right;
    left=right=N/2;
    while(1){
        if(left<=1){
            cout<<-1;
            exit(0);
        }
        else if(isPrime[left] && isPrime[right] && left+right==N){
            cout<<left<<' '<<right<<' ';
            break;
        }
        else{
            left--;
            right++;
        }
    }
}
int main(){
    int N;
    cin>>N;
    isPrime.resize(N+1,true);

    eratos(N);
    
    if(N<8)
        cout<<-1;
    else if(N%2==0){
        cout<<"2 2 ";
        N-=4;
        partition(N);
    }else{
        cout<<"2 3 ";
        N-=5;
        partition(N);
    }
    return 0;
}