/*
Author: TangLi
Time: 17/9/25
Problem: A - Alphabet
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;
int dp[100];

int main()
{
    string s;
    cin>>s;
    int len=s.length();
    for(int i=0;i<len;i++)
    {
        dp[i]=1;
        for(int j=0;j<i;j++)
        {
            if(s[i]>s[j] && dp[i]<dp[j]+1)
                dp[i]=dp[j]+1;
        }
    }
    int ans=0;
    for(int i=0;i<len;i++)
        ans=max(dp[i],ans);
    cout<<26-ans<<endl;
    return 0;
}
