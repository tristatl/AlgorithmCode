/*
Author: TangLi
Time: 17/9/25
Problem: F - Equality
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

char s[10];
int main()
{
    gets(s);
    int a=s[0]-'0',b=s[4]-'0',c=s[8]-'0';
    if(a+b==c)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}
