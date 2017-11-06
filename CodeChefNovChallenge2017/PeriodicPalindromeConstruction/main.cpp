/*
name : tangli
time : 2017/11/06
problem : Periodic Palindrome Construction
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
typedef long long ll;
#define first fi
#define second se
#define all(x) x.begin(),x.end()
#define inf 0x7fffffff
const int N = 1000000 + 5;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n, p;
        scanf("%d%d",&n,&p);

        bool ok = 1;
        if(p == 1 || p == 2) printf("impossible\n");
        else
        {
            int cir = n/p;
            for(int i = 0; i < cir; i++)
            {
                putchar('a');
                for(int i = 1; i < p-1; i++)
                    putchar('b');
                putchar('a');
            }
            printf("\n");
        }
    }
    return 0;
}
