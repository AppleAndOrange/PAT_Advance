#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("G:\\C++\\PATAgain\\test.txt","r",stdin);
    #endif // ONLINE_JUDGE
    int n,m;
    string id;
    string info[6];
    map<string,set<string>> mp;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>id;
        getchar();
        getline(cin,info[1]);
        mp[info[1]].insert(id);
        getline(cin,info[2]);
        mp[info[2]].insert(id);
        while(cin>>info[3]){
            mp[info[3]].insert(id);
            if(getchar()=='\n'){
                break;
            }
        }
        getline(cin,info[4]);
        mp[info[4]].insert(id);
        getline(cin,info[5]);
        mp[info[5]].insert(id);
    }
    cin>>m;
    getchar();
    for(int i=1;i<=m;i++){
        string str;
        getline(cin,str);
        cout<<str<<endl;
        str=str.substr(3,str.length()-1);
        if(mp[str].size()==0){
           cout<<"Not Found"<<endl;
        }else{
            set<string> s=mp[str];
            for(set<string>::iterator it=s.begin();it!=s.end();it++){
                cout<<*it<<endl;
            }
        }
    }
    return 0;
}
