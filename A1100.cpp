#include <iostream>
#include <cmath>
#include <cctype>
#include <map>
#include <string>
using namespace std;
map<string,int> m;
string toStr[26];
void StringToInt(string str,int n){
    m[str]=n;
}
void IntToString(string str,int n){
    toStr[n]=str;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("G:\\C++\\PATAgain\\test.txt","r",stdin);
    #endif // ONLINE_JUDGE
    //string str0="tret";
    string str1[13]={"tret","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
    string str2[13]={"tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
    int n;
    cin>>n;
    string str;
    for(int i=0;i<13;i++){
        StringToInt(str1[i],i*13);
        StringToInt(str2[i],i);
        IntToString(str1[i],i+13);
        IntToString(str2[i],i);
    }
    getchar();
    for(int i=0;i<n;i++){
        getline(cin,str);
        if(isdigit(str[0])){
            int temp=stoi(str);
            int n1=temp/13,n2=temp%13;
            if(n1!=0){
                cout<<toStr[n1+13];
                if(n2!=0){
                    cout<<" ";
                    cout<<toStr[n2]<<endl;
                }else{
                    cout<<endl;
                }
            }else{
                cout<<toStr[n2]<<endl;
            }
        }
        if(isalpha(str[0])){
            if(str.length()>3){
                cout<<m[str.substr(0,3)]+m[str.substr(4,7)]<<endl;
            }else{
                cout<<m[str]<<endl;
            }
        }
    }
    return 0;
}
