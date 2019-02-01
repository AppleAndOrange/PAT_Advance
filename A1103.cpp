#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<int> temp,arr,fac;
int n,k,p,maxn=-1;

void dfs(int index,int sumK,int sum,int facSum){
    if(sum==n&&sumK==k){
        if(maxn<facSum){
            maxn=facSum;
            arr=temp;
        }
        return;
    }
    if(sumK>k||sum>n||index<1){
        return;
    }
    temp.push_back(index);
    dfs(index,sumK+1,sum+fac[index],facSum+index);
    temp.pop_back();
    dfs(index-1,sumK,sum,facSum);
}
int power(int num,int p){
    int res=1;
    for(int i=0;i<p;i++){
        res*=num;
    }
    return res;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("G:\\C++\\PATAgain\\test.txt","r",stdin);
    #endif // ONLINE_JUDGE
    cin>>n>>k>>p;
    int t=0,t1=0;
    while(t1<n){
        /** \brief
         *�������ֱ����pow()��������
         pow()���ؽ��Ϊ��������ǿ��ת��Ϊ���ͻ������
         *
         */

        t1=power(t,p);
        fac.push_back(t1);
        t++;
    }
    dfs(fac.size()-1,0,0,0);
    if(maxn==-1){
        printf("Impossible\n");
        return 0;
    }
    printf("%d = %d^%d",n,arr[0],p);
    for(int i=1;i<k;i++){
        printf(" + %d^%d",arr[i],p);
    }
    printf("\n");
    return 0;
}
