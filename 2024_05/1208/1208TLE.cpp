#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int n,W;
//- indicates whether the ith element is included
vector<bool> include;
vector<int> w;
vector<int> il,ir;
int mid;
int cnt;
void sum_of_subsets(int i,int weight,bool left){
    if(i<(left?mid-1:n)){
        include[i+1]=true;
        sum_of_subsets(i+1,weight+w[i+1],left);
        include[i+1]=false;
        sum_of_subsets(i+1,weight,left);
    }else{
        // for(int i=1;i<=(left?mid-1:n);i++)
        //     cout<<include[i]<<' ';
        // cout<<endl;
        int newdata=0;
        bool emptyset=true;
        for(int i=1;i<=(left?mid-1:n);i++)
            if(include[i]){
                emptyset=false;
                newdata+=w[i];
            }
        left?il.push_back(newdata):ir.push_back(newdata);
        if(weight==W && !emptyset) cnt++;
    }
}
void merge(){
    // for(int i=0;i<il.size();i++)
    //     cout<<il[i]<<' ';
    // cout<<endl;
    // for(int i=0;i<ir.size();i++)
    //     cout<<ir[i]<<' ';
    //cout<<endl;
    for(int i=0;i<il.size()-1;i++)
        for(int j=0;j<ir.size()-1;j++)
            if(il[i]+ir[j]==W)
                cnt++;
}
int main(){
    cin>>n>>W;
    mid=n/2+1;
    include.resize(n+1,false);
    w.resize(n+1,0);
    int total=0;
    for(int i=1;i<=n;i++)
        cin>>w[i];

    sort(w.begin()+1,w.end());
    sum_of_subsets(0,0,true);
    sum_of_subsets(n/2,0,false);
    
    merge();
    cout<<cnt;

    return 0;
}