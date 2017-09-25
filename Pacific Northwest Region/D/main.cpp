/*
Author£º TangLi
Time: 17/9/25
Problem£ºD - Cameras
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

const int N = 100000;
bool vis[N+5];

int main()
{
   // while(1)
   // {
        memset(vis,0,sizeof(vis));

        int n,k,r,inx;
        cin>>n>>k>>r;
        for(int i=0; i<k; i++)
        {
            cin>>inx;
            vis[inx]=1;
        }
        int sum=0,cnt=0;
        for(int i=1; i<=r; i++)
            if(vis[i]) sum++;
        if(sum==0)
        {
            vis[r]=vis[r-1]=1;
            sum+=2;
            cnt+=2;
        }
        if(sum==1)
        {
            if(vis[r]) vis[r-1]=1;
            else vis[r]=1;
            sum++;
            cnt++;
        }
        for(int i=r+1; i<=n; i++)
        {
            sum+=vis[i];
            sum-=vis[i-r];

            if(sum==0)
            {
                vis[i]=vis[i-1]=1;
                cnt+=2;
                sum+=2;
            }
            if(sum==1)
            {
                if(vis[i]) vis[i-1]=1;
                else vis[i]=1;
                cnt++;
                sum++;
            }
        }
        cout<<cnt<<endl;
   // }
    return 0;
}
