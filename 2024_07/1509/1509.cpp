#include <iostream>
#include <vector>
#include <string>
#define LENMAX 2500
using namespace std;
string str;
vector<vector<int>> cache;
int dp(int left,int right){
    if(cache[left][right]!=LENMAX)
        return cache[left][right];
    
    if(left==right)// 길이1인 문자열 -> 팰린드롬
        return cache[left][right]=1;
    if(str[left]==str[right]){// 양쪽 끝 비교해서 같은 문자라면
        if(left+1==right)// 길이2인 문자열 -> 팰린드롬
            return cache[left][right]=1;
        else if(dp(left+1,right-1)==1)// 양쪽 끝 문자 없애도 팰린드롬이라면 팰린드롬
            return cache[left][right]=1;
    }
    for(int i=left;i<right;i++)
        cache[left][right]=min(cache[left][right],dp(left,i)+dp(i+1,right));
    return cache[left][right];
}
int main(){
    cin>>str;
    cache.resize(str.length()+1,vector<int>(str.length()+1,LENMAX));
    
    cout<<dp(0,str.length()-1);






    FILE *fp=fopen("output.txt","w");
    for(int i=0;i<str.length();i++){
        for(int j=0;j<str.length();j++){
            fprintf(fp,"%8d(%4d,%4d)",cache[i][j],i,j);
        }
        fprintf(fp,"\n");
    }
    fclose(fp);

    return 0;
}