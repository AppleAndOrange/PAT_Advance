#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(int a,int b){
    return a>b;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("G:\\C++\\PATAgain\\test.txt","r",stdin);
    #endif // ONLINE_JUDGE
    string str;
    int sum;
    cin>>str;
    do{
        while(str.length()<4){
            str.insert(0,"0");
        }
        sort(str.begin(),str.end());
        int a=stoi(str);
        sort(str.begin(),str.end(),cmp);
        int b=stoi(str);
        sum=b-a;
        printf("%04d - %04d = %04d\n",b,a,sum);
        str=to_string(sum);
    }while(sum!=0&&sum!=6174);

    return 0;
}
