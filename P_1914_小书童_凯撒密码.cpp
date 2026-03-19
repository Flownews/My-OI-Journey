#include <bits/stdc++.h>
using namespace std;

int main() {
    string a;
    int n;
    cin>>n;
    cin>>a;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]+n>'z') a[i]-=26;
        a[i]+=n;
        if(a[i]>'z') a[i]-=26;
        if(a[i]>'z') a[i]-=26;
    }
    cout<<a;
    return 0;
}