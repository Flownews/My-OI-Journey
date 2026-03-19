#include <bits/stdc++.h>
using namespace std;
int main() {
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int num=(c-a)*60+d-b;
    cout<<num/60<<" "<<num%60;
    return 0;
}