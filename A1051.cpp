#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("G:\\C++\\PATAgain\\test.txt","r",stdin);
    #endif // ONLINE_JUDGE
    int m,n,k;
    bool flag;
    cin>>m>>n>>k;
    vector<int> v(n+1);
    for(int i=0;i<k;i++){
        stack<int> s;
        flag=true;
        int temp,t=1;
        for(int j=1;j<=n;j++){
           cin>>temp;
            v[j]=temp;
        }
        for(int j=1;j<=n;j++){
            s.push(j);
            if(s.size()>m){
                flag==false;
                break;
            }
            while(!s.empty()&&s.top()==v[t]){
                s.pop();
                t++;
            }
        }
        cout<<s.size()<<endl;
        if(flag==true&&s.empty()){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
