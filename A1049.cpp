#include <iostream>

using namespace std;

int GetCount(int n,int left,int right,int p){
    if(n==0){
        return left*p;
    }else if(n==1){
        return left*p+right+1;
    }else{
        return (left+1)*p;
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("G:\\C++\\PATAgain\\test.txt","r",stdin);
    #endif // ONLINE_JUDGE
    int num,left,right,p=1,n;
    int ans=0;
    cin>>num;
    while(num/p!=0){
        left=num/(p*10);
        n=num/p%10;
        right=num%p;
        ans+=GetCount(n,left,right,p);
        p=p*10;
    }
    cout<<ans;
    return 0;
}
