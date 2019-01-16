#include <iostream>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("G:\\C++\\PATAgain\\test.txt","r",stdin);
    #endif // ONLINE_JUDGE
    int n;
    cin>>n;
    double temp,sum=0;
    for(int i=0;i<n;i++){
        cin>>temp;
        sum+=temp*(i+1)*(n-i);
    }
    printf("%.2f\n",sum);
    return 0;
}
