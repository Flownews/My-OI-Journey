#include <bits/stdc++.h>
using namespace std;
int main()
{
    int q=20000,h,r;
    cin>>h>>r;
    double n=3.14*h*r*r;
    int ans=q/n+1;
    cout<<ans;
    return 0;
}