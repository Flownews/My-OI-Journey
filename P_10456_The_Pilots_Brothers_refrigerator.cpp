/*
#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[10][10],i,j,c[10][10],d[20],flag=0,k,p=0;
    char b;
    for(i=1;i<=4;i++)
    {
        for(j=1;j<=5;j++)
        {
            b=getchar();
            if(b=='-') a[i][j]=0;
            else if(b=='+') a[i][j]=1;
            c[i][j]=a[i][j];
        }
    }
    for(i=1;i<=16;i++) d[i]=0;
    int h,l;
    while(p<65536)
    {
        flag=0;
        p++;
        for(k=1;k<=16;k++)
        {
            if(d[k]==1)
            {
                h=(k-1)/4+1;
                l = (k - 1) % 4 + 1;
                for(i=1;i<=4;i++)
                {
                    for(j=1;j<=4;j++)
                    {
                        if(i==h || j==l)
                        {
                            if(c[i][j]==1) c[i][j]=0;
                            else c[i][j]=1;
                        }
                    }
                }
            }
        }
        for(i=1;i<=4;i++)
        {
            for(j=1;j<=4;j++)
            {
                if(c[i][j]==1) flag=1;
            }
        }
        if(flag==0)
        {
            for(i=1;i<=16;i++)
            {
                if(d[i]==1) flag++;
            }
            cout<<flag<<endl;
            for(i=1;i<=16;i++)
            {
                if(d[i]==1)
                {
                    cout<<(i-1)/4+1<<" "<<(i-1)%4+1<<endl;
                    //cout<<i<<" ";
                }
            }
            return 0;
        }
        for(i=1;i<=4;i++)
        {
            for(j=1;j<=4;j++)
            {
                c[i][j]=a[i][j];
            }
        }
        d[1]+=1;
        for(k=1;k<=16;k++)
        {
            if(d[k]==2)
            {
                d[k]=0;
                d[k+1]+=1;
            }     
        }
    }
    return 0;
}*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[5][5], c[5][5], d[20] = {0}, p = 0;
    char b;

    // 1. 读取输入 (修正 getchar 可能读入换行符的问题)
    for(int i=1; i<=4; i++) {
        for(int j=1; j<=4; j++) {
            cin >> b;
            if(b == '-') a[i][j] = 0;
            else a[i][j] = 1;
            c[i][j] = a[i][j];
        }
    }

    while(p < 65536) {
        // 2. 每次尝试前重置数组 c
        for(int i=1; i<=4; i++)
            for(int j=1; j<=4; j++) c[i][j] = a[i][j];

        // 3. 执行点按操作
        for(int k=1; k<=16; k++) {
            if(d[k] == 1) {
                int h = (k-1)/4 + 1;
                int l = (k-1)%4 + 1;
                // 翻转行
                for(int x=1; x<=4; x++) c[h][x] = !c[h][x];
                // 翻转列
                for(int x=1; x<=4; x++) c[x][l] = !c[x][l];
                // 关键：中心点被翻转了两次，现在是原始状态，必须再反转一次！
                c[h][l] = !c[h][l];
            }
        }

        // 4. 检查是否全部达成 '-' (即全为 0)
        bool success = true;
        for(int i=1; i<=4; i++) {
            for(int j=1; j<=4; j++) {
                if(c[i][j] == 1) { success = false; break; }
            }
        }

        if(success) {
            int steps = 0;
            for(int i=1; i<=16; i++) if(d[i] == 1) steps++;
            cout << steps << endl;
            for(int i=1; i<=16; i++) {
                if(d[i] == 1) cout << (i-1)/4 + 1 << " " << (i-1)%4 + 1 << endl;
            }
            return 0;
        }

        // 5. 二进制自增 (模拟所有组合)
        p++;
        d[1]++;
        for(int k=1; k<=16; k++) {
            if(d[k] == 2) {
                d[k] = 0;
                d[k+1]++;
            } else break;
        }
    }
    return 0;
}