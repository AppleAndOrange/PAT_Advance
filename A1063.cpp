#include <iostream>
#include <set>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("G:\\C++\\PATAgain\\test.txt","r",stdin);
    #endif // ONLINE_JUDGE
    int n,m,k;
    set<int> s[51];
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>m;
        for(int j=0;j<m;j++){
            int temp;
            cin>>temp;
            s[i].insert(temp);
        }
    }
    cin>>k;
    for(int i=0;i<k;i++){
        double same=0,total=0;
        int t1,t2;
        int temp;
        cin>>t1>>t2;
        total=s[t1].size();
        for(set<int>::iterator it=s[t2].begin();it!=s[t2].end();it++){
            temp=*it;
            if(s[t1].find(*it)!=s[t1].end()){
                same++;
            }else{
                total++;
            }
        }
        printf("%.1f%\n",same*100/total);
    }
    return 0;
}
