/*
Author: TangLi
Time: 17/9/25
Problem: K - Six Sides Gym - 101291K
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

int a[6],b[6];

int main()
{
    for(int i=0;i<6;i++)
        cin>>a[i];
    for(int i=0;i<6;i++)
        cin>>b[i];

    int A=0,tie=0;
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<6;j++)
        {
            if(a[i]==b[j])
                tie++;
            else if(a[i]>b[j])
                A++;
        }
    }
    printf("%.5f\n",1.0*A/(36-tie));
    return 0;
}
