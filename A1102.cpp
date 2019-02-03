#include <iostream>
#include <queue>
using namespace std;
struct Node{
    int data;
    int lchild,rchild;
}node[11];
int index=0,n,table[11]={0};
void levelOrder(int root){
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int temp=q.front();
        q.pop();
        cout<<temp;
        index++;
        if(index<n){
            cout<<" ";
        }
        if(node[temp].rchild!=-1){
            q.push(node[temp].rchild);
        }
        if(node[temp].lchild!=-1){
            q.push(node[temp].lchild);
        }
    }
}
void inOrder(int root){
    if(root==-1){
        return;
    }
    inOrder(node[root].rchild);
    cout<<node[root].data;
    index++;
    if(index<n){
        cout<<" ";
    }
    inOrder(node[root].lchild);
}
int getRoot(){
    for(int i=0;i<n;i++){
        if(table[i]!=1){
            return i;
        }
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("G:\\C++\\PATAgain\\test.txt","r",stdin);
    #endif // ONLINE_JUDGE
    cin>>n;
    int root;
    for(int i=0;i<n;i++){
        char t1,t2;
        node[i].data=i;
        cin>>t1>>t2;
        if(t1=='-'){
            node[i].lchild=-1;
        }else{
            table[t1-'0']=1;
            node[i].lchild=t1-'0';
        }
        if(t2=='-'){
            node[i].rchild=-1;
        }else{
            table[t2-'0']=1;
            node[i].rchild=t2-'0';
        }
    }
    root=getRoot();
    levelOrder(root);
    cout<<endl;
    index=0;
    inOrder(root);
    return 0;
}
