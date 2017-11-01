/*
name : tangli
time : 2017/11/1
problem : cf762A k-division
*/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <map>
#include <set>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
typedef long long ll;
const ll mod = 1000000007;

int main()
{
    ll n,k;
    scanf("%lld%lld",&n,&k);
    ll cnt = 0;
    ll ans = 0;
    bool flag = false;
    for(ll i = 1; i*i <= n; i++)
    {
        if(n%i == 0) cnt++;
        if(cnt == k)
        {
            ans = i;
            flag = true;break;
        }
    }
    if(!flag)
    {
        cnt *= 2;
        ll m = floor(sqrt(n) + 0.5);
        if(m*m == n) cnt--;
        ll cnt2 = 0;
        for(ll i = 1; i*i <= n; i++)
        {
            if(n%i == 0)
                cnt2++;
            if(cnt2 == cnt-k+1)
            {
                ans = n/i;
                flag = true;break;
            }
        }
    }
    if(flag)
        printf("%lld\n",ans);
    else
        printf("-1\n");

    return 0;
}
