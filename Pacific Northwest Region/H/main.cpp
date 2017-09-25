/*
Author: TangLi
Time: 17/9/25
Problem: H - Islands Gym - 101291H
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

char mat[55][55];
int vis[55][55];
int n,m;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

void dfs(int x,int y,int k)
{
    //cout<<x<<" "<<y<<" "<<k<<endl;
    if(x<0||y<0||x>=n||y>=m) return;
    if(mat[x][y]=='W'||vis[x][y]) return;
    vis[x][y]=k;

    for(int i=0;i<4;i++)
        dfs(x+dx[i],y+dy[i],k);
}
int main()
{
    memset(vis,0,sizeof(vis));

    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>mat[i];

    int cnt=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(!vis[i][j]&&mat[i][j]=='L')
                dfs(i,j,++cnt);
        }
    }
    cout<<cnt<<endl;
    return 0;
}
