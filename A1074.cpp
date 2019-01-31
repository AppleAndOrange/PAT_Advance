#include <iostream>
#include <algorithm>
using namespace std;
int maxn=100000;
struct Node{
    int address,data,next;
    int order;
}node[100000];

bool cmp(Node a,Node b){
    return a.order<b.order;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("G:\\C++\\PATAgain\\test.txt","r",stdin);
    #endif // ONLINE_JUDGE
    int start,n,k;
    cin>>start>>n>>k;
    for(int i=0;i<maxn;i++){
        node[i].order=maxn;
    }
    for(int i=0;i<n;i++){
        int addr,data,next;
        cin>>addr>>data>>next;
        node[addr].address=addr;
        node[addr].data=data;
        node[addr].next=next;
    }
    int p=start,cnt=0;
    while(p!=-1){
        node[p].order=cnt++;
        p=node[p].next;
    }

    sort(node,node+maxn,cmp);
    for(int i=0;i<cnt/k;i++){
        for(int j=(i+1)*k-1;j>i*k;j--){
            printf("%05d %d %05d\n",node[j].address,node[j].data,node[j-1].address);
        }
        printf("%05d %d ",node[i*k].address,node[i*k].data);
        if(i<(cnt/k-1)){
            printf("%05d\n",node[(i+2)*k-1]);
        }else{
            if(cnt%k==0){
                printf("-1\n");
            }else{
                printf("%05d\n",node[(i+1)*k]);
                for(i=cnt/k*k;i<cnt;i++){
                    printf("%05d %d ",node[i].address,node[i].data);
                    if(i<cnt-1){
                        printf("%05d\n",node[i+1].address);
                    }else{
                        printf("-1\n");
                    }
                }
            }
        }
    }
    return 0;
}
