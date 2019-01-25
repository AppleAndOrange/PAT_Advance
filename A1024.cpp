#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
struct data{
    int c[1000]={0};
    int len=0;
};
bool IsPalindromic(data a){
    for(int i=0;i<=a.len/2;i++){
        if(a.c[i]!=a.c[a.len-1-i]){
            return false;
        }
    }
    return true;
}
data change(char a[],int len){
    data t;
    t.len=len;
    for(int i=0;i<len;i++){
        t.c[i]=a[t.len-i-1]-'0';
    }
    return t;
}
data add(data a,data b){
    data t;
    int carry=0;
    for(int i=0;i<a.len||i<b.len;i++){
        int temp=a.c[i]+b.c[i]+carry;
        t.c[t.len++]=temp%10;
        carry=temp/10;
    }
    if(carry!=0){
        t.c[t.len++]=carry;
    }
    return t;
}
void print(data a){
    for(int i=0;i<a.len;i++){
        printf("%d",a.c[a.len-i-1]);
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("G:\\C++\\PATAgain\\test.txt","r",stdin);
    #endif // ONLINE_JUDGE
    char c[12];
    int k,i;
    scanf("%s %d",c,&k);
    data t=change(c,strlen(c));
    for(i=0;i<k&&!IsPalindromic(t);i++){
        data temp=t;
        reverse(temp.c,temp.c+temp.len);
        t=add(temp,t);
    }
    print(t);
    printf("\n%d\n",i);
    return 0;
}
