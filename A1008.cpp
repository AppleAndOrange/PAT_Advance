#include <iostream>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("G:\\C++\\PATAgain\\test.txt","r",stdin);
    #endif // ONLINE_JUDGE
    int mmin=101,mmax=-1;
    int n,temp=0,current=0,total=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>temp;
        if(current>temp){
            total+=(current-temp)*4;
        }else if(current<temp){
            total+=(temp-current)*6;
        }
        current=temp;
    }
    total+=n*5;
    cout<<total<<endl;
    return 0;
}
