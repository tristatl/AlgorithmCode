/*
name : tangli
time : 2017/11/1
problem : cf884C
*/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define CLR(a,b) memset(a,0,sizeof(a))
typedef long long ll;
const ll mod = 1000000000+7;
const int N = 100000+5;
int nex[N];
int vis[N];
vector<ll>v;
int dfs(int s)
{
    int p = nex[s];
    vis[p] = 1;
    int ans = 1;
    while(p!=s)
    {
        ans++;
        p = nex[p];
        vis[p] = 1;
    }
    return ans;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++)
        scanf("%d",&nex[i]);
    int cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        if(!vis[i])
        {
            vis[i] = 1;
            cnt = dfs(i);
            v.pb(cnt);
            //cout<<i<<" "<<cnt<<endl;
        }
    }
    ll ans = 0, tmp = 0;
    sort(v.begin(),v.end());
    for(int i = 0; i < v.size(); i++)
    {
        if(i >= v.size()-2)
            tmp += v[i];
        else
            ans += v[i]*v[i];
    }
    ans += tmp*tmp;
    printf("%lld\n",ans);
    return 0;
}
