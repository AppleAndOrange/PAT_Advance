#include <iostream>
#include <queue>
using namespace std;

int in[31],post[31];
int n;
struct Node{
    int data;
    Node *lchild,*rchild;
};

Node* build(int postL,int postR,int inL,int inR){
    if(postL>postR){
        return nullptr;
    }
    Node *node=new Node();
    node->data=post[postR];
    int pos;
    for(int i=inL;i<=inR;i++){
        if(in[i]==post[postR]){
            pos=i;
            break;
        }
    }
    int numLeft=pos-inL;
    node->lchild=build(postL,postL+numLeft-1,inL,pos-1);
    node->rchild=build(postL+numLeft,postR-1,pos+1,inR);
    return node;
}
void preOrder(Node *root){
    if(root==nullptr){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->lchild);
    preOrder(root->rchild);
}

void levelOrder(Node *root){
    queue<Node*> q;
    int cnt=1;
    q.push(root);
    while(!q.empty()){
        Node *temp=q.front();
        q.pop();
        cout<<temp->data;
        if(cnt<n){
            cout<<" ";
        }
        cnt++;
        if(temp->lchild!=nullptr){
            q.push(temp->lchild);
        }
        if(temp->rchild!=nullptr){
            q.push(temp->rchild);
        }
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("G:\\C++\\PATAgain\\test.txt","r",stdin);
    #endif // ONLINE_JUDGE

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>post[i];
    }
    for(int i=0;i<n;i++){
        cin>>in[i];
    }
    Node *root=build(0,n-1,0,n-1);
    levelOrder(root);
    //preOrder(root);
    return 0;
}
