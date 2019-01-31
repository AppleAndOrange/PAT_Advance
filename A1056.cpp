#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("G:\\C++\\PATAgain\\test.txt","r",stdin);
    #endif // ONLINE_JUDGE
    int p,g;
    int group;
    cin>>p>>g;
    vector<int> v(p);
    queue<int> q;
    map<int,int> m;
    for(int i=0;i<p;i++){
        cin>>v[i];
    }
    for(int i=0;i<p;i++){
        int temp;
        cin>>temp;
        q.push(v[temp]);
    }
    while(q.size()!=1){
        int cnt=q.size();
        int tempG=q.size()/g;
        if(q.size()%g!=0){
            tempG+=1;
        }
        for(int i=0;i<cnt;i+=g){
            int mmax=q.front();
            m[mmax]=tempG+1;
            q.pop();
            for(int j=1;j+i<cnt&&j<g;j++){
                int t=q.front();
                m[t]=tempG+1;
                if(mmax<t){
                    mmax=t;
                }
                q.pop();
            }
            q.push(mmax);
        }
    }
    m[q.front()]=1;
    for(int i=0;i<p;i++){
        if(i!=0){
            cout<<" ";
        }
        cout<<m[v[i]];
    }
    cout<<endl;
    return 0;
}
