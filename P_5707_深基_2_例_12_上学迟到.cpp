#include <bits/stdc++.h>
using namespace std;
int main() 
{
    int s,v;
    cin>>s>>v;
    int t=s/v;
    if(s%v!=0) t+=1;
    int ans=470-t;
    if(ans>=0)
    {
        if(ans%60>=10) cout<<"0"<<ans/60<<":"<<ans%60;
        else cout<<"0"<<ans/60<<":0"<<ans%60;
    }
    else
    {
        ans+=24*60;
        if(ans/60>=10)
        {
            if(ans%60>=10) cout<<ans/60<<":"<<ans%60;
            else cout<<ans/60<<":0"<<ans%60;
        }
        else
        {
            if(ans%60>=10) cout<<"0"<<ans/60<<":"<<ans%60;
            else cout<<"0"<<ans/60<<":0"<<ans%60;
        }
    }
    return 0;
}