/*
name: tangli
time: 2017/10/13
problem: Max Mex
https://www.codechef.com/OCT17/problems/MEX
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

const int N = 200000+5;
int flag[N];

int main()
{
    int T;
    scanf("%d",&T);

    while(T--)
    {
        memset(flag,0,sizeof(flag));

        int n,k;
        scanf("%d%d",&n,&k);

        int num;
        for(int i = 0; i < n; i++)
        {
             scanf("%d",&num);
             if(!flag[num])
                flag[num] = 1;
        }

        int ans = 0;
        for(int i = 0; i <= N; i++)
        {
            if(!flag[i])
            {
                if(k > 0) k--;
                else {ans = i; break;}
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
