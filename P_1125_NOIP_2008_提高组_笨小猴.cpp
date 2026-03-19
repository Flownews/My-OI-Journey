#include <bits/stdc++.h>
using namespace std;

int main() {
    string a;
    cin>>a;
    int b[26],ma=0,mi=101;
    for(int i=0;i<26;i++) b[i]=0;
    for(int i=0;i<a.size();i++)
    {
        b[a[i]-='a']++;
    }
    for(int i=0;i<26;i++)
    {
        if(b[i]>ma) ma=b[i];
        if(b[i]<mi && b[i]!=0) mi=b[i];
    }
    int n=ma-mi;
    if(n==0 || n==1)
    {
            cout<<"No Answer"<<endl<<0;
            return 0;
    }
    for(int i=2;i<=n;i++)
    {
        if(n%i==0 && n!=i)
        {
            cout<<"No Answer"<<endl<<0;
            return 0;
        }
    }
    cout<<"Lucky Word"<<endl<<n;
    return 0;
}