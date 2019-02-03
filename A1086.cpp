#include <iostream>
#include <string>
#include <stack>
using namespace std;
struct Node{
    int data;
    Node *lchild,*rchild;
};
int n;
stack<int> s;
int pre[30],in[30],inNum=0,preNum=0,cnt=0;

Node *build(int preL,int preR,int inL,int inR){
    if(preL>preR){
        return nullptr;
    }
    Node *root=new Node();
    root->data=pre[preL];
    int k;
    for(int i=inL;i<=inR;i++){
        if(in[i]==pre[preL]){
            k=i;
            break;
        }
    }
    int numLeft=k-inL;
    root->lchild=build(preL+1,preL+numLeft,inL,k-1);
    root->rchild=build(preL+numLeft+1,preR,k+1,inR);
    return root;
}

void postOrder(Node *root){
    if(root==nullptr){
        return;
    }
    postOrder(root->lchild);
    postOrder(root->rchild);
    cout<<root->data;
    cnt++;
    if(cnt<n){
        cout<<" ";
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("G:\\C++\\PATAgain\\test.txt","r",stdin);
    #endif // ONLINE_JUDGE
    cin>>n;
    int cnt=2*n;
    for(int i=0;i<cnt;i++){
        string temp;
        cin>>temp;
        if(temp=="Push"){
            int data;
            cin>>data;
            pre[preNum++]=data;
            s.push(data);
        }else{
            in[inNum++]=s.top();
            s.pop();
        }
    }
    Node *root=build(0,n-1,0,n-1);
    postOrder(root);
    return 0;
}
