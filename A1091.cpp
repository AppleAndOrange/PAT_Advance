#include <iostream>
#include <queue>
using namespace std;
struct Node{
    int layer,r,c;
}node;
int row=1290,column=130,maxn=61;
bool in[61][1290][130]={false};
int pixel[61][1290][130];
int m,n,l,t;
int changeZ[6]={0,0,0,0,1,-1};
int changeX[6]={1,-1,0,0,0,0};
int changeY[6]={0,0,1,-1,0,0};

bool judge(int z,int  x,int y){
    if(z<0||z>=l||x<0||x>=m||y<0||y>=n||in[z][x][y]==true||pixel[z][x][y]==0){
        return false;
    }
    return true;
}

int bfs(int z,int x,int y){
    in[z][x][y]=true;
    int cnt=1;
    queue<Node> q;
    node.layer=z;
    node.r=x;
    node.c=y;
    q.push(node);
    while(!q.empty()){
        Node temp=q.front();
        q.pop();
        for(int i=0;i<6;i++){
            int newZ=temp.layer+changeZ[i];
            int newX=temp.r+changeX[i];
            int newY=temp.c+changeY[i];
            if(judge(newZ,newX,newY)){
                cnt++;
                node.layer=newZ;
                node.r=newX;
                node.c=newY;
                q.push(node);
                in[newZ][newX][newY]=true;
            }
        }
    }
    if(cnt>=t){
        return cnt;
    }else{
        return 0;
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("G:\\C++\\PATAgain\\test.txt","r",stdin);
    #endif // ONLINE_JUDGE
    cin>>m>>n>>l>>t;
    int ans=0;
    for(int i=0;i<l;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<n;k++){
                cin>>pixel[i][j][k];
            }
        }
    }
    for(int i=0;i<l;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<n;k++){
                if(pixel[i][j][k]==1&&in[i][j][k]==false){
                    ans+=bfs(i,j,k);
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
