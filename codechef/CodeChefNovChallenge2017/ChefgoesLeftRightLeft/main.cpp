/*
name : tangli
time : 2017/11/06
problem : Chef goes Left Right Left
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
typedef long long ll;
#define first fi
#define second se
#define all(x) x.begin(),x.end()
#define inf 0x7fffffff
const int N = 1000000 + 5;

int a[N];

int main()
{
    //cout << inf << endl;
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n, r;
        scanf("%d%d",&n,&r);

        for(int i = 1; i <= n; i++)
            scanf("%d",a+i);

        int mx = inf, mn = -inf;

        bool ok = 1;
        for(int i = 2; i <= n; i++)
        {
            //cout << mx << " " << mn << endl;
            //cout << a[i] << endl;
            if(a[i] > mx){ok = 0;break;}
            if(a[i] < mn){ok = 0;break;}

            if(a[i] > a[i-1]) mn = a[i-1];
            else if(a[i] < a[i-1]) mx = a[i-1];
        }
        if(ok) puts("YES");
        else puts("NO");
    }
    return 0;
}
