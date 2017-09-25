/*
Author: TangLi
Time: 17/9/25
Problem: M - Zigzag
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

int a[55];

int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>a[i];

    bool inc=0;
    int ans1=1;
    for(int i=1; i<n; i++)
    {
        if(a[i]>a[i-1]&&!inc)
        {
            inc=1;
            ans1++;
        }
        else if(a[i]<a[i-1]&&inc)
        {
            inc=0;
            ans1++;
        }

    }
    inc=1;
    int ans2=1;
    for(int i=1; i<n; i++)
    {
        if(a[i]>a[i-1]&&!inc)
        {
            inc=1;
            ans2++;
        }
        else if(a[i]<a[i-1]&&inc)
        {
            inc=0;
            ans2++;
        }
    }
    cout<<max(ans1,ans2)<<endl;
    return 0;
}
