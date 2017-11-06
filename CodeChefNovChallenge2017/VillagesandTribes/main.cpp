/*
name : tangli
time : 2017/11/06
problem : Villages and Tribes
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
const int N = 100000 + 5;

char s[N];

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",s);

        int a = 0, b = 0, cnt = 0;
        char bef = 'X';
        for(int i = 0; i < strlen(s); i++)
        {
            if(s[i] == '.') cnt++;
            else if(s[i] == 'A')
            {
                a++;
                if(bef == 'A') a += cnt;
                bef = 'A';
                cnt = 0;
            }
            else
            {
                b++;
                if(bef == 'B') b += cnt;
                bef = 'B';
                cnt = 0;
            }
        }
        printf("%d %d\n",a,b);
    }
    return 0;
}
