#include <iostream>
#include <vector>
#define MODNUM 1000000007
using namespace std;
long long n;
//0, 1, 2, 3, 4, 5, 6,  7,  8,  9, 10, 11,  12,  13,  14,  15,  16,   17
//0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597
vector<vector<long long>> mat_mult(vector<vector<long long>> a,vector<vector<long long>> b){
    int i,j,k,m,row,col;
    row=a.size(),col=b[0].size(),m=a[0].size();
    vector<vector<long long>> ret(row,vector<long long>(col));
    for(i=0;i<row;i++)
        for(j=0;j<col;j++)
            for(k=0;k<m;k++)
                ret[i][j]+=(a[i][k]*b[k][j])%MODNUM;
    return ret;
}
vector<vector<long long>> mat_pow(vector<vector<long long>> mat, long long pow){
    if(pow==1) return mat;
    else{
        vector<vector <long long>> mat_half=mat_pow(mat,pow/2);
        if(pow%2==0) return mat_mult(mat_half,mat_half);
        else return mat_mult(mat,mat_mult(mat_half,mat_half));
    }
}
long long fibo(long long n){
    if(n<2) return n;
    vector<vector<long long>> ret=mat_mult(mat_pow({{1,1},{1,0}},n-1),{{1},{0}});
    return ret[0][0]%MODNUM;
}
int main(){
    cin >> n;
    cout << fibo(n);
    return 0;
}