#include <iostream>
#include <vector>
#define MODNUM 1000
using namespace std;
long long n,b;
typedef struct vector<vector<long long>> matrix;
vector<matrix> cache;
matrix matmult(matrix matA,matrix matB){
    long long i,j,k; matrix ret(n,vector<long long>(n,0));
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            for(k=0;k<n;k++)
                ret[i][j]+=(matA[i][k]*matB[k][j])%MODNUM;
            ret[i][j]%=MODNUM;
        }
    }
    return ret;
}
matrix matpow(matrix mat,long long pow){
    if(pow==1) return mat;
    else {
        matrix halfpow=matpow(mat,pow/2);    
        if(pow%2==0) return matmult(halfpow,halfpow);
        else return matmult(mat,matmult(halfpow,halfpow));
    }
}
matrix matadd(matrix matA,matrix matB){
    int i,j;
    matrix ret(n,vector<long long>(n,0));
    for(i=0;i<n;i++) for(j=0;j<n;j++) ret[i][j]=(matA[i][j]+matB[i][j])%MODNUM;
    return ret;
}
matrix solve(matrix mat, long long pow){
    if(pow==1) return mat;
    else{
        matrix partition=solve(mat,pow/2);
        matrix halfpow=matpow(mat,pow/2);
        return (pow%2) ? matadd( matadd(partition, matmult(partition,halfpow) ) ,matmult(mat,matmult(halfpow,halfpow))) : matadd(partition, matmult(partition,halfpow) );
    }
}
int main(){
    cin >> n >> b;
    matrix mat(n,vector<long long> (n)); 
    int i,j;

    for(i=0;i<n;i++) for(j=0;j<n;j++) cin>>mat[i][j];
    
    mat=solve(mat,b);

    for(i=0;i<n;i++) {
        for(j=0;j<n-1;j++) cout << mat[i][j]%MODNUM << ' ';
        cout<<mat[i][j]%MODNUM<<endl;
    }

    return 0;
}