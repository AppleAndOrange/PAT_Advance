#include <iostream>
#include <set>
#include <stdio.h>
using namespace std;
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("G:\\C++\\PATAgain\\test.txt","r",stdin);
    #endif // ONLINE_JUDGE
    int n;
    int inf=999999999;
    scanf("%d",&n);
    int arr[n],leftMax[n],rightMin[n];
    leftMax[0]=0;
    rightMin[n-1]=inf;
    int mmin=inf,mmax=0;
    set<int> s;
    for(int i=0;i<n;i++){
        int temp;
        scanf("%d",&temp);
        arr[i]=temp;
    }
    for(int i=1;i<n;i++){
        if(arr[i-1]>mmax){
            mmax=arr[i-1];
        }
        leftMax[i]=mmax;
    }
    for(int i=n-2;i>=0;i--){
        if(arr[i+1]<mmin){
            mmin=arr[i+1];
        }
        rightMin[i]=mmin;
    }
    for(int i=0;i<n;i++){
        if(arr[i]>leftMax[i]&&arr[i]<rightMin[i]){
            s.insert(arr[i]);
        }
    }
    printf("%d\n",s.size());
    for(set<int>::iterator it=s.begin();it!=s.end();it++){
        if(it!=s.begin()){
            printf(" ");
        }
        printf("%d",*it);
    }
    /*在没有数据满足的情况下也要输出换行*/
    if(s.size()==0){
        cout<<endl;
    }
    return 0;
}
