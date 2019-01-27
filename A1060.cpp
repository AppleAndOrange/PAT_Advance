#include <iostream>
#include <string.h>
using namespace std;
int n;
string GetNumber(string str,int &p){
    int temp=0,i=0;
    while(str.length()>1&&str[0]=='0'){
        str.erase(str.begin());
    }
    if(str[0]=='.'){
        str.erase(str.begin());
        while(str.length()>1&&str[0]=='0'){
            str.erase(str.begin());
            temp--;
        }
        p=temp;
    }else if(str[0]!='0'){
        while(str.length()>temp&&str[i]!='.'){
            temp++;
            i++;
        }
        if(temp<str.length()){
            str.erase(str.begin()+i);
        }
        p=temp;
    }
    if(str[0]=='0'){
        p=0;
    }
    int num=0;
    string res;
    while(num<n){
        if(num<str.length()){
            res+=str[num];
        }else{
            res+='0';
        }
        num++;
    }
    return res;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("G:\\C++\\PATAgain\\test.txt","r",stdin);
    #endif // ONLINE_JUDGE
    int p1=0,p2=0;
    cin>>n;
    string str1,str2;
    cin>>str1>>str2;
    str1=GetNumber(str1,p1);
    str2=GetNumber(str2,p2);
    if(str1==str2&&p1==p2){
        cout<<"YES 0."<<str1<<"*10^"<<p1<<endl;
    }else{
        cout<<"NO 0."<<str1<<"*10^"<<p1<<" 0."<<str2<<"*10^"<<p2<<endl;
    }
    return 0;
}
