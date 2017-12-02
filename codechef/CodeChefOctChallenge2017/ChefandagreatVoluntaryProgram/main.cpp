/*
name : tangli
time : 2017/10/19
problem : codechef 2017 oct challenge Chef and a great voluntary Program
https://www.codechef.com/problems/CHEFGP
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

const int N = 1e5 + 5;
char s[N],ans[10*N];

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int x,y;

        scanf("%s%d%d",s,&x,&y);
        //cout <<s<<endl;

        int a = 0, b = 0;
        for(int i = 0; i < strlen(s); i++)
        {
            if(s[i] == 'a') a++;
            else if(s[i] == 'b') b++;
        }
        int sa,sb,left = 0,add = 0;
        if(a > b)
        {
            sa = a/x +((a%x)==0?0:1);
            sb = sa - 1;

            if(b >= sb)
                left = b - sb;
            else
                add = sb - b;

            for(int i = 0; i < a; i++)
            {
                if(i%x == 0 && i)
                {
                    if(add > 0)
                    {
                        putchar('*');
                        add--;
                    }
                    else
                        putchar('b');
                }
                else if(left > 0)
                {
                    putchar('b');
                    left--;
                }
                putchar('a');
            }
        }
        else
        {
            sb = b/y +((b%y)==0?0:1);
            sa = sb - 1;

            if(a >= sa)
                left = a - sa;
            else
                add = sa - a;

            for(int i = 0; i < b; i++)
            {
                if(i%y == 0 && i)
                {
                    if(add > 0)
                    {
                        putchar('*');
                        add--;
                    }
                    else
                        putchar('a');
                }
                else if(left > 0)
                {
                    putchar('a');
                    left--;
                }
                putchar('b');
            }
        }
        printf("\n");
    }
    return 0;
}
