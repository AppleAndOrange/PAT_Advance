#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("G:\\C++\\PATAgain\\test.txt","r",stdin);
    #endif // ONLINE_JUDGE
    string s,temp,res;
    int mmax=0;
    char c;
    map<string,int> m;
    getline(cin,s);
    for(int i=0;i<s.length();i++){
        c=s[i];
        if(isalnum(s[i])){
            s[i]=tolower(s[i]);
            temp+=s[i];
        }
        if(!isalnum(s[i])||i==s.length()-1){
            /**
            ��temp Ϊ�յ�����£�����ʹm->second++����Ϊʹ����Ҳ���ԣ�����Ҫ����ĸ������
            */
            if(temp.length()!=0){
                m[temp]++;
            }
            temp="";
        }
    }
    for(auto it=m.begin();it!=m.end();it++){
        if(it->second>mmax){
            res=it->first;
            mmax=it->second;
        }
//    cout<<it->fi6rst<<" "<<it->second<<endl;
    }
    cout<<res<<" "<<mmax;
    return 0;
}
