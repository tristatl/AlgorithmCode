/*
name : tangli
time : 2017/10/20
problem : codechef 2017 Oct challenge Counter Test For CHEFSUM
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

#define ll long long

const ll MAX = 1LL<<32 ;

int main()
{

    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        ll b = MAX / (n+1);
        ll na = MAX % (n+1) - 1;
        ll nb = n - na;
        ll a = b + 1;
        //cout << MAX << endl;
        //cout << b << endl;

        printf("%d",a);
        for(int i = 0; i < na-1; i++)
            cout << " " << a;
        for(int i = 0; i < nb; i++)
            cout << " " << b;
        cout << endl;

    }
    return 0;
}
