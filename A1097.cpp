#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Node{
    int addr,key,next;
}node[100000];
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("G:\\C++\\PATAgain\\test.txt","r",stdin);
    #endif // ONLINE_JUDGE
    int s,n;
//    map<int,int> m;
    /** \brief
     *能用数组坚决不用map，慢死了
     *
     */

    bool exist[100000];
    cin>>s>>n;
    vector<Node> v(n),r(n);
    fill(exist,exist+100000,false);
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        node[temp].addr=temp;
        cin>>node[temp].key>>node[temp].next;
    }
    int p=s,t1=0,t2=0;
    while(p!=-1){
        int temp=abs(node[p].key);
       if(exist[temp]!=true){
            v[t1++]=node[p];
            exist[temp]=true;
       }else{
           r[t2++]=node[p];
       }
        p=node[p].next;
    }
    /** \brief
     *
     * 不要忘记判断为null的情况
     */

    if(t1>0){
        for(int i=0;i<t1-1;i++){
            printf("%05d %d %05d\n",v[i].addr,v[i].key,v[i+1].addr);
        }
        printf("%05d %d %d\n",v[t1-1].addr,v[t1-1].key,-1);
    }
    if(t2>0){
        for(int i=0;i<t2-1;i++){
        printf("%05d %d %05d\n",r[i].addr,r[i].key,r[i+1].addr);
        }
        printf("%05d %d %d\n",r[t2-1].addr,r[t2-1].key,-1);
    }
    return 0;
}
