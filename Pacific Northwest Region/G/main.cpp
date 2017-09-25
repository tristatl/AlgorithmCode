/*
Author: TangLi
Time: 17/9/25
Problem: G - Gravity Gym - 101291G
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

char mp[55][55];

int main()
{
    int m,n;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>mp[i];
    for(int j=0;j<m;j++)
    {
        for(int i=n-1;i>=0;i--)
        {
            if(mp[i][j]!='o') continue;
            int k;
            for(k=i+1;k<n;k++)
            {
                if(mp[k][j] != '.') break;
            }
            if(i != k-1)
            {
                mp[k-1][j]='o';
                mp[i][j]='.';
            }
        }
    }
    for(int i=0;i<n;i++)
        cout<<mp[i]<<endl;

    return 0;
}
