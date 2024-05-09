#include <iostream>
#include <string>
#include <cstring>
#include <map>
using namespace std;
int romeToArab(string inp){
    //- Normal case
    static map<string,int> romeNumber={
        {"I", 1},
        {"V", 5},
        {"X", 10},
        {"L", 50},
        {"C", 100},
        {"D", 500},
        {"M", 1000}
    };
    //- Small number before large number case
    static map<string,int> romeNumberException={
        {"IV", 4}, 
        {"IX", 9}, 
        {"XL", 40}, 
        {"XC", 90}, 
        {"CD", 400}, 
        {"CM", 900}
    };
    int ret=0;
    while(inp.size()){
        //The first two chars are in romeNumberException
        if(romeNumberException.find(inp.substr(0,2)) != romeNumberException.end()){
            ret+=romeNumberException[inp.substr(0,2)];
            inp.erase(0,2);
        }else{ // The first char are in romeNumber
            ret+=romeNumber[inp.substr(0,1)];
            inp.erase(0,1);
        }
    }
    return ret;
}
string arabToRome(int inp){
    //- Normal case
    static map<int,string,greater<int>> romeNumber={
        {1, "I"},
        {5, "V"},
        {10,"X"},
        {50,"L"},
        {100,"C"},
        {500,"D"},
        {1000,"M"}
    };
    //- Small number before large number case
    static map<int,string,greater<int>> romeNumberException={
        {4,"IV"}, 
        {9,"IX"}, 
        {40,"XL"}, 
        {90,"XC"}, 
        {400,"CD"}, 
        {900,"CM"}
    };
    string ret="";
    while(inp){
        cout<<endl<<inp;
        for(auto iter=romeNumber.begin();iter!=romeNumber.end();iter++){
            if(inp%iter->first>=0){
                inp/=iter->first;
                ret.append(iter->second);
                break;
            }
        }
        for(auto iter=romeNumberException.begin();iter!=romeNumberException.end();iter++){
            if(inp%iter->first>=0){
                inp/=iter->first;
                ret.append(iter->second);
                break;
            }
        }
    }
    return ret;
}
int main(){
    string inp1,inp2;
    cin>>inp1>>inp2;
    int otp1=romeToArab(inp1),otp2=romeToArab(inp2);
    cout<<otp1+otp2;
    string otp3=arabToRome(otp1+otp2);
    cout<<endl<<otp3;
    return 0;
}